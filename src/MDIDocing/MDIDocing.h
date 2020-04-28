
// MDIDocing.h : main header file for the MDIDocing application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMDIDocingApp:
// See MDIDocing.cpp for the implementation of this class
//

class CMDIDocingApp : public CWinAppEx
{
public:
	CMDIDocingApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMDIDocingApp theApp;
