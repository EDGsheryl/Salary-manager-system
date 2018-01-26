// insert.cpp : 实现文件
//
#include "stdafx.h"
#include "salary.h"
#include "insert.h"
#include "afxdialogex.h"


// insert 对话框

IMPLEMENT_DYNAMIC(insert, CDialogEx)

insert::insert(CWnd* pParent /*=NULL*/)
	: CDialogEx()
{

}

insert::~insert()
{
}

void insert::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(insert, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON11, &insert::OnBnClickedButton11)
END_MESSAGE_MAP()


// insert 消息处理程序


void insert::OnBnClickedButton11()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str1;
	GetDlgItem(IDC_EDIT1)->GetWindowText(str1);
	CString str2;
	GetDlgItem(IDC_EDIT2)->GetWindowText(str2);
	CString str3;
	GetDlgItem(IDC_EDIT3)->GetWindowText(str3);
	CString str4;
	GetDlgItem(IDC_EDIT4)->GetWindowText(str4);

	if (str1 == ""){
		MessageBox(_T("请输入工号"));
		return;
	}
	if (str2 == "" ) {
		MessageBox(_T("请输入姓名"));
		return;
	}
	if (str3 != "男" && str3 != "女") {
		MessageBox(_T("请输入正确的性别"));
		return;
	}
	if (str4 != "经理" && str4!= "技术工" && str4!="普工" && str4!="临时工") {
		MessageBox(_T("请输入正确的岗位"));
		return;
	}

	for (auto i : manage_system::s) {
		if (str1 == i->getID())
		{
			MessageBox(_T("工号冲突！"));
			return;
		}
	}
	
	if (str4 != "临时工") manage_system::insert(str1, str2, str3, str4, 4000);
	else manage_system::insert(str1, str2, str3, str4, 5000);
	MessageBox(_T("插入成功！"));

	this->DestroyWindow();
}
