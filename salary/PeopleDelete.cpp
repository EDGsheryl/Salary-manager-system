// PeopleDelete.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "salary.h"
#include "PeopleDelete.h"
#include "afxdialogex.h"


// PeopleDelete �Ի���

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


// PeopleDelete ��Ϣ�������


void PeopleDelete::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str1;
	GetDlgItem(IDC_EDIT9)->GetWindowText(str1);

	if (str1 == "") {
		MessageBox(_T("�����빤��"));
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
		MessageBox(_T("δ�ҵ����ţ�"));
		return;
	}

	manage_system::remove(str1);
	MessageBox(_T("�Ƴ��ɹ�"));

	this->DestroyWindow();
}
