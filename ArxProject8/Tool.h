#pragma once
#include"StdAfx.h"
class Tool
{
public:
	static AcDbObjectId AddToModeSpace(AcDbEntity* pEnd);
	static void Changeline25(AcDbObjectId LineId);
	static void Changeline50(AcDbObjectId LineId);
	static void Write();
};

