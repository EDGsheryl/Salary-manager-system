#pragma once


// insert �Ի���

class insert : public CDialogEx
{
	DECLARE_DYNAMIC(insert)

public:
	insert(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~insert();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD =  };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton11();
};
