
// DayOfTheWeekMFCApp.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CDayOfTheWeekMFCAppApp:
// See DayOfTheWeekMFCApp.cpp for the implementation of this class
//

class CDayOfTheWeekMFCAppApp : public CWinApp
{
public:
	CDayOfTheWeekMFCAppApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CDayOfTheWeekMFCAppApp theApp;
