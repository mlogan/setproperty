{
  "targets": [
    {
      "target_name": "set-accessor-property",
      "sources": [
        "src/set-accessor-property.cc",
      ],
      "cflags_cc": [ "-std=c++11" ],
      'conditions': [
        [ 'OS=="mac"', {

          'xcode_settings': {
            'OTHER_CPLUSPLUSFLAGS' : ['-std=c++11', '-stdlib=libc++'],
            'MACOSX_DEPLOYMENT_TARGET': '10.7'
          },
        }],
      ],
    }
  ]
}
