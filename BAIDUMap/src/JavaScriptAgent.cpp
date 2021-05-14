#include "stdafx.h"
#include "JavaScriptAgent.h"
#include "afxdialogex.h"
#include <stdarg.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

JavaScriptAgent::JavaScriptAgent()
{

}

void JavaScriptAgent::init()
{
	char chCurtPath[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, chCurtPath);
	CString htmlPageURL = "file://"+(CString)chCurtPath + "../script/test.html";
	browser.Navigate(htmlPageURL, NULL, NULL, NULL, NULL);
	web.SetDocument(browser.get_Document());
}

void JavaScriptAgent::callJSFunc(const CString& jsFuncName, CComVariant& varResult)
{
	web.CallJScript(jsFuncName, &varResult);
}

void JavaScriptAgent::callJSFunc(const CString& jsFuncName, const CString& arg)
{
	web.CallJScript(jsFuncName, arg);
}

void JavaScriptAgent::callJSFunc(const CString& jsFuncName, const CString& arg1, const CString& arg2)
{
	web.CallJScript(jsFuncName, arg1, arg2);
}

CExplorer1& JavaScriptAgent::getBrowser()
{
	return browser;
}
