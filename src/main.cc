#include <napi.h>

Napi::Number vInit(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  long ret = VideoNet_Init(NULL,1);
  return Napi::Number::New(env,ret);
}
Napi::Boolean vCleanup(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  bool ret = VideoNet_Cleanup();
  return Napi::Boolean::New(env,ret);
}

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

  VIDEONET_DEVICEINFO OutDev; 
	memset(&OutDev,0,sizeof(OutDev));
  int nError = 0;		
  int ret = VideoNet_Login((char*)uuidip.c_str(), 36123, (char*)username.c_str(),(char*)password.c_str(),(LPVIDEONET_DEVICEINFO)(&OutDev),&nError);
  return Napi::Number::New(env, ret);
}
Napi::Number vLogout(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  if (info.Length() < 1) {
    Napi::TypeError::New(env, "Wrong count of arguments").ThrowAsJavaScriptException();
    return Napi::Number::New(env,-1);
  }
  if (!info[0].IsNumber()) {
    Napi::TypeError::New(env, "Wrong arguments type").ThrowAsJavaScriptException();
    return Napi::Number::New(env,-1);
  }
  long loginID = info[0].As<Napi::Number>().Int32Value();
  long ret = VideoNet_Logout(loginID);
  return Napi::Number::New(env,ret);
}

Napi::Boolean vConfigCarme(const Napi::CallbackInfo& info){
  Napi::Env env = info.Env();
  if (info.Length() < 1) {
    Napi::TypeError::New(env, "Wrong count of arguments").ThrowAsJavaScriptException();
    return Napi::Boolean::New(env,false);
  }
  if (!info[0].IsNumber()) {
    Napi::TypeError::New(env, "Wrong arguments type").ThrowAsJavaScriptException();
    return Napi::Boolean::New(env,false);
  }
  long loginID = info[0].As<Napi::Number>().Int32Value();
  unsigned long dwRetLen = 0;
	int nWaitTime = 10000;
	SDK_CONFIG_NORMAL NormalConfig = {{0}};
	BOOL bSuccess = VideoNet_GetDevConfig(loginID, E_SDK_CONFIG_SYSNORMAL ,0, 
		(char *)&NormalConfig ,sizeof(SDK_CONFIG_NORMAL), &dwRetLen,nWaitTime);
	if ( bSuccess && dwRetLen == sizeof(SDK_CONFIG_NORMAL))
	{
    return Napi::Boolean::New(env,true);
	}
  
    return Napi::Boolean::New(env,false);
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
  exports.Set(Napi::String::New(env, "vConfigCarme"),
              Napi::Function::New(env, vConfigCarme));
  return exports;
}

NODE_API_MODULE(hello, Init)