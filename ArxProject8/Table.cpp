#include "stdafx.h"
#include "Table.h"
#include"string"
#include"INDEX.h"
#include"Tool.h"
using namespace std;



double x = 650;
double y = 276;
void Table::Init()
{
   
  
}

void Table::Unload()
{
    acedRegCmds->removeGroup(_T("g1"));

}
AcDbObjectId Table::CreateLinex(int i,double width,double cellHeight) //绘制直线
{
        AcDbLine* pLine1 = new AcDbLine();
        // 设置起点和终点
        pLine1->setStartPoint(AcGePoint3d(x, y + i * cellHeight, 0.0));
        pLine1->setEndPoint(AcGePoint3d(x + width, y + i * cellHeight, 0.0));
        return Tool::AddToModeSpace(pLine1);

    }
AcDbObjectId Table::CreateLiney( double width, double Height) //绘制直线
{
    AcDbLine* pLine2 = new AcDbLine();
    // 设置起点和终点
    pLine2->setStartPoint(AcGePoint3d(x +  width,y ,  0.0));
    pLine2->setEndPoint(AcGePoint3d(x + width,y + Height, 0.0));
    return Tool::AddToModeSpace(pLine2);
}


void Table::CreateTable()
{
    
    for (int i = 0; i <= 9; i++)   //绘制表格
    {
        AcDbObjectId id = CreateLinex(i, 180, 14);
        if (i == 0)
           Tool:: Changeline50(id);
        else
            Tool::Changeline25(id);
    };

        AcDbObjectId id1 = CreateLiney(0, 308);//表格左侧粗实线
        Tool::Changeline50(id1);
        AcDbObjectId id2 = CreateLiney(80, 308);
        Tool::Changeline25(id2);
        AcDbObjectId id3 = CreateLiney(120, 182);
        Tool::Changeline25(id3);
        AcDbObjectId id4 = CreateLiney(180, 308);
        Tool::Changeline50(id4);
        y = 402;
        for (int i = 0; i <= 3; i++)
        {
            AcDbObjectId id = CreateLinex(i, 180, 28);
            Tool::Changeline25(id);
        }
        y = 486;
        for (int i = 0; i <= 7; i++)
        {
            AcDbObjectId id = CreateLinex(i, 180, 14);
            Tool::Changeline25(id);
        }
        x = 730;
        y = 416;
        AcDbObjectId id = CreateLinex(0, 100, 0);
        Tool::Changeline25(id);
        y = 486;
        AcDbObjectId id5 = CreateLiney(40, 98);
        Tool::Changeline25(id5);
        Tool::Write();//绘制表格文字
}
