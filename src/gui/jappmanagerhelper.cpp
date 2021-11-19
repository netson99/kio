#include "jappmanagerhelper.h"
#include "kprocessrunner_p.h"
#include "kiogui_debug.h"
#include <dlfcn.h>
#include <mutex>

void createKProcessRunnerFactory()
{
    static std::once_flag flag;
    std::call_once(flag, [](){
        typedef KProcessRunnerFactory * (*CREATEFACTORY_TYPE)(void);
        void *handle  = dlopen("libjprocessrunner_client.so", RTLD_NOW);
        if (handle)
        {
            CREATEFACTORY_TYPE factoryCreater = (CREATEFACTORY_TYPE)dlsym(handle, "createAppManagerClientProcessRunnerFactory");
            if (factoryCreater)
            {
                KProcessRunnerFactory *factory = factoryCreater();
                if (factory)
                {
                    KProcessRunner::setProcessRunnerFactory(factory);
                }
                else
                {
                    dlclose(handle);
                }
            }
            else
            {
                dlclose(handle);
            }
        }
        else
        {
            qCDebug(KIO_GUI) << "Fail to load libjprocessrunner_client.so" << dlerror();
        }
    });
}