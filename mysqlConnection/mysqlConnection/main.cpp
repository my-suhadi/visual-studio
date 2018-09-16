#include <afxwin.h>
#include <mysql.h>
#include "resource.h"


MYSQL* conn;

// kelas pertama turunan dari CDialog atau CFrameWnd
class SQL_WINDOW : public CDialog
{
public:
	SQL_WINDOW(CWnd* pParent = NULL) : CDialog(SQL_WINDOW::IDD, pParent)
	{}

	enum {IDD = INTERFACE};
	DECLARE_MESSAGE_MAP()

protected:
	virtual void DoDataExchange(CDataExchange *pDX) { CDialog::DoDataExchange(pDX); }
	virtual BOOL OnInitDialog()
	{
		CDialog::OnInitDialog();
		conn = mysql_init(0);
		conn = mysql_real_connect(conn, "202.61.104.191", "root", "Gazper34", "mysql", 3307, NULL, 0);
		return true;
	}
};

// kelas kedua turunan dari CWinApp dan membuat instan dr kelas pertama
class SQL_APP : public CWinApp
{
public:
	SQL_APP() {}

	virtual BOOL InitInstance()
	{
		CWinApp::InitInstance();
		SQL_WINDOW dlg;
		m_pMainWnd = &dlg;
		INT_PTR nResponse = dlg.DoModal();
		return FALSE;
	}
};

BEGIN_MESSAGE_MAP (SQL_WINDOW, CDialog)
END_MESSAGE_MAP()

SQL_APP runApp;