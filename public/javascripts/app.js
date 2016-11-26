angular.module('App', [])
      .controller('AppController', function($scope) {
        $scope.name = "Inconnu";
        $scope.events = [];

        $scope.refresh = function(){
          var data = $.ajax("http://localhost:3000/7", { async:false }).responseJSON;
          $scope.name = data.name;
          $scope.events = data.events.map(function(event){
            return {
              title : event.title,
              start : moment(event.start).locale('fr').format('LLLL'),
              end : moment(event.end).locale('fr').format('LT')
            }
          });
        }
      });
