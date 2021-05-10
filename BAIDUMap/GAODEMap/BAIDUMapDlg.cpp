
// BAIDUMapDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "BAIDUMap.h"
#include "BAIDUMapDlg.h"
#include "afxdialogex.h"
#include "WebPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CBAIDUMapDlg �Ի���



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


// CBAIDUMapDlg ��Ϣ�������

BOOL CBAIDUMapDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CString strURL;//htm�ļ���ȫ·��
	char chCurtPath[MAX_PATH];//��ǰĿ¼
	GetCurrentDirectory(MAX_PATH, chCurtPath);//��ȡ��ǰĿ¼��������chCurtPath��
	strURL = "file://"+(CString)chCurtPath + "/test.html";//��chCurtDrct����ǿ��ת����CString,��ƴ�ӳ�ȫ·��
	Browser.Navigate(strURL, NULL, NULL, NULL, NULL);

	//���������Ĭ��ֵ
	SetDlgItemText(IDC_EDIT1,"108.95357");//IDC_EDIT1���edit�ؼ�ID
	SetDlgItemText(IDC_EDIT2,"34.26732");//IDC_EDIT1���edit�ؼ�ID

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CBAIDUMapDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CBAIDUMapDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//********************************************************JS����C++�����,��������ο�ʼ
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
	SetDlgItemText(IDC_EDIT3,pCStrKey);//IDC_EDIT1���edit�ؼ�ID
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
//JavaScript�����������ķ���ʱ����ѷ��������ŵ�rgszNames�У�������Ҫ�����ַ������ⶨһ��Ψһ������ID����rgDispId���ظ���
//ͬ��JavaScript��ȡ������������ʱ������������ŵ�rgszNames�У�������Ҫ������������ⶨһ��Ψһ������ID����rgDispId���ظ���
//������JavaScript�����Invoke���������ID��Ϊ�������ݽ���
HRESULT STDMETHODCALLTYPE CBAIDUMapDlg::GetIDsOfNames(REFIID riid, LPOLESTR *rgszNames, UINT cNames, LCID lcid, DISPID *rgDispId)
{
    //rgszNames�Ǹ��ַ������顣cNamesָ������������м����ַ��������費��1���ַ�����������
    if (cNames != 1)
        return E_NOTIMPL;
    //�����ַ�����ShowMessageBox��˵��JavaScript�ڵ�������������ShowMessageBox�������ҾͰ����ⶨ��IDͨ��rgDispId������
    if (wcscmp(rgszNames[0], L"ShowPointString") == 0)
    {
        *rgDispId = FUNCTION_ShowMessageBox;
        return S_OK;
    }
    else
        return E_NOTIMPL;
}
//**************ע��JS����C++�ĺ���
HRESULT STDMETHODCALLTYPE CBAIDUMapDlg::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS *pDispParams, VARIANT *pVarResult, EXCEPINFO *pExcepInfo, UINT *puArgErr)
{
    //ͨ��ID�Ҿ�֪��JavaScript������ĸ�����
    if (dispIdMember == FUNCTION_ShowMessageBox)
    {
        //����Ƿ������һ������
        if (pDispParams->cArgs != 1)
            return E_NOTIMPL;
        //�����������Ƿ����ַ�������
        if (pDispParams->rgvarg[0].vt != VT_BSTR)
            return E_NOTIMPL;
        //���ĵ���
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
        //�Եģ�����һ��IDispatch�������Լ�(this)������
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
//*****************************************JS����C++����,��������ν���


void CBAIDUMapDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//MessageBox("---->1");
	CString lng;
	CString lat;
	lngBox.GetWindowText(lng);
	latBox.GetWindowText(lat);
	CWebPage web;
	web.SetDocument(Browser.get_Document());
	const CString funcName("showMap");//������
	CComVariant varResult;
	web.CallJScript(funcName, lng, lat, &varResult);
}


void CBAIDUMapDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CWebPage web;
	web.SetDocument(Browser.get_Document());
	const CString funcName("getCenterPoint");//������
	CComVariant varResult;
	web.CallJScript(funcName, &varResult);
	CString str;
	str=varResult.bstrVal;
	SetDlgItemText(IDC_EDIT3,str);//IDC_EDIT1���edit�ؼ�ID
}


void CBAIDUMapDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString points;
	pointsEdit.GetWindowText(points);
	CWebPage web;
	web.SetDocument(Browser.get_Document());
	const CString funcName("pinpoints");//������
	CComVariant varResult;
	web.CallJScript(funcName, points, &varResult);
}


void CBAIDUMapDlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CComQIPtr<IHTMLDocument2> document = Browser.get_Document();
    CComDispatchDriver script;
    document->get_Script(&script);
    CComVariant var(static_cast<IDispatch*>(this));
    script.Invoke1(L"SaveCppObject", &var);
}

void CBAIDUMapDlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString points;
	pointsEdit.GetWindowText(points);
	CWebPage web;
	web.SetDocument(Browser.get_Document());
	const CString funcName("pinPolyline");//������
	CComVariant varResult;
	web.CallJScript(funcName, points, &varResult);
}


void CBAIDUMapDlg::OnBnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString points;
	pointsEdit.GetWindowText(points);
	CWebPage web;
	web.SetDocument(Browser.get_Document());
	const CString funcName("pinPolygon");//������
	CComVariant varResult;
	web.CallJScript(funcName, points, &varResult);
}

BEGIN_EVENTSINK_MAP(CBAIDUMapDlg, CDialogEx)
	ON_EVENT(CBAIDUMapDlg, IDC_EXPLORER1, 259, CBAIDUMapDlg::DocumentCompleteExplorer1, VTS_DISPATCH VTS_PVARIANT)
END_EVENTSINK_MAP()

//***********************ҳ�������Ϻ���JS����C++����
void CBAIDUMapDlg::DocumentCompleteExplorer1(LPDISPATCH pDisp, VARIANT* URL)
{
	// TODO: �ڴ˴������Ϣ����������
	CComQIPtr<IHTMLDocument2> document = Browser.get_Document();
    CComDispatchDriver script;
    document->get_Script(&script);
    CComVariant var(static_cast<IDispatch*>(this));
    script.Invoke1(L"SaveCppObject", &var);
}
