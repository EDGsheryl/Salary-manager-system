#pragma once


// PeoeleUpdate �Ի���

class PeoeleUpdate : public CDialogEx
{
	DECLARE_DYNAMIC(PeoeleUpdate)

public:
	PeoeleUpdate(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~PeoeleUpdate();

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
