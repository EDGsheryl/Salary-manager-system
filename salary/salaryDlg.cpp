
// salaryDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "salary.h"
#include "salaryDlg.h"
#include "afxdialogex.h"
#include "insert.h"
#include "PeopleDelete.h"
#include "PeoeleUpdate.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CsalaryDlg 对话框



CsalaryDlg::CsalaryDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_SALARY_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CsalaryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, mylist);
}

BEGIN_MESSAGE_MAP(CsalaryDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CsalaryDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CsalaryDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CsalaryDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CsalaryDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CsalaryDlg 消息处理程序

BOOL CsalaryDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	mylist.AddString(_T("工号\t 姓名\t 性别\t 职务\t 考勤天数\t 工资"));

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}
int people::stocks = 0;
set<people*> manage_system::s = *(new set<people*>());

void CsalaryDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CsalaryDlg::OnPaint()
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
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CsalaryDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CsalaryDlg::freshlist() {
	while (mylist.GetCount() > 0)
		mylist.DeleteString(0);
	mylist.AddString(_T("工号\t 姓名\t 性别\t 职务\t 考勤天数\t 工资"));
	for (auto i : manage_system::s) {
		mylist.AddString(i->getInfo());
	}
}


void CsalaryDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	insert *ins = new insert;
	ins->Create(IDD_DIALOG1, this);
	ins->ShowWindow(SW_SHOW);
}


void CsalaryDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	PeoeleUpdate *ins = new PeoeleUpdate;
	ins->Create(IDD_DIALOG2, this);
	ins->ShowWindow(SW_SHOW);
}


void CsalaryDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	PeopleDelete *ins = new PeopleDelete;
	ins->Create(IDD_DIALOG3, this);
	ins->ShowWindow(SW_SHOW);
}


void CsalaryDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	freshlist();
}
