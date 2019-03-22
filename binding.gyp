{
  "targets": [
    {
      "target_name": "jvt",
      "sources": [ "./src/main.cc" ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")"
      ],
      'link_settings': {
        'libraries': [
          '-lVideoNetAPI.lib',
        ],
        'library_dirs': [
          './libs',
        ]
      },
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
    },{
      "target_name":"copy_libs",
      "type":"none",
      "dependencies":["jvt"],
      "copies":[
        {
            'destination': '<(module_root_dir)/build/Release',
            'files': ['<(module_root_dir)/libs/VideoNetAPI.dll',
            '<(module_root_dir)/libs/VideoAnalysisAPI.dll',
            '<(module_root_dir)/libs/NpcMpiMonTsp.dll']
        }
      ]
    }
  ]
}