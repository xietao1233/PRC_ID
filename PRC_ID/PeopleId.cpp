#include "stdafx.h"
#include "PeopleId.h"
#include "Citys.h"
#include <sstream>


CPeopleId::CPeopleId()
{
	InitRandom();

}

CPeopleId::~CPeopleId()
{
}

void CPeopleId::RandomId()
{
	RandomRegion();
	RandomBirthDay();
	RandomValue1 = Random(0, 2);
	RandomValue2 = Random(0, 9);
	RandomSexValue();

}

void CPeopleId::InitRandom()
{
	srand((unsigned int)time(NULL));

	RandomSeed = (unsigned int)time(NULL);
}

unsigned int CPeopleId::Random(unsigned int iStart, unsigned int iEnd)
{
	unsigned int iValue = iEnd - iStart + 1;
	RandomSeed += rand();

	return ((unsigned int)(RandomSeed % iValue) + iStart);
}

void CPeopleId::RandomRegion()
{
	REGIONDATA *p = NULL;

	do 
	{
		p = &stRegionData[Random(0, GetCitysCount() - 1)];
	} while (!p->is_city_name);

	Address = p->province_name;
	Address += " - ";
	Address += GetCityName(p->city_id);
	Address += " - ";
	Address += p->city_name;
	RegionId = p->city_id;
}

void CPeopleId::RandomBirthDay()
{
	Year = Random(1960, 1997);
	Month = Random(1, 12);
	Day = Random(1, 28);
}

void CPeopleId::RandomSexValue()
{
	unsigned char arrMale[] = { 1, 3, 5, 7 };
	unsigned char arrFemale[] = { 2, 4, 6, 8 };

	Female = Random(0, 1) ? true : false;
	if (!Female)
		SexValue = arrMale[Random(0, 3)];
	else
		SexValue = arrFemale[Random(0, 3)];
}

std::string CPeopleId::GetPeopleId()
{
	std::ostringstream os;
	char szBuff[0x20] = { 0 };

	RandomId();
	os << RegionId;

	sprintf_s(szBuff, 0x20, "%04d%02d%02d%d%d%d", Year, Month, Day, RandomValue1, RandomValue2, SexValue);
	os << szBuff;

	SetCheckValue(os.str());
	os << CheckValue;

	return os.str();
}

void CPeopleId::SetCheckValue(std::string strId)
{
	unsigned char arrBase[] = { 7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2 };
	unsigned char arrRe[] = { '1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2' };
	unsigned int iCheck = 0, iIndex = 0;

	for each (auto c in strId)
	{
		iCheck += ((c - 0x30) * arrBase[iIndex]);
		iIndex++;
	}
	CheckValue = arrRe[iCheck % 11];
}

std::string CPeopleId::GetCityName(unsigned int region_id)
{
	std::string strResult;
	char szBuff[0x10] = { 0 };

	sprintf_s(szBuff, 0x10, "%d", region_id);
	szBuff[4] = 0x30;
	szBuff[5] = 0x30;
	region_id = strtol(szBuff, 0, 10);

	for (unsigned int i = 0; i < GetCitysCount(); i++)
	{
		if (region_id == stRegionData[i].city_id)
		{
			strResult = stRegionData[i].city_name;
			break;
		}
	}

	return strResult;
}
