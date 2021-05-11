
// BAIDUMapDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "BAIDUMap.h"
#include "BAIDUMapDlg.h"
#include "afxdialogex.h"
#include "WebPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CBAIDUMapDlg 对话框



CBAIDUMapDlg::CBAIDUMapDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBAIDUMapDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBAIDUMapDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EXPLORER1, Browser);
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


// CBAIDUMapDlg 消息处理程序

BOOL CBAIDUMapDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	char chCurtPath[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, chCurtPath);
	CString htmlPageURL = "file://"+(CString)chCurtPath + "../script/test.html";
	Browser.Navigate(htmlPageURL, NULL, NULL, NULL, NULL);

	SetDlgItemText(IDC_EDIT1,"108.95357");//IDC_EDIT1你的edit控件ID
	SetDlgItemText(IDC_EDIT2,"34.26732");//IDC_EDIT1你的edit控件ID

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

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

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CBAIDUMapDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// JavaScript call cpp  start
enum
{
    FUNCTION_ShowMessageBox = 1,
    FUNCTION_GetProcessID = 2,
};

void CBAIDUMapDlg::ShowPointString(const wchar_t *msg) {
	int pSize = WideCharToMultiByte(CP_OEMCP, 0, msg, wcslen(msg), NULL, 0, NULL, NULL);
    char* pCStrKey = new char[pSize+1];
    WideCharToMultiByte(CP_OEMCP, 0, msg, wcslen(msg), pCStrKey, pSize, NULL, NULL);
    pCStrKey[pSize] = '\0';
	SetDlgItemText(IDC_EDIT3,pCStrKey);//IDC_EDIT1你的edit控件ID
	return;
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
HRESULT STDMETHODCALLTYPE CBAIDUMapDlg::GetIDsOfNames(REFIID riid, LPOLESTR *rgszNames, UINT cNames, LCID lcid, DISPID *rgDispId)
{
    //rgszNames是个字符串数组。cNames指明这个数组中有几个字符串。假设不是1个字符串。忽略它
    if (cNames != 1)
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
    //通过ID我就知道JavaScript想调用哪个方法
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
	CWebPage web;
	web.SetDocument(Browser.get_Document());
	const CString funcName("showMap");
	CComVariant varResult;
	web.CallJScript(funcName, lng, lat, &varResult);
}


void CBAIDUMapDlg::OnBnClickedButton2()
{
	CWebPage web;
	web.SetDocument(Browser.get_Document());
	const CString funcName("getCenterPoint");
	CComVariant varResult;
	web.CallJScript(funcName, &varResult);
	CString str;
	str=varResult.bstrVal;
	SetDlgItemText(IDC_EDIT3, str);
}


void CBAIDUMapDlg::OnBnClickedButton3()
{
	CString points;
	pointsEdit.GetWindowText(points);
	CWebPage web;
	web.SetDocument(Browser.get_Document());
	const CString funcName("pinpoints");
	CComVariant varResult;
	web.CallJScript(funcName, points, &varResult);
}


void CBAIDUMapDlg::OnBnClickedButton4()
{
	CComQIPtr<IHTMLDocument2> document = Browser.get_Document();
    CComDispatchDriver script;
    document->get_Script(&script);
    CComVariant var(static_cast<IDispatch*>(this));
    script.Invoke1(L"SaveCppObject", &var);
}

void CBAIDUMapDlg::OnBnClickedButton5()
{
	CString points;
	pointsEdit.GetWindowText(points);
	CWebPage web;
	web.SetDocument(Browser.get_Document());
	const CString funcName("pinPolyline");
	CComVariant varResult;
	web.CallJScript(funcName, points, &varResult);
}


void CBAIDUMapDlg::OnBnClickedButton6()
{
	CString points;
	pointsEdit.GetWindowText(points);
	CWebPage web;
	web.SetDocument(Browser.get_Document());
	const CString funcName("pinPolygon");
	CComVariant varResult;
	web.CallJScript(funcName, points, &varResult);
}

BEGIN_EVENTSINK_MAP(CBAIDUMapDlg, CDialogEx)
	ON_EVENT(CBAIDUMapDlg, IDC_EXPLORER1, 259, CBAIDUMapDlg::DocumentCompleteExplorer1, VTS_DISPATCH VTS_PVARIANT)
END_EVENTSINK_MAP()

// send cpp object to JavaScript after the page uploaded
void CBAIDUMapDlg::DocumentCompleteExplorer1(LPDISPATCH pDisp, VARIANT* URL)
{
	CComQIPtr<IHTMLDocument2> document = Browser.get_Document();
    CComDispatchDriver script;
    document->get_Script(&script);
    CComVariant var(static_cast<IDispatch*>(this));
    script.Invoke1(L"SaveCppObject", &var);
}
