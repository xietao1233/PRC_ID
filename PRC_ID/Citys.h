#include "stdafx.h"

typedef struct tagProvinceData
{
	unsigned int id;
	const char* name;
	bool enable;		//是否启用该省名
}PROVINCEDATA, *PPROVINCEDATA;

typedef struct tagCityData
{
	unsigned int id;
	const char* name;
	unsigned int province_index;
	bool enable;		//是否启用该地区名
}CITYDATA, *PCITYDATA;

typedef struct tagCountyData
{
	unsigned int id;
	const char* name;
	PCITYDATA* city_info;
	bool enable;		//是否启用该区县名
	bool county_name;		//是否是个区县名
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
