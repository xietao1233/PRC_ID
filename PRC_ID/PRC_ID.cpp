// RPC_ID.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Citys.h"
#include "PeopleId.h"

unsigned int iRandom = 0;


void InitRandom()
{
	unsigned int iTid = GetCurrentThreadId(), iPid = GetCurrentProcessId();
	unsigned int iValue = (unsigned int)GetModuleHandle(NULL);
	srand((unsigned int)time(NULL));

	iRandom = (iValue >> 16) + (iTid >> 2) + (iPid >> 2);
}

unsigned int Random(unsigned int iStart, unsigned int iEnd)
{
	unsigned int iValue = iEnd - iStart + 1;
	iRandom += rand();

	return ((unsigned int)(iRandom % iValue) + iStart);
}

int _tmain(int argc, _TCHAR* argv[])
{
	CPeopleId pi;

	//printf("µØÖ·: %s - %s\nCode = %d%d%02d%02d%d%d1\n", p->province_name, p->city_name, p->city_id, dwYear, dwMonth, dwDay, Random(0, 2), Random(0, 9));
	printf("%s ÐÔ±ð: %d\n %s\n", pi.Address.c_str(), pi.Female, pi.GetPeopleId().c_str());

	system("pause");

	return 0;
}

