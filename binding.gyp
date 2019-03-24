{
  "variables":{
    "libs_dir%":"<!(node config.js libs)"
  },
  "targets": [
    {
      "target_name": "jvt",
      "sources": [ "./src/main.cc" ],
      "include_dirs": [
       "<!@(node -p \"require('./config').includes_dir\")"
      ],
      "copies":[{
          'destination': '<(module_root_dir)/build/Release',
          'files': [
            "<!@(node -p \"require('./config').libs2copy\")"
          ]
        }
      ],
      "libraries":[
        "<!@(node -p \"require('./config').libraries\")"
      ],
      'defines': [
        'NAPI_DISABLE_CPP_EXCEPTIONS'
      ]
    }
  ]
}