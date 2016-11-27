var express = require('express');
var router = express.Router();

/* GET home page. */
router.get('/', function(req,res,next){
  res.render('index');
});
router.get('/:id', function(req, res, next) {
    var date = new Date();
    var d = date.getDate();
    var m = date.getMonth();
    var y = date.getFullYear();
    res.send({
    "name": "JoColina",
    "EDT": [{
            "debut": new Date('2016-11-28T08:00:00'),
            "fin": new Date(' 2016-11-28T10:00:00'),
            "nom": "LO23",
            "salle": "FB102"
        },  {
            "debut": new Date('2016-11-28T14:15:00'),
            "fin": new Date('2016-11-28T16:15:00'),
            "nom": "GE37",
            "salle": "RO205"
        }, {
            "debut": new Date('2016-11-28T16:30:00'),
            "fin": new Date('2016-11-28T18:30:00'),
            "nom": "LO23",
            "salle": "FA500"
        }, {
            "debut": new Date('2016-11-29T10:15:00'),
            "fin": new Date('2016-11-28T12:15:00'),
            "nom": "MT09",
            "salle": "FA210"
        }, {
            "debut": new Date('2016-11-29T16:30:00'),
            "fin": new Date('2016-11-28T18:30:00'),
            "nom": "LO23",
            "salle": "FA500"
        },
        {
            "debut": new Date('2016-11-30T08:00:00'),
            "fin": new Date('2016-11-30T10:00:00'),
            "nom": "LO23",
            "salle": "FB102"
        },  {
            "debut": new Date('2016-11-30T16:30:00'),
            "fin": new Date('2016-11-30T18:30:00'),
            "nom": "LO23",
            "salle": "FA500"
        },
        {
            "debut": new Date('2016-12-01T08:00:00'),
            "fin": new Date('2016-12-01T10:00:00'),
            "nom": "LO23",
            "salle": "FB102"
        }, {
            "debut": new Date('2016-12-01T14:15:00'),
            "fin": new Date('2016-12-01T16:15:00'),
            "nom": "GE37",
            "salle": "RO205"
        },
        {
            "debut": new Date('2016-12-02T08:00:00'),
            "fin": new Date('2016-12-02T10:00:00'),
            "nom": "LO23",
            "salle": "FB102"
        }, {
            "debut": new Date('2016-12-02T10:15:00'),
            "fin": new Date('2016-12-02T12:15:00'),
            "nom": "MT09",
            "salle": "FA210"
        }, {
            "debut": new Date('2016-12-02T16:30:00'),
            "fin": new Date('2016-12-02T18:30:00'),
            "nom": "LO23",
            "salle": "FA500"
        }
    ]
});
});

module.exports = router;
