#include"NextDate.h"
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
using namespace std;
string TellNextDate(int year,int month, int day)
{
	int toYear, toMonth, toDay;
	toYear = year;
	toMonth = month;
	toDay = day;
	int caseMonth[12] = {1,4,1,2,1,2,1,1,2,1,2,3};
	bool invalid = false;	
	switch (caseMonth[month])
	{
	case 1:
	if(day<31&&day>0)
	{
		toDay = day+1;
		
	}
	else if(day==31)
	{
		toDay = 1;
		toMonth = month+1;
	}
	else
	{
		invalid = true;
	}
	
	break;
	case 2:
	if(day<30&&day>0)
	{
		toDay = day+1;
		
	}
	else if(day==30)
	{
		toDay = 1;
		toMonth = month+1;
	}
	else
	{
		invalid = true;
	}
	
	break;
	case 3:
	if(day<31&&day>0)
	{
		toDay = day+1;
	}
	else if(day==31)
	{
		toMonth = 1;
		toDay  = 1;
		toYear = year+1;
	}
	else
	{
		invalid = true;
	}
	if(year==2012)
	{
		invalid = true;
	}
	break;
	case 4:
	if(day<28&&day>0)
	{
		toDay = day+1;
	}
	else if(day==28)
	{
		if((year%4==0&&year%100!=0)||year%200==0)
		{
			toDay = 29;
		}
		else
		{
			toDay = 1;
			toMonth = 3;
		}	
	}
	else if(day==29)
	{
		if((year%4==0&&year%100!=0)||year%200==0)
		{
			toDay = 1;
			toMonth = 3;
		}
		else
		{
			invalid = true;
		}	
		
	}
	else
	{
		invalid = true;
	}
	break;
	}
	char str[100];
	memset(str,0,sizeof(str));
	if(invalid==true)
	{
		return "Invalid Input";
	}
	else
	{
		sprintf(str,"%d/%d/%d",toYear,toMonth,toDay);
		string a(str);
		
		return a;
	}
	return "Error";
}
