#include "stdafx.h"
#include"INDEX.h"
using namespace std;

extern INDEX* pDialog;
void Tool::Changeline50(AcDbObjectId LineId)
{
    AcDbEntity* pEnt1;
    if (acdbOpenObject(pEnt1, LineId, AcDb::kForWrite) == Acad::eOk)
    {
        // 设置直线的线条粗细为40毫米
        pEnt1->setLineWeight(AcDb::kLnWt040);
        // 关闭直线对象
        pEnt1->close();
    }
}
void Tool::Changeline25(AcDbObjectId LineId)
{
    AcDbEntity* pEnt2;
    if (acdbOpenObject(pEnt2, LineId, AcDb::kForWrite) == Acad::eOk)
    {
        // 设置直线的线条粗细为25毫米
        pEnt2->setLineWeight(AcDb::kLnWt025);
        // 关闭直线对象
        pEnt2->close();
    }
}
void Tool::Write()
{
    for (int i = 0; i <= 6; i++)
    {
        std::string strA[7] = { "模数","齿数","齿形角","齿顶高系数" ,"全齿高" ,"径向变位系数","齿厚" };
        string str = strA[i];
        ACHAR* ach;
        USES_CONVERSION;
        ach = (ACHAR*)A2CT(str.c_str());
        AcDbMText* pMText = new AcDbMText;
        pMText->setTextStyle(AcDbObjectId::kNull);
        pMText->setContents(ach);
        AcGePoint3d pMTextOrigin(690, 577 - i * 14, 0);
        pMText->setLocation(pMTextOrigin);
        pMText->setWidth(80);
        pMText->setTextHeight(6);
        pMText->setAttachment(AcDbMText::kMiddleCenter);
        Tool::AddToModeSpace(pMText);
    }
    for (int i = 0; i <= 6; i++)
    {
        string strB[7] = { "m","z","α","han" ,"h" ,"x","s" };
        string str = strB[i];
        ACHAR* ach;
        USES_CONVERSION;
        ach = (ACHAR*)A2CT(str.c_str());
        AcDbMText* pMText = new AcDbMText;
        pMText->setTextStyle(AcDbObjectId::kNull);
        pMText->setContents(ach);
        AcGePoint3d pMTextOrigin(750, 577 - i * 14, 0);
        pMText->setLocation(pMTextOrigin);
        pMText->setWidth(40);
        pMText->setTextHeight(6);
        pMText->setAttachment(AcDbMText::kMiddleCenter);
        Tool::AddToModeSpace(pMText);
    }
    for (int i = 0; i <= 6; i++) //
    {
        //string strA[7] = { "模数","齿数","齿形角","齿顶高系数" ,"全齿高" ,"径向变位系数","齿厚"};
        string strC[7] = { " "," "," "," " ," " ," "," " };
        string str = strC[i];
        ACHAR* ach;
        USES_CONVERSION;
        ach = (ACHAR*)A2CT(str.c_str());
        AcDbMText* pMText = new AcDbMText;
        pMText->setTextStyle(AcDbObjectId::kNull);
        pMText->setContents(ach);
        AcGePoint3d pMTextOrigin(800, 577 - i * 14, 0);
        pMText->setLocation(pMTextOrigin);
        pMText->setWidth(60);
        pMText->setTextHeight(6);
        pMText->setAttachment(AcDbMText::kMiddleCenter);
        Tool::AddToModeSpace(pMText);
    }
    for (int i = 0; i <= 2; i++)
    {
        string strD[3] = { "精度等级（GB/T10095-2008）","跨距（公法线长度）及上下偏差","配对齿轮" };
        string str = strD[i];
        ACHAR* ach;
        USES_CONVERSION;
        ach = (ACHAR*)A2CT(str.c_str());
        AcDbMText* pMText = new AcDbMText;
        pMText->setTextStyle(AcDbObjectId::kNull);
        pMText->setContents(ach);
        AcGePoint3d pMTextOrigin(690, 472 - i * 28, 0);
        pMText->setLocation(pMTextOrigin);
        pMText->setWidth(80);
        pMText->setTextHeight(6);
        pMText->setAttachment(AcDbMText::kMiddleCenter);
        Tool::AddToModeSpace(pMText);
    }
    for (int i = 0; i <= 8; i++)
    {
        string strE[9] = { "跨测齿数","检验项目","单个齿距偏差","齿距累积总偏差","齿廓计值范围","齿廓总偏差","螺旋线计值范围","螺旋线总偏差","径向跳动" };
        string str = strE[i];
        ACHAR* ach;
        USES_CONVERSION;
        ach = (ACHAR*)A2CT(str.c_str());
        AcDbMText* pMText = new AcDbMText;
        pMText->setTextStyle(AcDbObjectId::kNull);
        pMText->setContents(ach);
        AcGePoint3d pMTextOrigin(690, 395 - i * 14, 0);
        pMText->setLocation(pMTextOrigin);
        pMText->setWidth(80);
        pMText->setTextHeight(6);
        pMText->setAttachment(AcDbMText::kMiddleCenter);
        Tool::AddToModeSpace(pMText);
    }



    for (int i = 0; i <= 10; i++)
    {
        string strF[11] = { "图号","齿数","K","代号","±fpt","Fp","Lα","Fα","Lβ","Fβ","Fγ" };
        string str = strF[i];
        ACHAR* ach;
        USES_CONVERSION;
        ach = (ACHAR*)A2CT(str.c_str());
        AcDbMText* pMText = new AcDbMText;
        pMText->setTextStyle(AcDbObjectId::kNull);
        pMText->setContents(ach);
        AcGePoint3d pMTextOrigin(750, 423 - i * 14, 0);
        pMText->setLocation(pMTextOrigin);
        pMText->setWidth(40);
        pMText->setTextHeight(6);
        pMText->setAttachment(AcDbMText::kMiddleCenter);
        Tool::AddToModeSpace(pMText);
    }
    for (int i = 0; i <= 10; i++)
    {
        //"图号"，"齿数"，"跨测齿数","检验项目","单个齿距偏差","齿距累积总偏差","齿廓计值范围","齿廓总偏差","螺旋线计值范围","螺旋线总偏差","径向跳动"
        string strG[11] = { " " ," ", " ","允许值/mm"," "," "," "," "," "," "," " };
        string str = strG[i];
        ACHAR* ach;
        USES_CONVERSION;
        ach = (ACHAR*)A2CT(str.c_str());
        AcDbMText* pMText = new AcDbMText;
        pMText->setTextStyle(AcDbObjectId::kNull);
        pMText->setContents(ach);
        AcGePoint3d pMTextOrigin(800, 423 - i * 14, 0);
        pMText->setLocation(pMTextOrigin);
        pMText->setWidth(60);
        pMText->setTextHeight(6);
        pMText->setAttachment(AcDbMText::kMiddleCenter);
        Tool::AddToModeSpace(pMText);
    }
    AcDbMText* pMText = new AcDbMText;  //精度等级（GB/T10095-2008）
    pMText->setTextStyle(AcDbObjectId::kNull);
    pMText->setContents(TEXT(""));
    AcGePoint3d pMTextOrigin1(780, 472, 0);
    pMText->setLocation(pMTextOrigin1);
    pMText->setWidth(100);
    pMText->setTextHeight(6);
    pMText->setAttachment(AcDbMText::kMiddleCenter);
    Tool::AddToModeSpace(pMText);

    AcDbMText* pMText1 = new AcDbMText;//"跨距（公法线长度）及上下偏差"
    pMText1->setTextStyle(AcDbObjectId::kNull);
    pMText1->setContents(TEXT(""));
    AcGePoint3d pMTextOrigin2(750, 444, 0);
    pMText1->setLocation(pMTextOrigin2);
    pMText1->setWidth(40);
    pMText1->setTextHeight(6);
    pMText1->setAttachment(AcDbMText::kMiddleCenter);
    Tool::AddToModeSpace(pMText1);

    AcDbMText* pMText2 = new AcDbMText;//"配对齿轮" 
    pMText2->setTextStyle(AcDbObjectId::kNull);
    pMText2->setContents(TEXT(" "));
    AcGePoint3d pMTextOrigin3(800, 444, 0);
    pMText2->setLocation(pMTextOrigin3);
    pMText2->setWidth(60);
    pMText2->setTextHeight(6);
    pMText2->setAttachment(AcDbMText::kMiddleCenter);
    Tool::AddToModeSpace(pMText2);
}
AcDbObjectId Tool::AddToModeSpace(AcDbEntity* pEnt)
{

    AcDbBlockTable* pBT1 = new AcDbBlockTable;


    acdbHostApplicationServices()->workingDatabase()->getBlockTable(pBT1, AcDb::kForRead);

    AcDbBlockTableRecord* pBT1Rcd = new AcDbBlockTableRecord;


    pBT1->getAt(ACDB_MODEL_SPACE, pBT1Rcd, AcDb::kForWrite);
    AcDbObjectId LineId;

    pBT1Rcd->appendAcDbEntity(LineId, pEnt);

    pBT1->close();
    pBT1Rcd->close();
    pEnt->close();
    return LineId;
}