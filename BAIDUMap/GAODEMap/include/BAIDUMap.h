
// BAIDUMap.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CBAIDUMapApp:
// �йش����ʵ�֣������ BAIDUMap.cpp
//

class CBAIDUMapApp : public CWinApp
{
public:
	CBAIDUMapApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CBAIDUMapApp theApp;