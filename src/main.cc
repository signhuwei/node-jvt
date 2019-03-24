#include <napi.h>
#include "jvt.h"
#include "convert.h"
#ifdef __APPLE__//Not support but developing ineed
    using namespace SDK_JVTFACE;
#endif
#ifdef __linux__
    using namespace SDK_JVTFACE;
#endif

/*
* Wrap VideoNet_Init
*/
Napi::Number vInit(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  long ret = VideoNet_Init(0,1);
  return Napi::Number::New(env,ret);
}

/*
* Wrap VideoNet_Cleanup
*/
Napi::Boolean vCleanup(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  bool ret = VideoNet_Cleanup();
  return Napi::Boolean::New(env,ret);
}

/*
* Wrap VideoNet_Login
* input: <String> IP,
        <String> username,
        <String> password,
        [<Number> port]
* output: <Number> Login ID (error:0)
*/
Napi::Number vLogin(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  if (info.Length() < 3) {
    Napi::TypeError::New(env, "Wrong count of arguments").ThrowAsJavaScriptException();
    return Napi::Number::New(env,0);
  }
  if (!info[0].IsString() || !info[1].IsString()|| !info[2].IsString()) {
    Napi::TypeError::New(env, "Wrong arguments type").ThrowAsJavaScriptException();
    return Napi::Number::New(env,0);
  }
  std::string uuidip = info[0].As<Napi::String>();
  std::string username = info[1].As<Napi::String>();
  std::string password = info[2].As<Napi::String>();
  int port = 36123;
  if(info[3]){
    if(!info[3].IsNumber()) {
      Napi::TypeError::New(env, "Type of port should be Number").ThrowAsJavaScriptException();
      return Napi::Number::New(env,0);
    }
    port = info[3].As<Napi::Number>();
  }

  VIDEONET_DEVICEINFO OutDev = {{0}};
  int nError = 0;		
  int ret = VideoNet_Login((char*)uuidip.c_str(), port, (char*)username.c_str(),(char*)password.c_str(),(LPVIDEONET_DEVICEINFO)(&OutDev),&nError);
  return Napi::Number::New(env, ret);
}

/*
* Wrap VideoNet_Logout
* input: <Number> Login ID
* output: <Number> Login ID (error:0)
*/
Napi::Number vLogout(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  if (info.Length() < 1) {
    Napi::TypeError::New(env, "Wrong count of arguments").ThrowAsJavaScriptException();
    return Napi::Number::New(env,0);
  }
  if (!info[0].IsNumber()) {
    Napi::TypeError::New(env, "Wrong arguments type").ThrowAsJavaScriptException();
    return Napi::Number::New(env,0);
  }
  long loginID = info[0].As<Napi::Number>().Int32Value();
  long ret = VideoNet_Logout(loginID);
  return Napi::Number::New(env,ret);
}

/*
* Wrap VideoNet_GetDevConfig/VideoNet_SetDevConfig
* input: <Number>LonginID,
        <String>configType,
        [<Object> ConfigStruct]
* output: <Object> ConfigStruct (error:nulll)
*/
#define SDK_CONFIG_INIT(TYPE,SST) \
    SST config; \
    memset(&config,0,sizeof(SST));  \
    pConfigParams = (char*)&config; \
    nSizeOfConfig = sizeof(SST); \
    nCommand = TYPE; 
Napi::Value vConfigCamera(const Napi::CallbackInfo& info){
  Napi::Env env = info.Env();
  if (info.Length() < 1) {
    Napi::TypeError::New(env, "Wrong count of arguments").ThrowAsJavaScriptException();
    return env.Null();
  }
  //loginID
  if (!info[0].IsNumber()) {
    Napi::TypeError::New(env, "LoginID should be Number!").ThrowAsJavaScriptException();
    return env.Null();
  }
  long nLoginID = info[0].As<Napi::Number>().Int32Value();
  char * pConfigParams;
  unsigned long nSizeOfConfig = 0;
  std::string strConfigType = std::string("E_SDK_CONFIG_SYSNORMAL");
  unsigned long nCommand;

  //configType
  if(info[1]){
    if (!info[1].IsString()) {
      Napi::TypeError::New(env, "ConfigType should be String!").ThrowAsJavaScriptException();
      return env.Null();
    }
    strConfigType = info[1].As<Napi::String>();
  }
  //get device config
  if(strConfigType == "E_SDK_CONFIG_SYSNORMAL"){
    SDK_CONFIG_INIT(E_SDK_CONFIG_SYSNORMAL,SDK_CONFIG_NORMAL)
  }else if(strConfigType == "E_SDK_CONFIG_CAMERA"){
    SDK_CONFIG_INIT(E_SDK_CONFIG_CAMERA,SDK_CameraParam)
  }else{
    Napi::TypeError::New(env, "ConfigType not support!").ThrowAsJavaScriptException();
      return env.Null();
  }
  //set configParams
  // if(info[2]){
  //   if (!info[2].IsObject()) {
  //     Napi::TypeError::New(env, "ConfigParams should be Object!").ThrowAsJavaScriptException();
  //     return env.Null();
  //   }
  // }

  int nWaitTime = 10000;
  unsigned long dwRetLen = 0;
	long bSuccess = VideoNet_GetDevConfig(nLoginID, nCommand ,0,pConfigParams ,nSizeOfConfig, &dwRetLen,nWaitTime);
	
  if ( bSuccess && dwRetLen == nSizeOfConfig){
    if(strConfigType == "E_SDK_CONFIG_SYSNORMAL"){
      return convert(env,*(SDK_CONFIG_NORMAL*)pConfigParams);
    }else if(strConfigType == "E_SDK_CONFIG_CAMERA"){
      return convert(env,*(SDK_CameraParam*)pConfigParams);
    }
  }
  
  return env.Null();
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "vInit"),
              Napi::Function::New(env, vInit));
  exports.Set(Napi::String::New(env, "vCleanup"),
              Napi::Function::New(env, vCleanup));
  exports.Set(Napi::String::New(env, "vLogin"),
              Napi::Function::New(env, vLogin));
  exports.Set(Napi::String::New(env, "vLogout"),
              Napi::Function::New(env, vLogout));
  exports.Set(Napi::String::New(env, "vConfigCamera"),
              Napi::Function::New(env, vConfigCamera));
  return exports;
}

NODE_API_MODULE(hello, Init)