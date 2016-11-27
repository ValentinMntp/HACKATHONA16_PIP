angular.module('App', ['ui.calendar'])
      .controller('AppController', function($scope, uiCalendarConfig) {

        var date = new Date();
        var d = date.getDate();
        var m = date.getMonth();
        var y = date.getFullYear();

        $scope.name = "Inconnu";

        $scope.uiConfig = {
           calendar:{
             height: 450,
             editable: true,
             defaultView: 'agendaDay',
             header:{
               left: 'month agendaWeek agendaDay',
               center: 'title',
               right: 'today prev,next'
             },
             minTime :"08:00:00",
             maxTime :"21:00:00",
             allDaySlot : false,
             locale : 'fr',

            // hiddenDays : [0],
           }
         };

         $scope.events = [];
         $scope.eventSources = [$scope.events];

        $scope.refresh = function(){
          var data = $.ajax("http://localhost:3000/7", { async:false }).responseJSON;
          $scope.name = data.name;
          console.log(data.EDT);
          var events = data.EDT.map(function(event){
            return {
              title : event.nom + ' \n '+ event.salle,
              start : event.debut,
              end : event.end,
            }
          });

          uiCalendarConfig.calendars.calendar.fullCalendar('removeEvents');
          uiCalendarConfig.calendars.calendar.fullCalendar('addEventSource', events);
        }
      });
