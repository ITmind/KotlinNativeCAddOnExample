#include "../bin/addinKotlin_api.h"
#include "addin.h"
#include <stdio.h>
#include <windows.h>

// DLL function signature
typedef int (*_getClassObject)(void*);
int TestAddIn(const char* dllname);

int main(){
	
	int errC = TestAddIn("addinC.dll");
	int errKotlin = TestAddIn("addinKotlin.dll");	

    return errC | errKotlin;
}

int TestAddIn(const char* dllname){

	_getClassObject GetClassObject;
	HINSTANCE hinstLib;

	// Load DLL file
	hinstLib = LoadLibrary(TEXT(dllname));
	if (hinstLib == NULL) {
		printf("ERROR: unable to load DLL %s\n", dllname);
		return 1;
	}
	// Get function pointer
	GetClassObject = (_getClassObject)GetProcAddress(hinstLib, "GetClassObject");
	if (GetClassObject == NULL) {
		printf("ERROR: unable to find DLL function GetClassObject\n");
		FreeLibrary(hinstLib);
		return 1;
	}

	IAddIn* addin = 0;

	GetClassObject(&addin);
	const char* testStr = addin->Test();
	puts(testStr);

	return 0;
}