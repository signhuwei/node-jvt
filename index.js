var jvt = require('bindings')('jvt')
console.log(jvt)
console.log(jvt.vInit())
var logID
console.log(logID = jvt.vLogin('192.168.3.188','admin','admin'))
console.log(jvt.vConfigCamera(logID))
console.log(jvt.vLogout(logID))
console.log(jvt.vCleanup())