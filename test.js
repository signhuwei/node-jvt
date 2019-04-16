var jvt = require('bindings')('jvt')
var [,,IP,username,password,query="E_SDK_CONFIG_SYSNORMAL",channel='0'] = process.argv
console.log(jvt)
console.log(jvt.vInit())
var logID
console.log(logID = jvt.vLogin(IP,username,password,36123))

var camCfg = jvt.vConfigCamera(logID,parseInt(channel),query);
console.log('get config:',camCfg)
//camCfg.whiteBalance = 1;
jvt.vConfigCamera(logID,parseInt(channel),query,camCfg);
var after = jvt.vConfigCamera(logID,parseInt(channel),query);
console.log('after setting:',after)
//console.log(jvt.vConfigCamera(logID,"E_SDK_CONFIG_SYSNORMAL"))
//console.log(jvt.vConfigCamera(logID,"E_SDK_CONFIG_CAMERA"))
//console.log(jvt.vConfigCamera(logID,"E_SDK_CONFIG_ABILITY_CAMERA"))
//console.log(jvt.vConfigCamera(logID,"E_SDK_CFG_PARAM_EX"))
//console.log(jvt.vConfigCamera(logID,"E_SDK_CFG_VIDEOCOLOR_CUSTOM",channel))

console.log(jvt.vLogout(logID))
console.log(jvt.vCleanup())