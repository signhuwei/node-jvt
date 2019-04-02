var jvt = require('bindings')('jvt')
var [,,IP,username,password,query="E_SDK_CONFIG_SYSNORMAL",channel='0'] = process.argv
console.log(jvt)
console.log(jvt.vInit())
var logID
console.log(logID = jvt.vLogin(IP,username,password))

console.log(jvt.vConfigCamera(logID,parseInt(channel),query))
//console.log(jvt.vConfigCamera(logID,"E_SDK_CONFIG_SYSNORMAL"))
//console.log(jvt.vConfigCamera(logID,"E_SDK_CONFIG_CAMERA"))
//console.log(jvt.vConfigCamera(logID,"E_SDK_CONFIG_ABILITY_CAMERA"))
//console.log(jvt.vConfigCamera(logID,"E_SDK_CFG_PARAM_EX"))
//console.log(jvt.vConfigCamera(logID,"E_SDK_CFG_VIDEOCOLOR_CUSTOM",channel))

console.log(jvt.vLogout(logID))
console.log(jvt.vCleanup())