#include <afxwin.h>
#include "resource.h"

// Variabel global
CEdit* pINPUT;
CEdit* pOUTPUT;
CButton* pMULAI;

class GAME_FORM : public CDialog
{
public:
	GAME_FORM(CWnd* pParent = NULL): CDialog(GAME_FORM::IDD, pParent)
	{}
	enum{IDD = INTERFACE1};
protected:
	virtual void DoDataExchange(CDataExchange* pDx)
	{
		CDialog::DoDataExchange(pDx);
	}
	virtual BOOL OnInitDialog()
	{
		CDialog::OnInitDialog();
		return true;
	}
public:
	DECLARE_MESSAGE_MAP()
};

class TheGame : public CWinApp
{
public:
	TheGame()
	{}
	virtual BOOL InitInstance()
	{
		CWinApp::InitInstance();
		GAME_FORM dlg;
		m_pMainWnd = &dlg;
		INT_PTR nResponse = dlg.DoModal();
		return FALSE;
	}
};

BEGIN_MESSAGE_MAP(GAME_FORM, CDialog)
END_MESSAGE_MAP()

TheGame theApp;