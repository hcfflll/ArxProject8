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
//----- INDEX.cpp : Implementation of INDEX
//-----------------------------------------------------------------------------
#include "StdAfx.h"
#include "resource.h"
#include "INDEX.h"
#include "Table.h"
#include"Tool.h"
extern INDEX* pDialog;
//-----------------------------------------------------------------------------
IMPLEMENT_DYNAMIC (INDEX, CAdUiBaseDialog)

BEGIN_MESSAGE_MAP(INDEX, CAdUiBaseDialog)
	ON_MESSAGE(WM_ACAD_KEEPFOCUS, OnAcadKeepFocus)
	ON_WM_CLOSE()
	ON_EN_CHANGE(IDC_EDIT_CS, &INDEX::OnEnChangeEditCs)
	ON_EN_CHANGE(IDC_EDIT_MS, &INDEX::OnEnChangeEditMs)
	ON_EN_CHANGE(IDC_EDIT_CXJ, &INDEX::OnEnChangeEditCxj)
	ON_EN_CHANGE(IDC_EDIT_CDGXS, &INDEX::OnEnChangeEditCdgxs)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, &INDEX::OnBnClickedButtonCancel)
	ON_BN_CLICKED(IDC_BUTTON_START, &INDEX::OnBnClickedButtonStart)
	ON_EN_KILLFOCUS(IDC_EDIT_CS, &INDEX::OnEnKillfocusEditCs)
	ON_EN_KILLFOCUS(IDC_EDIT_MS, &INDEX::OnEnKillfocusEditMs)
	ON_EN_KILLFOCUS(IDC_EDIT_CXJ, &INDEX::OnEnKillfocusEditCxj)
	ON_EN_CHANGE(IDC_EDIT_LXJ, &INDEX::OnEnChangeEditLxj)
	ON_EN_CHANGE(IDC_EDIT_KCCS, &INDEX::OnEnChangeEditKccs)
	ON_EN_KILLFOCUS(IDC_EDIT_CDGXS, &INDEX::OnEnKillfocusEditCdgxs)
	ON_EN_KILLFOCUS(IDC_EDIT_LXJ, &INDEX::OnEnKillfocusEditLxj)
	ON_EN_CHANGE(IDC_EDIT_BWXS, &INDEX::OnEnChangeEditBwxs)
	ON_EN_CHANGE(IDC_EDIT_PDCLCS, &INDEX::OnEnChangeEditPdclcs)
	ON_EN_KILLFOCUS(IDC_EDIT_BWXS, &INDEX::OnEnKillfocusEditBwxs)
	ON_EN_KILLFOCUS(IDC_EDIT_KCCS, &INDEX::OnEnKillfocusEditKccs)
	ON_EN_KILLFOCUS(IDC_EDIT_PDCLCS, &INDEX::OnEnKillfocusEditPdclcs)
	ON_EN_CHANGE(IDC_EDIT_CK, &INDEX::OnEnChangeEditCk)
	ON_EN_KILLFOCUS(IDC_EDIT_CK, &INDEX::OnEnKillfocusEditCk)
END_MESSAGE_MAP()

//-----------------------------------------------------------------------------
INDEX::INDEX (CWnd *pParent /*=NULL*/, HINSTANCE hInstance /*=NULL*/) : CAdUiBaseDialog (INDEX::IDD, pParent, hInstance)
, C_CDGXS(_T(""))
, C_CS(_T(""))
, C_CXJ(_T(""))
, C_MS(_T(""))
, C_BWXS(_T(""))
, C_KCCS(_T(""))
, C_LXJ(_T(""))
, C_PDCLCS(_T(""))
, C_CK(_T(""))
{
}

//-----------------------------------------------------------------------------
void INDEX::DoDataExchange (CDataExchange *pDX) {
	CAdUiBaseDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_CANCEL, C_CANCEL);
	DDX_Control(pDX, IDC_BUTTON_START, C_START);
	DDX_Text(pDX, IDC_EDIT_CDGXS, C_CDGXS);
	DDX_Text(pDX, IDC_EDIT_CS, C_CS);
	DDX_Text(pDX, IDC_EDIT_CXJ, C_CXJ);
	DDX_Text(pDX, IDC_EDIT_MS, C_MS);
	DDX_Text(pDX, IDC_EDIT_BWXS, C_BWXS);
	DDX_Text(pDX, IDC_EDIT_KCCS, C_KCCS);
	DDX_Text(pDX, IDC_EDIT_LXJ, C_LXJ);
	DDX_Text(pDX, IDC_EDIT_PDCLCS, C_PDCLCS);
	DDX_Text(pDX, IDC_EDIT_CK, C_CK);
}

//-----------------------------------------------------------------------------
//----- Needed for modeless dialogs to keep focus.
//----- Return FALSE to not keep the focus, return TRUE to keep the focus
LRESULT INDEX::OnAcadKeepFocus (WPARAM, LPARAM) {
	return (TRUE) ;
}


