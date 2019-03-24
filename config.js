if (process.argv.length == 3) {
    var query = process.argv[2];
    if (query === "libs") {
        console.log(__dirname+'/libs');
    }else if (query === "includes") {
        console.log(__dirname+'/includes');
    }else if (query === "libs_copy") {
        var os = require('os')
        var arch = os.arch()
        var type = os.type() == 'Linux' ? 'linux' : 'win'
        var libs = type == 'linux' ? ['libjvtsdk.so','libnpcmpimontsp.so'] : ['VideoNetAPI.dll','NpcMpiMonTsp.dll']
        libs.forEach(lib=>{
            console.log(`${__dirname}/libs/${type}/${arch}/${lib}`)
        })
    }
}
var addonAPI = require('node-addon-api')
var os = require('os')
var arch = os.arch()
var type = os.type() == 'Linux' ? 'linux' : 'win'
var libs = type == 'linux' ? ['libjvtsdk.so','libnpcmpimontsp.so'] : ['VideoNetAPI.dll','NpcMpiMonTsp.dll']
var links = type == 'linux' ? ['libjvtsdk.so','libnpcmpimontsp.so'] : ['VideoNetAPI.lib','NpcMpiMonTsp.lib']

module.exports = {
    libs2copy:libs.map(lib=>`"${__dirname}/libs/${type}/${arch}/${lib}"`).join(' '),
    includes_dir:[addonAPI.include,`"${__dirname}/includes/${type}/${arch}/API"`].join(' '),
    libraries:links.map(lib=>`"${__dirname}/libs/${type}/${arch}/${lib}"`).join(' ')
}