//#include "../../../../bin/libnative_api.h"
#include <libnative_api.h>
#include <stdio.h>
#include <windows.h>

// DLL function signature
typedef libnative_KLong (*importFunction)(const char*, void*);
typedef libnative_ExportedSymbols* (*importFunction2)(void);
//extern libnative_KLong GetClassObject(const char* wsName, void* pInterface);

struct AddIn{
    const char* (*Test)(void);
};
typedef struct AddIn AddIn;

int main(){
    importFunction GetClassObject;
    importFunction2 Libnative;
	HINSTANCE hinstLib;

	// Load DLL file
	hinstLib = LoadLibrary(TEXT("libnative.dll"));
	if (hinstLib == NULL) {
		printf("ERROR: unable to load DLL\n");
		return 1;
	}

	// Get function pointer
	GetClassObject = (importFunction) GetProcAddress(hinstLib, "GetClassObject");
	if (GetClassObject == NULL) {
		printf("ERROR: unable to find DLL function\n");
		FreeLibrary(hinstLib);
		return 1;
	}

    // Get function pointer
	Libnative = (importFunction2) GetProcAddress(hinstLib, "libnative_symbols");
	if (Libnative == NULL) {
		printf("ERROR: unable to find DLL function\n");
		FreeLibrary(hinstLib);
		return 1;
	}

    puts("Call GetClassObject");
    libnative_ExportedSymbols* lib = Libnative();
    //libnative_ExportedSymbols.kotlin.root.AddInNative addin;
    //libnative_KNativePtr addin = lib -> kotlin.root.AddInNative; 
    AddIn addin;
    GetClassObject("my name", &addin);
    puts("EndCall GetClassObject");
    const char* ch = addin.Test();
    puts(ch);

    return 0;
}