// PeoeleUpdate.cpp : 实现文件
//

#include "stdafx.h"
#include "salary.h"
#include "PeoeleUpdate.h"
#include "afxdialogex.h"


// PeoeleUpdate 对话框

IMPLEMENT_DYNAMIC(PeoeleUpdate, CDialogEx)

PeoeleUpdate::PeoeleUpdate(CWnd* pParent /*=NULL*/)
	: CDialogEx()
{

}

PeoeleUpdate::~PeoeleUpdate()
{
}

void PeoeleUpdate::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(PeoeleUpdate, CDialogEx)
	ON_BN_CLICKED(IDOK, &PeoeleUpdate::OnBnClickedOk)
END_MESSAGE_MAP()


// PeoeleUpdate 消息处理程序



void PeoeleUpdate::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str1;
	GetDlgItem(IDC_EDIT5)->GetWindowText(str1);
	CString str2;
	GetDlgItem(IDC_EDIT6)->GetWindowText(str2);
	CString str3;
	GetDlgItem(IDC_EDIT7)->GetWindowText(str3);
	CString str4;
	GetDlgItem(IDC_EDIT8)->GetWindowText(str4);

	if (str1 == "") {
		MessageBox(_T("请输入工号"));
		return;
	}
	if (str3 != "男" && str3 != "女" && str3 != "") {
		MessageBox(_T("请输入正确的性别"));
		return;
	}
	if (str4 != "经理" && str4 != "技术工" && str4 != "普工" && str4 != "临时工" && str4 != "") {
		MessageBox(_T("请输入正确的岗位"));
		return;
	}
	bool findflag = 0;
	for (auto i : manage_system::s) {
		if (str1 == i->getID())
		{
			findflag = 1;
		}
	}
	if (!findflag) {
		MessageBox(_T("未找到工号！"));
		return;
	}

	if (str4 != "临时工") manage_system::update(str1, str2, str3, str4, 4000);
	else manage_system::update(str1, str2, str3, str4, 5000);
	MessageBox(_T("更新成功！"));

	this->DestroyWindow();
}
