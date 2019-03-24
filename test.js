var jvt = require('bindings')('jvt')
var [,,IP,username,password] = process.argv
console.log(jvt)
console.log(jvt.vInit())
var logID
console.log(logID = jvt.vLogin(IP,username,password))
console.log(jvt.vConfigCamera(logID,"E_SDK_CONFIG_ABILITY_CAMERA"))
console.log(jvt.vLogout(logID))
console.log(jvt.vCleanup())