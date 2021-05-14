#include "stdafx.h"
#include "BaiduMapApp.h"
#include "BaiduMapDlg.h"
#include "afxdialogex.h"
#include "CAboutDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CBAIDUMapDlg::CBAIDUMapDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBAIDUMapDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBAIDUMapDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	CExplorer1& browser = jsAgent.getBrowser();
	DDX_Control(pDX, IDC_EXPLORER1, browser);
	DDX_Control(pDX, IDC_EDIT1, lngBox);
	DDX_Control(pDX, IDC_EDIT2, latBox);
	DDX_Control(pDX, IDC_EDIT3, pointBox);
	DDX_Control(pDX, IDC_EDIT4, pointsEdit);
}

BEGIN_MESSAGE_MAP(CBAIDUMapDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CBAIDUMapDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CBAIDUMapDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CBAIDUMapDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CBAIDUMapDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CBAIDUMapDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CBAIDUMapDlg::OnBnClickedButton6)
END_MESSAGE_MAP()


BOOL CBAIDUMapDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	jsAgent.init();

	SetDlgItemText(IDC_EDIT1,"108.95357");
	SetDlgItemText(IDC_EDIT2,"34.26732");

	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);
	return TRUE;
}

void CBAIDUMapDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

void CBAIDUMapDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

HCURSOR CBAIDUMapDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// JavaScript call cpp  start
void CBAIDUMapDlg::ShowPointString(const wchar_t *msg) {
	int pSize = WideCharToMultiByte(CP_OEMCP, 0, msg, wcslen(msg), NULL, 0, NULL, NULL);
    char* pCStrKey = new char[pSize+1];
    WideCharToMultiByte(CP_OEMCP, 0, msg, wcslen(msg), pCStrKey, pSize, NULL, NULL);
    pCStrKey[pSize] = '\0';
	SetDlgItemText(IDC_EDIT3,pCStrKey);//IDC_EDIT1你的edit控件ID
	delete pCStrKey;
}

HRESULT STDMETHODCALLTYPE CBAIDUMapDlg::GetTypeInfoCount(UINT *pctinfo)
{
    return E_NOTIMPL;
}
HRESULT STDMETHODCALLTYPE CBAIDUMapDlg::GetTypeInfo(UINT iTInfo, LCID lcid, ITypeInfo **ppTInfo)
{
    return E_NOTIMPL;
}
//JavaScript调用这个对象的方法时，会把方法名，放到rgszNames中，我们须要给这种方法名拟定一个唯一的数字ID。用rgDispId传回给它
//同理JavaScript存取这个对象的属性时。会把属性名放到rgszNames中，我们须要给这个属性名拟定一个唯一的数字ID，用rgDispId传回给它
//紧接着JavaScript会调用Invoke。并把这个ID作为參数传递进来
HRESULT STDMETHODCALLTYPE CBAIDUMapDlg::GetIDsOfNames(REFIID riid, LPOLESTR *rgszNames, UINT cNameNum, LCID lcid, DISPID *rgDispId)
{
    //rgszNames是个字符串数组。cNames指明这个数组中有几个字符串。假设不是1个字符串。忽略它
    if (cNameNum != 1)
        return E_NOTIMPL;
    //假设字符串是ShowMessageBox。说明JavaScript在调用我这个对象的ShowMessageBox方法。我就把我拟定的ID通过rgDispId告诉它
    if (wcscmp(rgszNames[0], L"ShowPointString") == 0)
    {
        *rgDispId = FUNCTION_ShowMessageBox;
        return S_OK;
    }
    else
        return E_NOTIMPL;
}
// register cpp-function called by JavaScritp
HRESULT STDMETHODCALLTYPE CBAIDUMapDlg::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS *pDispParams, VARIANT *pVarResult, EXCEPINFO *pExcepInfo, UINT *puArgErr)
{
    if (dispIdMember == FUNCTION_ShowMessageBox)
    {
        if (pDispParams->cArgs != 1)
            return E_NOTIMPL;
        if (pDispParams->rgvarg[0].vt != VT_BSTR)
            return E_NOTIMPL;
        ShowPointString(pDispParams->rgvarg[0].bstrVal);
        return S_OK;
    }
    else
        return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE CBAIDUMapDlg::QueryInterface(REFIID riid, void **ppvObject)
{
    if (riid == IID_IDispatch || riid == IID_IUnknown)
    {
        *ppvObject = static_cast<IDispatch*>(this);
        return S_OK;
    }
    else
        return E_NOINTERFACE;
}

ULONG STDMETHODCALLTYPE CBAIDUMapDlg::AddRef()
{
    return 1;
}

ULONG STDMETHODCALLTYPE CBAIDUMapDlg::Release()
{
    return 1;
}
// JavaScript call cpp  end


void CBAIDUMapDlg::OnBnClickedButton1()
{
	CString lng;
	CString lat;
	lngBox.GetWindowText(lng);
	latBox.GetWindowText(lat);
	jsAgent.callJSFunc("showMap", lng, lat);
}

void CBAIDUMapDlg::OnBnClickedButton2()
{
	CComVariant varResult;
	jsAgent.callJSFunc("getCenterPoint", varResult);
	CString str;
	str=varResult.bstrVal;
	SetDlgItemText(IDC_EDIT3, str);
}

void CBAIDUMapDlg::OnBnClickedButton3()
{
	CString points;
	pointsEdit.GetWindowText(points);
	jsAgent.callJSFunc("pinpoints", points);
}

void CBAIDUMapDlg::OnBnClickedButton4()
{
	CExplorer1& browser = jsAgent.getBrowser();
	CComQIPtr<IHTMLDocument2> document = browser.get_Document();
    CComDispatchDriver script;
    document->get_Script(&script);
    CComVariant var(static_cast<IDispatch*>(this));
    script.Invoke1(L"SaveCppObject", &var);
}

void CBAIDUMapDlg::OnBnClickedButton5()
{
	CString points;
	pointsEdit.GetWindowText(points);
	jsAgent.callJSFunc("pinPolyline", points);
}


void CBAIDUMapDlg::OnBnClickedButton6()
{
	CString points;
	pointsEdit.GetWindowText(points);
	jsAgent.callJSFunc("pinPolygon", points);
}

BEGIN_EVENTSINK_MAP(CBAIDUMapDlg, CDialogEx)
	ON_EVENT(CBAIDUMapDlg, IDC_EXPLORER1, 259, CBAIDUMapDlg::DocumentCompleteExplorer1, VTS_DISPATCH VTS_PVARIANT)
END_EVENTSINK_MAP()

// send cpp object to JavaScript after the page uploaded
void CBAIDUMapDlg::DocumentCompleteExplorer1(LPDISPATCH pDisp, VARIANT* URL)
{
	CExplorer1& browser = jsAgent.getBrowser();
	CComQIPtr<IHTMLDocument2> document = browser.get_Document();
    CComDispatchDriver script;
    document->get_Script(&script);
    CComVariant var(static_cast<IDispatch*>(this));
    script.Invoke1(L"SaveCppObject", &var);
}
