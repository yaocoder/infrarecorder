/*
 * InfraRecorder - CD/DVD burning software
 * Copyright (C) 2006-2012 Christian Kindahl
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

#include "stdafx.hh"
#include "string_table.hh"
#include "lang_util.hh"
#include "copy_disc_dlg.hh"

CCopyDiscDlg::CCopyDiscDlg(bool bAppMode) :
    m_bCentered(false),m_bAppMode(bAppMode),
    m_pSrcDevice(NULL),m_pDstDevice(NULL),
    CPropertySheetImpl<CCopyDiscDlg>(lngGetString(COPYDISC_TITLE),0,NULL),
    m_GeneralPage(),
    m_ReadPage(false,false)
{
    m_psh.dwFlags |= PSH_NOAPPLYNOW | PSH_HASHELP | PSH_NOCONTEXTHELP;

    AddPage(m_GeneralPage);
    AddPage(m_AdvancedPage);
    AddPage(m_ReadPage);
}

CCopyDiscDlg::~CCopyDiscDlg()
{
}

LRESULT CCopyDiscDlg::OnShowWindow(UINT uMsg,WPARAM wParam,LPARAM lParam,BOOL &bHandled)
{
    // Center the window, once.
    if (wParam == TRUE && !m_bCentered)
    {
        CenterWindow();
        m_bCentered = true;
    }

    // Add the dialog to the task bar and enable it to be minimized.
    if (m_bAppMode)
    {
        ModifyStyle(0,WS_MINIMIZEBOX | WS_SYSMENU);
        ModifyStyleEx(0,WS_EX_APPWINDOW);

        HMENU hSysMenu = GetSystemMenu(FALSE);
        ::InsertMenu(hSysMenu,0,MF_BYPOSITION,SC_RESTORE,_T("&Restore"));
        ::InsertMenu(hSysMenu,2,MF_BYPOSITION,SC_MINIMIZE,_T("Mi&nimize"));
        ::InsertMenu(hSysMenu,3,MF_BYPOSITION | MF_SEPARATOR,0,_T(""));
    }

    bHandled = FALSE;
    return 0;
}

LRESULT CCopyDiscDlg::OnSetDevice(UINT uMsg,WPARAM wParam,LPARAM lParam,BOOL &bHandled)
{
    if (wParam == 1)
        m_pSrcDevice = reinterpret_cast<ckmmc::Device *>(lParam);
    else
        m_pDstDevice = reinterpret_cast<ckmmc::Device *>(lParam);

    bHandled = TRUE;
    return 0;
}

LRESULT CCopyDiscDlg::OnGetDevice(UINT uMsg,WPARAM wParam,LPARAM lParam,BOOL &bHandled)
{
    bHandled = TRUE;
    return reinterpret_cast<LRESULT>(wParam == 1 ? m_pSrcDevice : m_pDstDevice);
}

LRESULT CCopyDiscDlg::OnSetCloneMode(UINT uMsg,WPARAM wParam,LPARAM lParam,BOOL &bHandled)
{
    m_ReadPage.SetCloneMode(wParam == TRUE);

    bHandled = TRUE;
    return 0;
}
