// PeoeleUpdate.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "salary.h"
#include "PeoeleUpdate.h"
#include "afxdialogex.h"


// PeoeleUpdate �Ի���

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


// PeoeleUpdate ��Ϣ�������



void PeoeleUpdate::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str1;
	GetDlgItem(IDC_EDIT5)->GetWindowText(str1);
	CString str2;
	GetDlgItem(IDC_EDIT6)->GetWindowText(str2);
	CString str3;
	GetDlgItem(IDC_EDIT7)->GetWindowText(str3);
	CString str4;
	GetDlgItem(IDC_EDIT8)->GetWindowText(str4);

	if (str1 == "") {
		MessageBox(_T("�����빤��"));
		return;
	}
	if (str3 != "��" && str3 != "Ů" && str3 != "") {
		MessageBox(_T("��������ȷ���Ա�"));
		return;
	}
	if (str4 != "����" && str4 != "������" && str4 != "�չ�" && str4 != "��ʱ��" && str4 != "") {
		MessageBox(_T("��������ȷ�ĸ�λ"));
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

	if (str4 != "��ʱ��") manage_system::update(str1, str2, str3, str4, 4000);
	else manage_system::update(str1, str2, str3, str4, 5000);
	MessageBox(_T("���³ɹ���"));

	this->DestroyWindow();
}
