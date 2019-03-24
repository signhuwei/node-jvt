var jvt = require('bindings')('jvt')
console.log(jvt)
console.log(jvt.vInit())
var logID
console.log(logID = jvt.vLogin(process[2],process[3],process[4]))
console.log(jvt.vConfigCamera(logID))
console.log(jvt.vLogout(logID))
console.log(jvt.vCleanup())