#pragma once
class Table
{
public:
	static void Init();
	static void Unload();
	static void CreateTable();
	static AcDbObjectId CreateLinex(int i,double r,double c);
	static AcDbObjectId CreateLiney( double r, double c);

};

