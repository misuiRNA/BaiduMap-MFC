#pragma once
#include "explorer1.h"
#include "box_lng.h"
#include "afxwin.h"


class CBAIDUMapDlg : public CDialogEx, public IDispatch
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
	CExplorer1 Browser;
	afx_msg void OnBnClickedButton1();
	CEdit lngBox;
	CEdit latBox;
	CEdit pointBox;
	afx_msg void OnBnClickedButton2();
	void ShowPointString(const wchar_t *msg);
	CEdit pointsEdit;

	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();

	virtual HRESULT STDMETHODCALLTYPE GetTypeInfoCount(UINT *pctinfo);
	virtual HRESULT STDMETHODCALLTYPE GetTypeInfo(UINT iTInfo, LCID lcid, ITypeInfo **ppTInfo);
	virtual HRESULT STDMETHODCALLTYPE GetIDsOfNames(REFIID riid, LPOLESTR *rgszNames, UINT cNames, LCID lcid, DISPID *rgDispId);
	virtual HRESULT STDMETHODCALLTYPE Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS *pDispParams, VARIANT *pVarResult, EXCEPINFO *pExcepInfo, UINT *puArgErr);
	virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppvObject);
	virtual ULONG STDMETHODCALLTYPE AddRef();
	virtual ULONG STDMETHODCALLTYPE Release();
	DECLARE_EVENTSINK_MAP()
	void DocumentCompleteExplorer1(LPDISPATCH pDisp, VARIANT* URL);
};

enum
{
    FUNCTION_ShowMessageBox = 1,
    FUNCTION_GetProcessID = 2,
};
