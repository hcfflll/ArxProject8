#include "stdafx.h"
#include"INDEX.h"
using namespace std;

extern INDEX* pDialog;
void Tool::Changeline50(AcDbObjectId LineId)
{
    AcDbEntity* pEnt1;
    if (acdbOpenObject(pEnt1, LineId, AcDb::kForWrite) == Acad::eOk)
    {
        // ����ֱ�ߵ�������ϸΪ40����
        pEnt1->setLineWeight(AcDb::kLnWt040);
        // �ر�ֱ�߶���
        pEnt1->close();
    }
}
void Tool::Changeline25(AcDbObjectId LineId)
{
    AcDbEntity* pEnt2;
    if (acdbOpenObject(pEnt2, LineId, AcDb::kForWrite) == Acad::eOk)
    {
        // ����ֱ�ߵ�������ϸΪ25����
        pEnt2->setLineWeight(AcDb::kLnWt025);
        // �ر�ֱ�߶���
        pEnt2->close();
    }
}
void Tool::Write()
{
    for (int i = 0; i <= 6; i++)
    {
        std::string strA[7] = { "ģ��","����","���ν�","�ݶ���ϵ��" ,"ȫ�ݸ�" ,"�����λϵ��","�ݺ�" };
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
        string strB[7] = { "m","z","��","han" ,"h" ,"x","s" };
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
        //string strA[7] = { "ģ��","����","���ν�","�ݶ���ϵ��" ,"ȫ�ݸ�" ,"�����λϵ��","�ݺ�"};
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
        string strD[3] = { "���ȵȼ���GB/T10095-2008��","��ࣨ�����߳��ȣ�������ƫ��","��Գ���" };
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
        string strE[9] = { "������","������Ŀ","�����ݾ�ƫ��","�ݾ��ۻ���ƫ��","������ֵ��Χ","������ƫ��","�����߼�ֵ��Χ","��������ƫ��","��������" };
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
        string strF[11] = { "ͼ��","����","K","����","��fpt","Fp","L��","F��","L��","F��","F��" };
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
        //"ͼ��"��"����"��"������","������Ŀ","�����ݾ�ƫ��","�ݾ��ۻ���ƫ��","������ֵ��Χ","������ƫ��","�����߼�ֵ��Χ","��������ƫ��","��������"
        string strG[11] = { " " ," ", " ","����ֵ/mm"," "," "," "," "," "," "," " };
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
    AcDbMText* pMText = new AcDbMText;  //���ȵȼ���GB/T10095-2008��
    pMText->setTextStyle(AcDbObjectId::kNull);
    pMText->setContents(TEXT(""));
    AcGePoint3d pMTextOrigin1(780, 472, 0);
    pMText->setLocation(pMTextOrigin1);
    pMText->setWidth(100);
    pMText->setTextHeight(6);
    pMText->setAttachment(AcDbMText::kMiddleCenter);
    Tool::AddToModeSpace(pMText);

    AcDbMText* pMText1 = new AcDbMText;//"��ࣨ�����߳��ȣ�������ƫ��"
    pMText1->setTextStyle(AcDbObjectId::kNull);
    pMText1->setContents(TEXT(""));
    AcGePoint3d pMTextOrigin2(750, 444, 0);
    pMText1->setLocation(pMTextOrigin2);
    pMText1->setWidth(40);
    pMText1->setTextHeight(6);
    pMText1->setAttachment(AcDbMText::kMiddleCenter);
    Tool::AddToModeSpace(pMText1);

    AcDbMText* pMText2 = new AcDbMText;//"��Գ���" 
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