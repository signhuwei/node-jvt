{
  "variables":{
    "libs_dir%":"<!(node config.js libs)",
    "includes_dir%":"./includes"
  },
  "targets": [
    {
      "target_name": "jvt",
      "sources": [ "./src/main.cc" ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")",
        "<(includes_dir)/<(OS)/<(target_arch)/API/"
      ],
      "conditions":[
        # node-gyp clean configure build --verbose
        ['OS=="linux"' and 'target_arch=="x64"', {
            'defines': [
              '__linux__','__x86_64__','NAPI_DISABLE_CPP_EXCEPTIONS'
            ],
            "libraries": [
              "<(libs_dir)/<(OS)/<(target_arch)/libjvtsdk.so"
            ],
            "copies":[{
                'destination': '<(module_root_dir)/build/Release',
                'files': [
                  '<(module_root_dir)/libs/<(OS)/<(target_arch)/libjvtsdk.so',
                  '<(module_root_dir)/libs/<(OS)/<(target_arch)/libnpcmpimontsp_x64.so'
                ]
              }
            ]
          }
        ],['OS=="linux"' and 'target_arch=="ia32"', {
            'defines': [
              '__linux__','NAPI_DISABLE_CPP_EXCEPTIONS'
            ],
            "libraries": [
              "-l<(libs_dir)/<(OS)/<(target_arch)/libjvtsdk.so"
            ],
            "copies":[{
                'destination': '<(module_root_dir)/build/Release',
                'files': [
                  '<(module_root_dir)/libs/<(OS)/<(target_arch)/libjvtsdk.so',
                  '<(module_root_dir)/libs/<(OS)/<(target_arch)/libnpcmpimontsp.so'
                ]
              }
            ]
          }
        ],['OS=="win1"' and 'target_arch=="x641"', {
            'defines': [
              'windows_dbr','_WIN32','_WIN64','NAPI_DISABLE_CPP_EXCEPTIONS'
            ],
            "libraries": [
              "-l<(libs_dir)/<(OS)/<(target_arch)/VideoNetAPI.lib",
              "-l<(libs_dir)/<(OS)/<(target_arch)/NpcMpiMonTsp.lib"
            ],
            "copies":[{
                'destination': '<(module_root_dir)/build/Release',
                'files': [
                  '<(module_root_dir)/libs/<(OS)/<(target_arch)/API/VideoNetAPI.dll',
                  #'<(module_root_dir)/libs/VideoAnalysisAPI.dll',
                  '<(module_root_dir)/libs/<(OS)/<(target_arch)/API/NpcMpiMonTsp.dll',
                ]
              }
            ]
          }
        ],['OS=="win"' and 'target_arch=="ia32"', {
            'defines': [
              'windows_dbr','_WIN32','NAPI_DISABLE_CPP_EXCEPTIONS'
            ],
            "libraries": [
              "-l<(libs_dir)/<(OS)/<(target_arch)/VideoNetAPI.lib",
              "-l<(libs_dir)/<(OS)/<(target_arch)/NpcMpiMonTsp.lib"
            ],
            "copies":[{
                'destination': '<(module_root_dir)/build/Release',
                'files': [
                  '<(module_root_dir)/libs/<(OS)/<(target_arch)/API/VideoNetAPI.dll',
                  #'<(module_root_dir)/libs/VideoAnalysisAPI.dll',
                  '<(module_root_dir)/libs/<(OS)/<(target_arch)/API/NpcMpiMonTsp.dll',
                ]
              }
            ]
          }
        ]
      ]
    }
  ]
}