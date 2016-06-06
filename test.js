
var ctor = require('./build/Release/set-accessor-property').ctor;

var obj = new ctor();

console.log("obj.a (MethodA):", obj.a);
console.log("obj.b(2) (MethodB):", obj.b(2));
console.log("calling obj.a(1) -- will crash");
obj.a(1);
