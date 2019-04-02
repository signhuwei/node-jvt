var addonAPI = require('node-addon-api')
var os = require('os')
var osMap = {
    "Linux":{
        type:"linux",
        libs:['libjvtsdk.so','libnpcmpimontsp.so'],
        links:['libjvtsdk.so','libnpcmpimontsp.so']
    },
    "Windows_NT":{
        type: "win",
        libs: ['VideoNetAPI.dll','NpcMpiMonTsp.dll','VideoAnalysisAPI.dll'],
        links: ['VideoNetAPI.lib','NpcMpiMonTsp.lib','VideoAnalysisAPI.lib']
    },
    "Darwin": {
        type:"linux", //OSX fake to linux
        libs: ['libjvtsdk.so','libnpcmpimontsp.so'],
        links: ['libjvtsdk.so','libnpcmpimontsp.so']
    }
}

var arch = os.arch()
var {type,libs,links} = osMap[os.type()];
module.exports = {
    libs2copy:libs.map(lib=>`"${__dirname}/libs/${type}/${arch}/${lib}"`).join(' '),
    includes_dir:[addonAPI.include,`"${__dirname}/includes/${type}/${arch}/API"`].join(' '),
    libraries:links.map(lib=>`"${__dirname}/libs/${type}/${arch}/${lib}"`).join(' ')
}