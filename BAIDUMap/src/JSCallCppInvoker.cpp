#include "stdafx.h"
#include "JSCallCppInvoker.h"

int JSCallCppInvoker::invokerNum = 0;

JSCallCppInvoker::JSCallCppInvoker(const wchar_t* funcName, CBAIDUMapDlg* obj, CppFunc funcInvoke) :
    funcId(invokerNum++), funcName(funcName), obj(obj), func(funcInvoke)
{
        
}

void JSCallCppInvoker::invoke(DISPPARAMS& params)
{
    (obj->*func)(params.rgvarg[0].bstrVal);
}
