#include "stdafx.h"
#include "JavaScriptAgent.h"
#include "afxdialogex.h"
#include <stdarg.h>
#include "BaiduMapDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

JavaScriptAgent::JavaScriptAgent()
{

}

void JavaScriptAgent::init(const char* pagePath)
{
    CString&& htmlPagePath = getPageAbsolutePath(pagePath);
    browser.Navigate(htmlPagePath, NULL, NULL, NULL, NULL);
    web.SetDocument(browser.get_Document());
}

CString JavaScriptAgent::getPageAbsolutePath(const char* pagePath)
{
    char chCurtPath[MAX_PATH];
    // TODO try to optimize
    GetCurrentDirectory(MAX_PATH, chCurtPath);
    CString htmlPagePath = "file://"+(CString)chCurtPath + pagePath;
    return htmlPagePath;
}

// TODO try to optimize
void JavaScriptAgent::callJSFunc(const CString& jsFuncName, CComVariant& result, const CString& arg1, const CString& arg2)
{
    if (nullptr == &arg1)
    {
        web.CallJScript(jsFuncName, &result);
    }
    else if (nullptr == &arg2)
    {
        web.CallJScript(jsFuncName, arg1, &result);
    }
    else
    {
        web.CallJScript(jsFuncName, arg1, arg2);
    }
}

void JavaScriptAgent::callJSFunc(const CString& jsFuncName, const CString& arg1, const CString& arg2)
{
    CComVariant varResult;
    callJSFunc(jsFuncName, varResult, arg1, arg2);
}

CExplorer1& JavaScriptAgent::getBrowser()
{
    return browser;
}


HRESULT STDMETHODCALLTYPE JavaScriptAgent::GetTypeInfoCount(UINT *pctinfo)
{
    return E_NOTIMPL;
}
HRESULT STDMETHODCALLTYPE JavaScriptAgent::GetTypeInfo(UINT iTInfo, LCID lcid, ITypeInfo **ppTInfo)
{
    return E_NOTIMPL;
}
//JavaScript调用这个对象的方法时，会把方法名，放到rgszNames中，我们须要给这种方法名拟定一个唯一的数字ID。用rgDispId传回给它
//同理JavaScript存取这个对象的属性时。会把属性名放到rgszNames中，我们须要给这个属性名拟定一个唯一的数字ID，用rgDispId传回给它
//紧接着JavaScript会调用Invoke。并把这个ID作为參数传递进来
HRESULT STDMETHODCALLTYPE JavaScriptAgent::GetIDsOfNames(REFIID riid, LPOLESTR *rgszNames, UINT cNameNum, LCID lcid, DISPID *rgDispId)
{
    if (cNameNum != 1)
        return E_NOTIMPL;
    if (wcscmp(rgszNames[0], L"ShowPointString") == 0)
    {
        *rgDispId = ShowMessageBox;
        return S_OK;
    }
    else
        return E_NOTIMPL;
}
// register cpp-function called by JavaScritp
HRESULT STDMETHODCALLTYPE JavaScriptAgent::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS *pDispParams, VARIANT *pVarResult, EXCEPINFO *pExcepInfo, UINT *puArgErr)
{
    if (dispIdMember == ShowMessageBox)
    {
        if (pDispParams->cArgs != 1)
            return E_NOTIMPL;
        if (pDispParams->rgvarg[0].vt != VT_BSTR)
            return E_NOTIMPL;
		//ShowPointString(pDispParams->rgvarg[0].bstrVal);
		pDispParams->rgvarg[0].bstrVal;
        callCppFunc((CppFuncId)dispIdMember,*pDispParams);
        return S_OK;
    }
    else
        return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE JavaScriptAgent::QueryInterface(REFIID riid, void **ppvObject)
{
    if (riid == IID_IDispatch || riid == IID_IUnknown)
    {
        *ppvObject = static_cast<IDispatch*>(this);
        return S_OK;
    }
    else
        return E_NOINTERFACE;
}

ULONG STDMETHODCALLTYPE JavaScriptAgent::AddRef()
{
    return 1;
}

ULONG STDMETHODCALLTYPE JavaScriptAgent::Release()
{
    return 1;
}


void JavaScriptAgent::callCppFunc(CppFuncId funcId, DISPPARAMS& params)
{
	cppInvoke->ShowPointString(params.rgvarg[0].bstrVal);
}

void JavaScriptAgent::confJavascriptInvoker()
{
    CComQIPtr<IHTMLDocument2> document = browser.get_Document();
    CComDispatchDriver script;
    document->get_Script(&script);
    CComVariant var(static_cast<IDispatch*>(this));
    script.Invoke1(L"SaveCppObject", &var);
}

void JavaScriptAgent::regJSCallCppFunc(CBAIDUMapDlg* invoke)
{
	cppInvoke = invoke;
}
