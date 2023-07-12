
// Variant10Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Variant10.h"
#include "Variant10Dlg.h"
#include "afxdialogex.h"
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <conio.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CVariant10Dlg dialog



CVariant10Dlg::CVariant10Dlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_VARIANT10_DIALOG, pParent)
	, INPUT(_T(""))
	, OUTPUT(_T("Result:"))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CVariant10Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, INPUT);
	DDX_Text(pDX, IDC_E1, OUTPUT);
	SetWindowTextW(L"Program of sorting words in alphabet order");
}

BEGIN_MESSAGE_MAP(CVariant10Dlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CVariant10Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CVariant10Dlg::OnBnClickedButton2)
	ON_COMMAND(ID_MENU_CLEAR, &CVariant10Dlg::OnMenuClear)
END_MESSAGE_MAP()


// CVariant10Dlg message handlers

BOOL CVariant10Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	for (int q = 0; q < 90; q++)
	{
		for (int e = 0; e < 10; e++)
		{
			words[q][e] = ' ';
		}

	}


	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CVariant10Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CVariant10Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CVariant10Dlg::OnBnClickedButton1()
{
	// INPUT
	if (word_counter<=89)
	{
	UpdateData(true);
	input_string = INPUT;
	UpdateData(false);

	in_order_string += input_string;
	in_order_string += " ";



	//alphabet sort

			for (int i = 0; i < input_string.GetLength(); i++)
			{
				words[word_counter][i] = input_string.GetAt(i);
			}

	if (word_counter>0)
	{ 
			for (int x = 0; x < word_counter;x++ )
			{
				for (int i = 0; i < word_counter; i++)
				{
					for (int k = 0; (k < 10); k++)
					{
						if ((words[i + 1][k] == ' ') || (words[i][k] == ' '))break;
						if ((words[i + 1][k] == words[i][k]))k++;
						if ((words[i + 1][k] < words[i][k]) && (fg == false) && (words[i + 1][k] != words[i][k])) {  //

							for (int c = 0; c < k; c++)
							{
								if ((words[i + 1][c] > words[i][c]))fg=true;
							}

							if (fg==false)
							{
								for (int d = 0; d < 10; d++)
								{
									word_buffer[0][d] = ' ';
									word_buffer[0][d] = words[i][d];
								}

								for (int s = 0; s < 10; s++)
								{
									words[i][s] = ' ';
									words[i][s] = words[i + 1][s];
								}

								for (int j = 0; j < 10; j++)
								{
									words[i + 1][j] = ' ';
									words[i + 1][j] = word_buffer[0][j];
								}
								fg = true;
							}
						}
					}
					fg = false;	
				}
			}
			///////
	}
		
		word_counter++;
	}
	else
	{
		ms = "Too much words";
		UpdateData(true);
		OUTPUT = ms;
		UpdateData(false);
	}

	


}


void CVariant10Dlg::OnBnClickedButton2()
{
	// OUTPUT

	for (int w = 0; w < word_counter; w++)
	{
		for (int i = 0; i < 10; i++)
		{
			if(words[w][i]!=' ')alphabet_string += (CString)words[w][i];
		}
		alphabet_string += " ";
	}
	ms = "";
	ms += "  Result: ";
	ms += in_order_string;
	ms += "\n  ";
	ms += "In alphabet order: ";
	ms += alphabet_string;
	UpdateData(true);
	OUTPUT = ms;
	UpdateData(false);
	
}


void CVariant10Dlg::OnMenuClear()
{
	// button clear

	word_counter = 0;
	in_order_string = "";
	alphabet_string = "";
	for (int q = 0; q < 90; q++)
	{
		for (int e = 0; e < 10; e++)
		{
			words[q][e] = ' ';
		}

	}
	ms = "";
	UpdateData(true);
	OUTPUT = ms;
	UpdateData(false);
}
