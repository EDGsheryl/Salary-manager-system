#pragma once


// insert 对话框

class insert : public CDialogEx
{
	DECLARE_DYNAMIC(insert)

public:
	insert(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~insert();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD =  };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton11();
};
