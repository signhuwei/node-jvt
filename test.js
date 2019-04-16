var jvt = require('bindings')('jvt')
var [,,IP,username,password,query="E_SDK_CONFIG_SYSNORMAL",channel='0'] = process.argv
console.log(jvt)
console.log(jvt.vInit())
var logID
console.log(logID = jvt.vLogin(IP,username,password,36123))

let cfg  = jvt.vConfigCamera(logID,parseInt(channel),query);
function eql(a,b){
    if(typeof a != 'object'){
        return a == b
    }
    Object.keys(a).reduce((r,c)=>(r=r&&(a[c]==b[c])),true)
}
Object.keys(cfg).forEach(key=>{
    if(typeof cfg[key] == 'object') {
        var oVal = cfg[key]
        Object.keys(oVal).forEach(k=>{
            oVal[k] = [oVal[k]+3,oVal[k]+1,oVal[k]+2][~~(3*Math.random())]
        })
    }else{
        cfg[key] = [cfg[key]+3,cfg[key]+1,cfg[key]+2][~~(3*Math.random())]
    }
    console.log(`set ${query} ${key} as ${typeof cfg[key] == 'object'? JSON.stringify(cfg[key]):cfg[key]}`)
    jvt.vConfigCamera(logID,parseInt(channel),query,cfg)
    let after = jvt.vConfigCamera(logID,parseInt(channel),query)
    console.log(`after set ${query} ${key} ,take back ${typeof after[key] == 'object'? JSON.stringify(after[key]):after[key]} 
        ${eql(after[key]==cfg[key])&&'============='}`)
})
//console.log(jvt.vConfigCamera(logID,"E_SDK_CONFIG_SYSNORMAL"))
//console.log(jvt.vConfigCamera(logID,"E_SDK_CONFIG_CAMERA"))
//console.log(jvt.vConfigCamera(logID,"E_SDK_CONFIG_ABILITY_CAMERA"))
//console.log(jvt.vConfigCamera(logID,"E_SDK_CFG_PARAM_EX"))
//console.log(jvt.vConfigCamera(logID,"E_SDK_CFG_VIDEOCOLOR_CUSTOM",channel))

console.log(jvt.vLogout(logID))
console.log(jvt.vCleanup())