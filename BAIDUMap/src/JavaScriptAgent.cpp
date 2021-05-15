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
	CString&& htmlPagePath = getPagePath();
	browser.Navigate(htmlPagePath, NULL, NULL, NULL, NULL);
	web.SetDocument(browser.get_Document());
}

CString JavaScriptAgent::getPagePath()
{
	char chCurtPath[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, chCurtPath);
	CString htmlPagePath = "file://"+(CString)chCurtPath + "../script/MapPage.html";
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