BOOL INDEX::OnInitDialog()
{
	CAdUiBaseDialog::OnInitDialog();
	v_editcs.SetRange(-100.0,100.0);
	 v_editms.SetRange(-100.0, 100.0);
	 v_editcdgxs.SetRange(-100.0, 100.0);
	 v_editpdclcs.SetRange(-100.0, 100.0);
	v_editlxj.SetRange(-100.0, 100.0);
	v_editcxj.SetRange(-100.0, 100.0);
	v_editkccs.SetRange(-100.0, 100.0);
	 v_editbwxs.SetRange(-100.0, 100.0);
	 v_editck.SetRange(-100.0, 100.0);
	// TODO:  在此添加额外的初始化
	 v_cs = "0.0";
	 v_ms = "0.0";
	 v_cdgxs = "0.0";
	 v_pdclcs = "0.0";
	 v_lxj = "0.0";
	 v_cxj = "0.0";
	 v_kccs = "0.0";
	 v_bwxs = "0.0";
	 v_ck = "0.0";

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void INDEX::PostNcDestroy()
{
	// TODO: 在此添加专用代码和/或调用基类
	delete this;
	if (pDialog != NULL)
	{
		 pDialog = NULL ;
	}
	CAdUiBaseDialog::PostNcDestroy();
	
}


void INDEX::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CAdUiBaseDialog::OnClose();
	DestroyWindow();
}


void INDEX::OnEnChangeEditCs()//齿数
{
	v_editcs.Convert();
	v_editcs.SetWindowTextW(v_cs);

	// TODO:  在此添加控件通知处理程序代码
}
void INDEX::OnEnKillfocusEditCs()
{
	v_editcs.GetWindowTextW(v_cs);
	v_editcs.Convert();
	// TODO: 在此添加控件通知处理程序代码
}


void INDEX::OnEnChangeEditMs()//模数
{
	v_editms.GetWindowTextW(v_ms);
	v_editms.Convert();

	// TODO:  在此添加控件通知处理程序代码
}
void INDEX::OnEnKillfocusEditMs()
{

	// TODO: 在此添加控件通知处理程序代码
}


void INDEX::OnEnChangeEditCxj()//齿形角
{
	v_editcxj.GetWindowTextW(v_cxj);
	v_editcxj.Convert();
	// TODO:  在此添加控件通知处理程序代码
}
void INDEX::OnEnKillfocusEditCxj()
{
	// TODO: 在此添加控件通知处理程序代码
}

void INDEX::OnEnChangeEditCdgxs()//齿顶高系数
{
	v_editcdgxs.GetWindowTextW(v_cdgxs);
	v_editcdgxs.Convert();

	// TODO:  在此添加控件通知处理程序代码
}
void INDEX::OnEnKillfocusEditCdgxs()
{
	// TODO: 在此添加控件通知处理程序代码
}


void INDEX::OnBnClickedButtonCancel()//取消
{
	DestroyWindow();
	// TODO: 在此添加控件通知处理程序代码
}


void INDEX::OnBnClickedButtonStart()
{
	DestroyWindow();
	PostNcDestroy();
	Table::CreateTable();

	// TODO: 在此添加控件通知处理程序代码
}




void INDEX::OnEnChangeEditLxj() //螺旋角
{
	v_editlxj.GetWindowTextW(v_lxj);
	v_editlxj.Convert();

	// TODO:  在此添加控件通知处理程序代码
}
void INDEX::OnEnKillfocusEditLxj()
{
	// TODO: 在此添加控件通知处理程序代码
}

void INDEX::OnEnChangeEditKccs()
{
	v_editkccs.GetWindowTextW(v_kccs);
	v_editkccs.Convert();

	// TODO:  在此添加控件通知处理程序代码
}

void INDEX::OnEnKillfocusEditKccs()
{
	// TODO: 在此添加控件通知处理程序代码
}


void INDEX::OnEnChangeEditBwxs()
{
	v_editbwxs.GetWindowTextW(v_bwxs);
	v_editbwxs.Convert();

	// TODO:  在此添加控件通知处理程序代码
}
void INDEX::OnEnKillfocusEditBwxs()
{
	// TODO: 在此添加控件通知处理程序代码
}

void INDEX::OnEnChangeEditPdclcs()
{
	v_editpdclcs.GetWindowTextW(v_pdclcs);
	v_editpdclcs.Convert();

	// TODO:  在此添加控件通知处理程序代码
}
void INDEX::OnEnKillfocusEditPdclcs()
{
	// TODO: 在此添加控件通知处理程序代码
}









void INDEX::OnEnChangeEditCk()
{

	v_editck.GetWindowTextW(v_ck);
	v_editck.Convert();

	// TODO:  在此添加控件通知处理程序代码
}


void INDEX::OnEnKillfocusEditCk()
{
	// TODO: 在此添加控件通知处理程序代码
}


	


	

