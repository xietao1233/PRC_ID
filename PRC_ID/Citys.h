#include "stdafx.h"

typedef struct tagProvinceData
{
	unsigned int id;
	const char* name;
	bool enable;		//�Ƿ����ø�ʡ��
}PROVINCEDATA, *PPROVINCEDATA;

typedef struct tagCityData
{
	unsigned int id;
	const char* name;
	unsigned int province_index;
	bool enable;		//�Ƿ����øõ�����
}CITYDATA, *PCITYDATA;

typedef struct tagCountyData
{
	unsigned int id;
	const char* name;
	PCITYDATA* city_info;
	bool enable;		//�Ƿ����ø�������
	bool county_name;		//�Ƿ��Ǹ�������
}COUNTYDATA, *PCOUNTYDATA;

typedef struct tagRegionData
{
	unsigned int city_id;
	const char* province_name;
	const char* city_name;
	bool is_city_name;
}REGIONDATA, *PREGIONDATA;

extern PROVINCEDATA stProvincesCode[];
extern REGIONDATA stRegionData[];
extern unsigned int GetCitysCount();
