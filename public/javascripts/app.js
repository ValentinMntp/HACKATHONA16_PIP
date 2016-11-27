angular.module('App', ['ui.calendar'])
      .controller('AppController', function($scope, uiCalendarConfig) {

        var date = new Date();
        var d = date.getDate();
        var m = date.getMonth();
        var y = date.getFullYear();
        var data;

        $scope.name = "Inconnu";

        $scope.uiConfig = {
           calendar:{
             height: 500,
             eventStartEditable: true,
             defaultView: 'agendaDay',
             header:{
               left: 'month agendaWeek agendaDay',
               center: 'title',
               right: 'today prev,next'
             },
             slotDuration: '00:15:00',
             slotLabelFormat:'H:mm',
             minTime :"08:00:00",
             maxTime :"21:00:00",
             allDaySlot : false,
             locale : 'fr',
             //hiddenDays : [0],
             eventClick: function(event, jsEvent, view){
               $scope.eventClicked = event;
               $('#myModal').modal('toggle');
              },
           }
         };

         $scope.events = [];
         $scope.eventSources = [$scope.events];

         $scope.update = function(salle){
           $scope.eventClicked._event.salle= salle;
           $.ajax({
              type: "POST",
              url: "http://172.25.31.238:8080/updateUser/C25V05D5",
              data: JSON.stringify(data),
              dataType: 'json',
              contentType : 'application/json'
            });

           $('#myModal').modal('hide');
           $scope.refresh();
         }

        $scope.refresh = function(){
          data = $.ajax("http://172.25.31.238:8080/user/C25V05D5", { async:false }).responseJSON;
          console.log(data);
          $scope.name = data.name;
          var events = data.EDT.map(function(event, i){
            if (event.nom == 'LO23')
              var col = '#cc0303'
            else if (event.nom =='MT09')
              var col = '#64b557'
            else if (event.nom =='GE37')
              var col = '#447889'
            return {
              id: i,
              title : event.nom + ' \n '+ event.salle,
              start : new Date (event.debut),
              end : new Date (event.fin),
              color: col,
              _event: event
            };

          });


          uiCalendarConfig.calendars.calendar.fullCalendar('removeEvents');
          uiCalendarConfig.calendars.calendar.fullCalendar('addEventSource', events);
        }
      });
