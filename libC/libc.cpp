#include "addin.h"

class AddIn : IAddIn {
public:
	const char* Test() {
		return "libC test ok";
	}

};

int GetClassObject(IAddIn** pInterface)
{
    if (!*pInterface)
    {
        *pInterface = (IAddIn*) new AddIn();
        //return (long)*pInterface;
    }

    return 0;
}