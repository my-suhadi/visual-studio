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
		SetupInterfacePointer();
		InitializeInterface();

		return true;
	}

	void SetupInterfacePointer()
	{
		pINPUT = (CEdit*)GetDlgItem(CE_INPUT);
		pOUTPUT = (CEdit*)GetDlgItem(CE_OUTPUT);
		pMULAI = (CButton*)GetDlgItem(CB_MULAI);
	}

	void InitializeInterface()
	{
		pINPUT->SetWindowTextA("Tulis Disini");
		pOUTPUT->SetWindowTextA("Klik \"MULAI\" untuk menjalankan");
	}
public:
	afx_msg void start() { TOMBOLMULAI(); }

	void TOMBOLMULAI()
	{
		MessageBox("BYe");
		pMULAI->EnableWindow(false);
	}

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

// GAME_FORM adalah child object sedangkan CDialog adalah parent object
BEGIN_MESSAGE_MAP(GAME_FORM, CDialog)
	// fungsi jangan dbuat di dalam class yg mewarisi CWinApp
	// fungsi harus dbuat di dalam class yg mewarisi CDialog
	ON_COMMAND(CB_MULAI, start)
END_MESSAGE_MAP()

TheGame theApp;