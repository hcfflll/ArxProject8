// (C) Copyright 2002-2007 by Autodesk, Inc. 
//
// Permission to use, copy, modify, and distribute this software in
// object code form for any purpose and without fee is hereby granted, 
// provided that the above copyright notice appears in all copies and 
// that both that copyright notice and the limited warranty and
// restricted rights notice below appear in all supporting 
// documentation.
//
// AUTODESK PROVIDES THIS PROGRAM "AS IS" AND WITH ALL FAULTS. 
// AUTODESK SPECIFICALLY DISCLAIMS ANY IMPLIED WARRANTY OF
// MERCHANTABILITY OR FITNESS FOR A PARTICULAR USE.  AUTODESK, INC. 
// DOES NOT WARRANT THAT THE OPERATION OF THE PROGRAM WILL BE
// UNINTERRUPTED OR ERROR FREE.
//
// Use, duplication, or disclosure by the U.S. Government is subject to 
// restrictions set forth in FAR 52.227-19 (Commercial Computer
// Software - Restricted Rights) and DFAR 252.227-7013(c)(1)(ii)
// (Rights in Technical Data and Computer Software), as applicable.
//

//-----------------------------------------------------------------------------
//----- INDEX.h : Declaration of the INDEX
//-----------------------------------------------------------------------------
#pragma once

//-----------------------------------------------------------------------------
#include "adui.h"
#include <resource.h>
//-----------------------------------------------------------------------------
class INDEX : public CAdUiBaseDialog {
	DECLARE_DYNAMIC (INDEX)

public:
	INDEX (CWnd *pParent =NULL, HINSTANCE hInstance =NULL) ;

	enum{IDD = IDD_DIALOG_INDEX1} ;

protected:
	virtual void DoDataExchange (CDataExchange *pDX) ;
	afx_msg LRESULT OnAcadKeepFocus (WPARAM, LPARAM) ;

	DECLARE_MESSAGE_MAP()
public:
	CButton C_CANCEL;
	CButton C_START;
	CString C_CDGXS;
	CString C_CS;
	CString C_CXJ;
	CString C_MS;
	CString C_LXJ;
	CString C_KCCS;
	CString C_PDCLCS;
	CString C_BWXS;
	CString C_CK;
	CAcUiAngleEdit v_editcs;
	CAcUiAngleEdit v_editms;
	CAcUiAngleEdit v_editcdgxs;
	CAcUiAngleEdit v_editpdclcs;
	CAcUiAngleEdit v_editlxj;
	CAcUiAngleEdit v_editcxj;
	CAcUiAngleEdit v_editkccs;
	CAcUiAngleEdit v_editbwxs;
	CAcUiAngleEdit v_editck;
	virtual BOOL OnInitDialog();
	virtual void PostNcDestroy();
	afx_msg void OnClose();
	afx_msg void OnEnChangeEditCs();
	afx_msg void OnEnChangeEditMs();
	afx_msg void OnEnChangeEditCxj();
	afx_msg void OnEnChangeEditCdgxs();
	afx_msg void OnBnClickedButtonCancel();
	afx_msg void OnBnClickedButtonStart();
	afx_msg void OnEnKillfocusEditCs();
	afx_msg void OnEnKillfocusEditMs();
	afx_msg void OnEnKillfocusEditCxj();
	afx_msg void OnEnChangeEditLxj();
	afx_msg void OnEnChangeEditKccs();
	afx_msg void OnEnKillfocusEditCdgxs();
	afx_msg void OnEnKillfocusEditLxj();
	afx_msg void OnEnChangeEditBwxs();
	afx_msg void OnEnChangeEditPdclcs();
	afx_msg void OnEnKillfocusEditBwxs();
	afx_msg void OnEnKillfocusEditKccs();
	afx_msg void OnEnKillfocusEditPdclcs();
public:
	CString v_cs;
	CString v_ms;
	CString v_cdgxs;
	CString v_pdclcs;
	CString v_lxj;
	CString v_cxj;
	CString v_kccs;
	CString v_bwxs;
	CString v_ck;
	afx_msg void OnEnChangeEditCk();
	afx_msg void OnEnKillfocusEditCk();

} ;
