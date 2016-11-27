const express = require('express');
const bodyParser = require('body-parser');
const mongoRequest = require("./request/request");
const PORT = 8080;


app = new express();
app.use(bodyParser.json());
app.use(function(req, res, next) {
  res.header("Access-Control-Allow-Origin", "*");
  res.header("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
  next();
});

mongoRequest.connect();

app.get('/user/:id', function(req,res,err){
	var id = req.params.id;
	var obj = mongoRequest.getUser(id, data => {console.log(data); res.json(data)});
});


app.post('/updateUser/:id', function(req, res, errr){
	console.log("on essaye de faire une update");
	var id = req.params.id;
	var json = req.body;
	mongoRequest.updateUser(id,json);
});

app.post('/user/', function(req, res, err){
	var json = req.body;
	console.log(json);
	mongoRequest.addUser(json);
});

app.post('/users/', function(req, res, err){
	var json = req.body;
	for(e of json){
		//console.log(e);
		mongoRequest.addUser(e);
	}
});

app.get('/room/:id', function(req, res, err){
	var id = req.params.id;
	var obj = mongoRequest.getRoom(id, data => {console.log(data); res.json(data)});
});

app.listen(PORT, function(){
	console.log("WAW ON EST CONNECTES A UN SUPER SERVEUR. WAW AS TU VU? WAW. RENVERSANT. SPECTACULAAAAAAIRE.");
});
