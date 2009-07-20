/*
 * InfraRecorder - CD/DVD burning software
 * Copyright (C) 2006-2009 Christian Kindahl
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "stdafx.h"
#include "ReadOptionsPage.h"
#include "CtrlMessages.h"
#include "StringTable.h"
#include "LangUtil.h"
#include "Settings.h"
#include "TransUtil.h"
#include "Core2.h"
#include "Core2Util.h"
#include "WinVer.h"
#include "InfraRecorder.h"
#include "VisualStyles.h"

CReadOptionsPage::CReadOptionsPage(bool bEnableClone,bool bEnableSpeed)
{
	m_bEnableClone = bEnableClone;
	m_bEnableSpeed = bEnableSpeed;
	m_hRefreshIcon = NULL;
	m_hRefreshImageList = NULL;

	// Try to load translated string.
	if (g_LanguageSettings.m_pLngProcessor != NULL)
	{	
		// Make sure that there is a strings translation section.
		if (g_LanguageSettings.m_pLngProcessor->EnterSection(_T("strings")))
		{
			TCHAR *szStrValue;
			if (g_LanguageSettings.m_pLngProcessor->GetValuePtr(TITLE_READ,szStrValue))
				SetTitle(szStrValue);
		}
	}

	m_psp.dwFlags |= PSP_HASHELP;
}

CReadOptionsPage::~CReadOptionsPage()
{
	if (m_hRefreshImageList != NULL)
		ImageList_Destroy(m_hRefreshImageList);

	if (m_hRefreshIcon != NULL)
		DestroyIcon(m_hRefreshIcon);
}

bool CReadOptionsPage::Translate()
{
	if (g_LanguageSettings.m_pLngProcessor == NULL)
		return false;

	CLngProcessor *pLng = g_LanguageSettings.m_pLngProcessor;
	
	// Make sure that there is a burn translation section.
	if (!pLng->EnterSection(_T("read")))
		return false;

	// Translate.
	TCHAR *szStrValue;
	int iMaxStaticRight = 0;

	if (pLng->GetValuePtr(IDC_NOREADERRCHECK,szStrValue))
		SetDlgItemText(IDC_NOREADERRCHECK,szStrValue);
	if (pLng->GetValuePtr(IDC_READSUBCHANNELCHECK,szStrValue))
		SetDlgItemText(IDC_READSUBCHANNELCHECK,szStrValue);
	if (pLng->GetValuePtr(IDC_READSPEEDSTATIC,szStrValue))
	{
		SetDlgItemText(IDC_READSPEEDSTATIC,szStrValue);

		// Update the static width if necessary.
		int iStaticRight = UpdateStaticWidth(m_hWnd,IDC_READSPEEDSTATIC,szStrValue);
		if (iStaticRight > iMaxStaticRight)
			iMaxStaticRight = iStaticRight;
	}

	// Make sure that the edit/combo controls are not in the way of the statics.
	if (iMaxStaticRight > 75)
		UpdateEditPos(m_hWnd,IDC_READSPEEDCOMBO,iMaxStaticRight,true);

	return true;
}

bool CReadOptionsPage::OnApply()
{
	// Remember the configuration.
	g_ReadSettings.m_bIgnoreErr = IsDlgButtonChecked(IDC_NOREADERRCHECK) == TRUE;
	g_ReadSettings.m_bClone = IsDlgButtonChecked(IDC_READSUBCHANNELCHECK) == TRUE;
	g_ReadSettings.m_iReadSpeed = m_ReadSpeedCombo.GetItemData(m_ReadSpeedCombo.GetCurSel());

	return true;
}

void CReadOptionsPage::OnHelp()
{
	TCHAR szFileName[MAX_PATH];
	GetModuleFileName(NULL,szFileName,MAX_PATH - 1);

	ExtractFilePath(szFileName);
	lstrcat(szFileName,lngGetManual());
	lstrcat(szFileName,_T("::/how_to_use/read_options.html"));

	HtmlHelp(m_hWnd,szFileName,HH_DISPLAY_TOC,NULL);
}

void CReadOptionsPage::UpdateSpeeds()
{
	// FIXME: Change to pointer.
	ckmmc::Device &Device =
		*reinterpret_cast<ckmmc::Device *>(::SendMessage(GetParent(),WM_GETDEVICE,1,0));

	// Maximum read speed.
	m_ReadSpeedCombo.ResetContent();
	m_ReadSpeedCombo.AddString(lngGetString(MISC_MAXIMUM));
	m_ReadSpeedCombo.SetItemData(0,0xFFFFFFFF);
	m_ReadSpeedCombo.SetCurSel(0);

	
	// Get current profile.
	unsigned short usProfile = PROFILE_NONE;
	if (g_Core2.GetProfile(Device,usProfile) && usProfile != PROFILE_NONE)
	{
		// List a few other read speeds.
		unsigned short usMaxSpeed = 0;
		if (g_Core2.GetMaxReadSpeed(Device,usMaxSpeed))
		{
			std::vector<unsigned int> Speeds;
			if (GetDispSpeeds((unsigned int)GetDispSpeed(usProfile,usMaxSpeed),Speeds))
			{
				TCHAR szBuffer[64];
				for (unsigned int i = 0; i < Speeds.size(); i++)
				{
					lsprintf(szBuffer,_T("%dx"),Speeds[i]);
					m_ReadSpeedCombo.AddString(szBuffer);
					m_ReadSpeedCombo.SetItemData(m_ReadSpeedCombo.GetCount() - 1,Speeds[i]);
					// It would be nice if one could ppass floating point numbers as
					// write speed to cdrecord/wodim!
				}
			}
		}
	}
}

void CReadOptionsPage::CheckMedia()
{
	if (m_bEnableSpeed)
	{
		UpdateSpeeds();
	}
	else
	{
		m_ReadSpeedCombo.ResetContent();
		m_ReadSpeedCombo.AddString(lngGetString(MISC_AUTO));
		m_ReadSpeedCombo.SetCurSel(0);
	}
}

LRESULT CReadOptionsPage::OnInitDialog(UINT uMsg,WPARAM wParam,LPARAM lParam,BOOL &bHandled)
{
	m_ReadSpeedCombo = GetDlgItem(IDC_READSPEEDCOMBO);

	CheckDlgButton(IDC_NOREADERRCHECK,g_ReadSettings.m_bIgnoreErr);

	// Enable/disable options.
	if (!m_bEnableClone)
	{
		::EnableWindow(GetDlgItem(IDC_READSUBCHANNELCHECK),FALSE);
		CheckDlgButton(IDC_READSUBCHANNELCHECK,m_bCloneCheck);
	}
	else
	{
		CheckDlgButton(IDC_READSUBCHANNELCHECK,g_ReadSettings.m_bClone);
	}

	if (!m_bEnableSpeed)
	{
		::EnableWindow(GetDlgItem(IDC_READSPEEDSTATIC),FALSE);
		::EnableWindow(GetDlgItem(IDC_READSPEEDCOMBO),FALSE);
	}

	// Translate the window.
	Translate();

	return TRUE;
}

LRESULT CReadOptionsPage::OnShowWindow(UINT uMsg,WPARAM wParam,LPARAM lParam,BOOL &bHandled)
{
	if ((BOOL)wParam == TRUE)
		CheckMedia();

	bHandled = FALSE;
	return 0;
}

LRESULT CReadOptionsPage::OnCheckMedia(UINT uMsg,WPARAM wParam,LPARAM lParam,BOOL &bHandled)
{
	CheckMedia();

	bHandled = FALSE;
	return 0;
}

void CReadOptionsPage::SetCloneMode(bool bEnable)
{
	m_bCloneCheck = bEnable;

	if (IsWindow())
		CheckDlgButton(IDC_READSUBCHANNELCHECK,bEnable);
}
