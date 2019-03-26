var addonAPI = require('node-addon-api')
var os = require('os')
var arch = os.arch()
var type = os.type() == 'Linux' ? 'linux' : 'win'
var libs = type == 'linux' ? ['libjvtsdk.so','libnpcmpimontsp.so'] : ['VideoNetAPI.dll','VideoAnalysisAPI.dll','NpcMpiMonTsp.dll']
var links = type == 'linux' ? ['libjvtsdk.so','libnpcmpimontsp.so'] : ['VideoNetAPI.lib','VideoAnalysisAPI.lib','NpcMpiMonTsp.lib']

module.exports = {
    libs2copy:libs.map(lib=>`"${__dirname}/libs/${type}/${arch}/${lib}"`).join(' '),
    includes_dir:[addonAPI.include,`"${__dirname}/includes/${type}/${arch}/API"`].join(' '),
    libraries:links.map(lib=>`"${__dirname}/libs/${type}/${arch}/${lib}"`).join(' ')
}