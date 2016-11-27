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
             displayEventTime:false,
             minTime :"08:00:00",
             maxTime :"21:00:00",
             allDaySlot : false,
             locale : 'fr',
             hiddenDays : [0],
             eventClick: function(event, jsEvent, view) {
                alert("Là on est sencé pouvoir modifier la salle en fait");
              },
           }
         };

         $scope.events = [];
         $scope.eventSources = [$scope.events];


        $scope.refresh = function(){
          var data = $.ajax("http://localhost:3000/7", { async:false }).responseJSON;
          $scope.name = data.name;

          var events = data.EDT.map(function(event){
            if (event.nom == 'LO23')
              var col = '#cc0303'
            else if (event.nom =='MT09')
              var col = '#64b557'
            else if (event.nom =='GE37')
              var col = '#447889'
            return {
              title : event.nom + ' \n '+ event.salle,
              start : event.debut,
              end : event.end,
              color: col
            }
          });

          uiCalendarConfig.calendars.calendar.fullCalendar('removeEvents');
          uiCalendarConfig.calendars.calendar.fullCalendar('addEventSource', events);
        }
      });
