#pragma once


// PeopleDelete �Ի���

class PeopleDelete : public CDialogEx
{
	DECLARE_DYNAMIC(PeopleDelete)

public:
	PeopleDelete(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~PeopleDelete();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD =  };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
