angular.module('App', ['ui.calendar'])
      .controller('AppController', function($scope, uiCalendarConfig) {

        var date = new Date();
        var d = date.getDate();
        var m = date.getMonth();
        var y = date.getFullYear();

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
             hiddenDays : [0],
             eventClick: function(event, jsEvent, view){
               $('#myModal').modal('toggle');
              },
           }
         };

         $scope.events = [];
         $scope.eventSources = [$scope.events];

         $scope.update = function(id, salle){
           var event = uiCalendarConfig.calendars.calendar.fullCalendar('clientEvents', id);

           event[0].title = event[0].title.substr(0, 4) + '\n' + salle ;

           uiCalendarConfig.calendars.calendar.fullCalendar('updateEvent', event[0]);
           $('#myModal').modal('hide');
           uiCalendarConfig.calendars.calendar.fullCalendar('refresh');
         }

        $scope.refresh = function(){
          var data = $.ajax("http://localhost:3000/7", { async:false }).responseJSON;
          $scope.name = data.name;
          var i = 0;
          var events = data.EDT.map(function(event){
            i++;
            if (event.nom == 'LO23')
              var col = '#cc0303'
            else if (event.nom =='MT09')
              var col = '#64b557'
            else if (event.nom =='GE37')
              var col = '#447889'
            return {
              id: i,
              title : event.nom + ' \n '+ event.salle,
              start : event.debut,
              end : event.fin,
              color: col
            };

          });


          uiCalendarConfig.calendars.calendar.fullCalendar('removeEvents');
          uiCalendarConfig.calendars.calendar.fullCalendar('addEventSource', events);
        }
      });
