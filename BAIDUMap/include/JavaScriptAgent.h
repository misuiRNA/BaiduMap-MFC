#pragma once

#include "explorer1.h"
#include "WebPage.h"
#include "resource.h"
#include "JSCallCppInvoker.h"
#include <map>

class JavaScriptAgent : public IDispatch {
	std::map<FunctionNameType, FunctionIdType> jsCallCppFuncIdMap;
	std::map<FunctionIdType, JSCallCppInvoker*> jsCallCppInvokerMap;
public:
    CExplorer1 browser;
    CWebPage web;

    JavaScriptAgent();
    void init(const char* pagePath);
	CExplorer1& getBrowser();

    void callJSFunc(const CString& jsFuncName, CComVariant& result, const CString& arg1 = *(CString*)nullptr, const CString& arg2 = *(CString*)nullptr);
    void callJSFunc(const CString& jsFuncName, const CString& arg1 = *(CString*)nullptr, const CString& arg2 = *(CString*)nullptr);

	void confJavascriptInvoker();
	void regJSCallCppFunc(JSCallCppInvoker* invoker);

    virtual HRESULT STDMETHODCALLTYPE GetIDsOfNames(REFIID riid, LPOLESTR *rgszNames, UINT cNames, LCID lcid, DISPID *rgDispId);
    virtual HRESULT STDMETHODCALLTYPE Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS *pDispParams, VARIANT *pVarResult, EXCEPINFO *pExcepInfo, UINT *puArgErr);
    virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppvObject);
    virtual HRESULT STDMETHODCALLTYPE GetTypeInfoCount(UINT *pctinfo);
    virtual HRESULT STDMETHODCALLTYPE GetTypeInfo(UINT iTInfo, LCID lcid, ITypeInfo **ppTInfo);
    virtual ULONG STDMETHODCALLTYPE AddRef();
    virtual ULONG STDMETHODCALLTYPE Release();
private:
    CString getPageAbsolutePath(const char* pagePath);
}; 
