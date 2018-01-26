#pragma once


// PeopleDelete 对话框

class PeopleDelete : public CDialogEx
{
	DECLARE_DYNAMIC(PeopleDelete)

public:
	PeopleDelete(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~PeopleDelete();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD =  };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
