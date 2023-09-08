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
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
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
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void INDEX::PostNcDestroy()
{
	// TODO: �ڴ����ר�ô����/����û���
	delete this;
	if (pDialog != NULL)
	{
		 pDialog = NULL ;
	}
	CAdUiBaseDialog::PostNcDestroy();
	
}


void INDEX::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CAdUiBaseDialog::OnClose();
	DestroyWindow();
}


void INDEX::OnEnChangeEditCs()//����
{
	v_editcs.Convert();
	v_editcs.SetWindowTextW(v_cs);

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
void INDEX::OnEnKillfocusEditCs()
{
	v_editcs.GetWindowTextW(v_cs);
	v_editcs.Convert();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void INDEX::OnEnChangeEditMs()//ģ��
{
	v_editms.GetWindowTextW(v_ms);
	v_editms.Convert();

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
void INDEX::OnEnKillfocusEditMs()
{

	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void INDEX::OnEnChangeEditCxj()//���ν�
{
	v_editcxj.GetWindowTextW(v_cxj);
	v_editcxj.Convert();
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
void INDEX::OnEnKillfocusEditCxj()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

void INDEX::OnEnChangeEditCdgxs()//�ݶ���ϵ��
{
	v_editcdgxs.GetWindowTextW(v_cdgxs);
	v_editcdgxs.Convert();

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
void INDEX::OnEnKillfocusEditCdgxs()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void INDEX::OnBnClickedButtonCancel()//ȡ��
{
	DestroyWindow();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void INDEX::OnBnClickedButtonStart()
{
	DestroyWindow();
	PostNcDestroy();
	Table::CreateTable();

	// TODO: �ڴ���ӿؼ�֪ͨ����������
}




void INDEX::OnEnChangeEditLxj() //������
{
	v_editlxj.GetWindowTextW(v_lxj);
	v_editlxj.Convert();

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
void INDEX::OnEnKillfocusEditLxj()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

void INDEX::OnEnChangeEditKccs()
{
	v_editkccs.GetWindowTextW(v_kccs);
	v_editkccs.Convert();

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

void INDEX::OnEnKillfocusEditKccs()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void INDEX::OnEnChangeEditBwxs()
{
	v_editbwxs.GetWindowTextW(v_bwxs);
	v_editbwxs.Convert();

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
void INDEX::OnEnKillfocusEditBwxs()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

void INDEX::OnEnChangeEditPdclcs()
{
	v_editpdclcs.GetWindowTextW(v_pdclcs);
	v_editpdclcs.Convert();

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
void INDEX::OnEnKillfocusEditPdclcs()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}









void INDEX::OnEnChangeEditCk()
{

	v_editck.GetWindowTextW(v_ck);
	v_editck.Convert();

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void INDEX::OnEnKillfocusEditCk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


	


	

