// insert.cpp : ʵ���ļ�
//
#include "stdafx.h"
#include "salary.h"
#include "insert.h"
#include "afxdialogex.h"


// insert �Ի���

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


// insert ��Ϣ�������


void insert::OnBnClickedButton11()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str1;
	GetDlgItem(IDC_EDIT1)->GetWindowText(str1);
	CString str2;
	GetDlgItem(IDC_EDIT2)->GetWindowText(str2);
	CString str3;
	GetDlgItem(IDC_EDIT3)->GetWindowText(str3);
	CString str4;
	GetDlgItem(IDC_EDIT4)->GetWindowText(str4);

	if (str1 == ""){
		MessageBox(_T("�����빤��"));
		return;
	}
	if (str2 == "" ) {
		MessageBox(_T("����������"));
		return;
	}
	if (str3 != "��" && str3 != "Ů") {
		MessageBox(_T("��������ȷ���Ա�"));
		return;
	}
	if (str4 != "����" && str4!= "������" && str4!="�չ�" && str4!="��ʱ��") {
		MessageBox(_T("��������ȷ�ĸ�λ"));
		return;
	}

	for (auto i : manage_system::s) {
		if (str1 == i->getID())
		{
			MessageBox(_T("���ų�ͻ��"));
			return;
		}
	}
	
	if (str4 != "��ʱ��") manage_system::insert(str1, str2, str3, str4, 4000);
	else manage_system::insert(str1, str2, str3, str4, 5000);
	MessageBox(_T("����ɹ���"));

	this->DestroyWindow();
}
