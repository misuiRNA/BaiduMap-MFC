#pragma once

#include "WebPage.h"

class CBAIDUMapDlg;
typedef void (CBAIDUMapDlg::*CppFunc)(const wchar_t *msg);

typedef const wchar_t* FunctionNameType;
typedef int FunctionIdType;

class JSCallCppInvoker
{
    static int invokerNum;
public:
    FunctionIdType funcId;
    FunctionNameType funcName;

    JSCallCppInvoker(FunctionNameType funcName, CBAIDUMapDlg* obj, CppFunc funcInvoke);
    virtual void invoke(DISPPARAMS& params);
private:
    CBAIDUMapDlg* obj;
    CppFunc func;
};
