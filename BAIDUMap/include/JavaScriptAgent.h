#pragma once

#include "explorer1.h"
#include "WebPage.h"

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"

class JavaScriptAgent {
public:
	CExplorer1 browser;
	CWebPage web;

    JavaScriptAgent();
	void init();

	void callJSFunc(const CString& jsFuncName, CComVariant& result, const CString& arg1 = *(CString*)nullptr, const CString& arg2 = *(CString*)nullptr);
	void callJSFunc(const CString& jsFuncName, const CString& arg1 = *(CString*)nullptr, const CString& arg2 = *(CString*)nullptr);
	CExplorer1& getBrowser();
private:
	CString getPagePath();
}; 
