# MDIDocking
MDI Docking user interface with dock panel buttons

## Dynamically create dock buttons

1) Add CButton member variable :
For example

		protected:
			CButton m_ClearButton;
			CButton m_RunButton;
			CButton m_ButtonShowAll;

2) Create Buttons without rectangle into OnCreate function:
For example:

		CRect rectDummy;
		rectDummy.SetRectEmpty(); // set empty rectangle

		m_ButtonShowAll.Create(_T("Show All"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			rectDummy, this, ID_SHOW_ALL_BUTTON);

		m_ClearButton.Create(_T("Clear"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			rectDummy, this, ID_CLEAR_BUTTON);


		m_RunButton.Create(_T("Filter"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			rectDummy, this, ID_RUN_BUTTON);

and add your icon :

	m_ButtonShowAll.SetIcon((HICON)LoadImage(AfxGetApp()->m_hInstance,
		MAKEINTRESOURCE(IDI_PROPERTIES_SHOW_ALL),
		IMAGE_ICON, 16, 16, LR_DEFAULTCOLOR));
	m_ClearButton.SetIcon((HICON)LoadImage(AfxGetApp()->m_hInstance,
		MAKEINTRESOURCE(IDI_PROPERTIES_CLEAR),
		IMAGE_ICON, 16, 16, LR_DEFAULTCOLOR));
	m_RunButton.SetIcon((HICON)LoadImage(AfxGetApp()->m_hInstance,
		MAKEINTRESOURCE(IDI_PROPERTIES_RUN),
		IMAGE_ICON, 16, 16, LR_DEFAULTCOLOR));


 3) Adjust Layout ( onCreate and OnSize events ):
 for example:

 		m_ButtonShowAll.SetWindowPos(nullptr, rectClient.left,
			rectClient.top + m_nComboHeight + cyTlb +
			rectClient.Height() - (m_nComboHeight + cyTlb) - m_nComboHeight,
			rectClient.Width() / 3, m_nComboHeight
			, SWP_NOACTIVATE | SWP_NOZORDER);


		m_ClearButton.SetWindowPos(nullptr, rectClient.left + rectClient.Width() / 3,
			rectClient.top + m_nComboHeight + cyTlb + 
			rectClient.Height() - (m_nComboHeight + cyTlb) - m_nComboHeight,
			rectClient.Width()/3, m_nComboHeight
			, SWP_NOACTIVATE | SWP_NOZORDER);


		m_RunButton.SetWindowPos(nullptr, rectClient.left + (rectClient.Width()/3)*2,
			rectClient.top + m_nComboHeight + cyTlb + 
			rectClient.Height() - (m_nComboHeight + cyTlb) - m_nComboHeight,
			rectClient.Width() / 3, m_nComboHeight
			, SWP_NOACTIVATE | SWP_NOZORDER);

5) After adjust the button you have to make it visible cButton->ShowWindow(true);

for example: 

	m_ButtonShowAll.ShowWindow(TRUE);
	m_ClearButton.ShowWindow(TRUE);
	m_RunButton.ShowWindow(TRUE);


6) You have to manually set up the message map for these ON_COMMAND and ON_UPDATE events.
For example:

		ON_COMMAND(ID_SHOW_ALL_BUTTON, OnShowAllButton)
		ON_UPDATE_COMMAND_UI(ID_SHOW_ALL_BUTTON, OnUpdateShowAllButton)

		ON_COMMAND(ID_CLEAR_BUTTON, OnClearButton)
		ON_UPDATE_COMMAND_UI(ID_CLEAR_BUTTON, OnUpdateClearButton)

		ON_COMMAND(ID_RUN_BUTTON, OnRunButton)
		ON_UPDATE_COMMAND_UI(ID_RUN_BUTTON, OnUpdateRunButton)


7) Set font as menu items:
For example:

		void CPropertiesWnd::SetCheckBoxFont() {

			::DeleteObject(m_fntCheckBox.Detach());
			LOGFONT lf;
			afxGlobalData.fontRegular.GetLogFont(&lf);

			NONCLIENTMETRICS info;
			info.cbSize = sizeof(info);

			afxGlobalData.GetNonClientMetrics(info);

			lf.lfHeight = info.lfMenuFont.lfHeight;
			lf.lfWeight = info.lfMenuFont.lfWeight;
			lf.lfItalic = info.lfMenuFont.lfItalic;

			m_fntCheckBox.CreateFontIndirect(&lf);


			m_CheckboxOR.SetFont(&m_fntCheckBox);
		}

## Using c++ 11 lambda expression:

		bool CLicenseView::FindString(const std::string& strHaystack,
					const std::string& strNeedle)
		{
			auto it = std::search(
				strHaystack.begin(), strHaystack.end(),
				strNeedle.begin(), strNeedle.end(),
				[](char ch1, char ch2) -> bool { return std::tolower(ch1) == std::tolower(ch2); }
			);
			return (it != strHaystack.end());
		}



		bool CLicenseView::CaseInSensCompare(const std::string& str1, 
		          const std::string& str2)
		{
			return ((str1.size() == str2.size()) &&
				std::equal(str1.begin(), str1.end(), str2.begin(), 
					[](char c1, char c2) -> bool {
						if (c1 == c2)
							return true;
						else if (std::tolower(c1) == std::tolower(c2))
							return true;
						return false;
					}
				  ));
		}
