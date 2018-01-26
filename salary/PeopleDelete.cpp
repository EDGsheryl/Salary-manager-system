// PeopleDelete.cpp : 实现文件
//

#include "stdafx.h"
#include "salary.h"
#include "PeopleDelete.h"
#include "afxdialogex.h"


// PeopleDelete 对话框

IMPLEMENT_DYNAMIC(PeopleDelete, CDialogEx)

PeopleDelete::PeopleDelete(CWnd* pParent /*=NULL*/)
	: CDialogEx()
{

}

PeopleDelete::~PeopleDelete()
{
}

void PeopleDelete::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(PeopleDelete, CDialogEx)
	ON_BN_CLICKED(IDOK, &PeopleDelete::OnBnClickedOk)
END_MESSAGE_MAP()


// PeopleDelete 消息处理程序


void PeopleDelete::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str1;
	GetDlgItem(IDC_EDIT9)->GetWindowText(str1);

	if (str1 == "") {
		MessageBox(_T("请输入工号"));
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

	manage_system::remove(str1);
	MessageBox(_T("移除成功"));

	this->DestroyWindow();
}
