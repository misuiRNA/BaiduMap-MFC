#pragma once

#include "explorer1.h"
#include "WebPage.h"
#include "resource.h"


enum CppFuncId
{
    ShowMessageBox = 1,
    GetProcessID = 2,
};

class CBAIDUMapDlg;

class JavaScriptAgent : public IDispatch {
	CBAIDUMapDlg* cppInvoke;
public:
    CExplorer1 browser;
    CWebPage web;

    JavaScriptAgent();
    void init(const char* pagePath);

    void callJSFunc(const CString& jsFuncName, CComVariant& result, const CString& arg1 = *(CString*)nullptr, const CString& arg2 = *(CString*)nullptr);
    void callJSFunc(const CString& jsFuncName, const CString& arg1 = *(CString*)nullptr, const CString& arg2 = *(CString*)nullptr);
    CExplorer1& getBrowser();
	void confJavascriptInvoker();
		//TODO try to optimize
	void regJSCallCppFunc(CBAIDUMapDlg* invoke);

    virtual HRESULT STDMETHODCALLTYPE GetTypeInfoCount(UINT *pctinfo);
    virtual HRESULT STDMETHODCALLTYPE GetTypeInfo(UINT iTInfo, LCID lcid, ITypeInfo **ppTInfo);
    virtual HRESULT STDMETHODCALLTYPE GetIDsOfNames(REFIID riid, LPOLESTR *rgszNames, UINT cNames, LCID lcid, DISPID *rgDispId);
    virtual HRESULT STDMETHODCALLTYPE Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS *pDispParams, VARIANT *pVarResult, EXCEPINFO *pExcepInfo, UINT *puArgErr);
    virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppvObject);
    virtual ULONG STDMETHODCALLTYPE AddRef();
    virtual ULONG STDMETHODCALLTYPE Release();
private:
    CString getPageAbsolutePath(const char* pagePath);
    void callCppFunc(CppFuncId funcId, DISPPARAMS& params);
}; 
