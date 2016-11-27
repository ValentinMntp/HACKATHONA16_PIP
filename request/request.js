const Mongo = require("mongodb").MongoClient;
const MongoObjectID = require("mongodb").ObjectID; 
const _DB = "mongodb://172.25.31.238:6666/pip2016";
const moment = require('moment');
var _db;

var mongoRequest = {};


mongoRequest.connect = function(){
	Mongo.connect(_DB, function(error, db) {
	    if (error) return error;
	    _db = db;
	    console.log("Connecté à la base de données 'users'");
	});
}

mongoRequest.getUser = function(id, callback){
	//console.log(id);
	try{
		var objToFind = { _id:id};
		console.log(objToFind);
		_db.collection("users").findOne(objToFind, function(error, result) {
			console.log("on essaye de récupérer le user ayant l'id :" + id);
			if (error) {throw error;}
			callback(result);
			//console.log(result);
		});
	}
	catch(e){
		console.log(e);
	}
}

mongoRequest.addUser = function(obj){
	try{
		_db.collection("users").insert(obj, function(error, result) {
			if (error) {throw error;}
		});
	}
	catch(e){
		console.log(e);
	}
}

mongoRequest.updateUser = function(obj, id){
	try{
		var objToFind = { _id:id, };
		_db.collection("users").update(objToFind,{'EDT':obj.EDT}, function(error, result) {
			if (error) {throw error;}
		});
	}
	catch(e){
		console.log(e);
	}
}

mongoRequest.getRoom = function(id, callback){
	try{
		var objToFind = { _id:id};
		console.log("on cherche une room");
		_db.collection("users").findOne(objToFind, function(error, result) {
			if (error) {throw error;}
			var date = new Date(); 
			for(e of result.EDT){
				console.log(Math.abs(new Date(e.debut) - date));
				if(Math.abs(new Date(e.debut) - date) <= 1200000){
					callback({'heure':e.debut,'salle':e.salle, 'nom':e.nom});
				}
			}
			callback('Pas de cours à venir');
			//console.log(result);
		});
	}
	catch(e){
		console.log(e);
	}
}

mongoRequest.close = function(){
	Mongo.close();
}

module.exports = mongoRequest;