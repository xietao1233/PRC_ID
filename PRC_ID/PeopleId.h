#pragma once

#include "stdafx.h"
#include <string>


class CPeopleId
{
public:
	CPeopleId();
	~CPeopleId();

	std::string GetPeopleId();

	std::string Address;
	unsigned int RegionId;
	unsigned int Year;
	unsigned char Month;
	unsigned char Day;
	bool Female;
	unsigned char RandomValue1;
	unsigned char RandomValue2;
	unsigned char SexValue;
	unsigned char CheckValue;

private:
	unsigned int RandomSeed;

	std::string GetCityName(unsigned int region_id);
	void RandomId();
	void InitRandom();
	unsigned int Random(unsigned int iStart, unsigned int iEnd);
	void RandomRegion();
	void RandomBirthDay();
	void RandomSexValue();
	void SetCheckValue(std::string strId);
};

