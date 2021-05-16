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
    ON_BN_CLICKED(IDC_BUTTON5, &CBAIDUMapDlg::OnBnClickedButton5)
    ON_BN_CLICKED(IDC_BUTTON6, &CBAIDUMapDlg::OnBnClickedButton6)
END_MESSAGE_MAP()


BOOL CBAIDUMapDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();
    jsAgent.init("../script/MapPage.html");

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

void CBAIDUMapDlg::ShowPointString(const wchar_t *msg) {
    int pSize = WideCharToMultiByte(CP_OEMCP, 0, msg, wcslen(msg), NULL, 0, NULL, NULL);
    char* pCStrKey = new char[pSize+1];
    WideCharToMultiByte(CP_OEMCP, 0, msg, wcslen(msg), pCStrKey, pSize, NULL, NULL);
    pCStrKey[pSize] = '\0';
    SetDlgItemText(IDC_EDIT3,pCStrKey);//IDC_EDIT1你的edit控件ID
    delete pCStrKey;
}

BEGIN_EVENTSINK_MAP(CBAIDUMapDlg, CDialogEx)
    ON_EVENT(CBAIDUMapDlg, IDC_EXPLORER1, 259, CBAIDUMapDlg::DocumentCompleteExplorer1, VTS_DISPATCH VTS_PVARIANT)
END_EVENTSINK_MAP()

void CBAIDUMapDlg::DocumentCompleteExplorer1(LPDISPATCH pDisp, VARIANT* URL)
{
	jsAgent.confJavascriptInvoker();
	jsAgent.regJSCallCppFunc(this);
}
