#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"

class BaiduMapApp : public CWinApp
{
public:
	BaiduMapApp();
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern BaiduMapApp baiduMapHandler;