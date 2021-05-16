#pragma once
#include "explorer1.h"
#include "box_lng.h"
#include "afxwin.h"
#include "WebPage.h"
#include "JavaScriptAgent.h"
#include "JSCallCppInvoker.h"


class CBAIDUMapDlg : public CDialogEx
{
public:
    enum { IDD = IDD_BAIDUMAP_DIALOG };

    CBAIDUMapDlg(CWnd* pParent = NULL);
protected:
    virtual void DoDataExchange(CDataExchange* pDX);
protected:
    HICON m_hIcon;

    virtual BOOL OnInitDialog();
    afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
    afx_msg void OnPaint();
    afx_msg HCURSOR OnQueryDragIcon();
    DECLARE_MESSAGE_MAP()
public:
    JavaScriptAgent jsAgent;

    CEdit lngBox;
    CEdit latBox;
    CEdit pointBox;
    CEdit pointsEdit;

    afx_msg void OnBnClickedButton1();
    afx_msg void OnBnClickedButton2();
    afx_msg void OnBnClickedButton3();
    afx_msg void OnBnClickedButton5();
    afx_msg void OnBnClickedButton6();
	void ShowPointString(const wchar_t *msg);

    DECLARE_EVENTSINK_MAP()
    void DocumentCompleteExplorer1(LPDISPATCH pDisp, VARIANT* URL);
};

enum
{
    FUNCTION_ShowMessageBox = 1,
    FUNCTION_GetProcessID = 2,
};
