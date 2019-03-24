 #ifndef _Password_Manager_H
#define _Password_Manager_H


#ifdef  PWM_EXPORTS
	#define PWM_API __declspec(dllexport)
#else
	#define PWM_API
//#define PWM_API extern "C"
#endif
/*
	Ω‚√‹
*/
PWM_API bool WINAPI DecryptStringEX(const char *sSrc,char *sDst, bool bAccOrPas);
/*
	//º”√‹
*/
PWM_API bool WINAPI EncryptStringEX(const char *sSrc,char *sDst, bool bAccOrPas);

#endif