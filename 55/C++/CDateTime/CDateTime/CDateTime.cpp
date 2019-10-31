#include"CDateTime.h"

#define ESC 0x1B

void HideCursor()
{
	HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO cursor_info = {1, 0};
	SetConsoleCursorInfo(hd, &cursor_info);
}
void ShowCursor()
{
	HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO cursor_info = {1, 1};
	SetConsoleCursorInfo(hd, &cursor_info);
}
CDateTime::CDateTime()
{
	m_date.year = 1;
	m_date.month = 1;
	m_date.day = 1;
	m_time.hour = 0;
	m_time.minute = 0;
	m_time.second = 0;
}

CDateTime::CDateTime(int year, int month, int day,int hour, int minute, int second)
{
	m_date.year = year;
	m_date.month = month;
	m_date.day = day;

	m_time.hour = hour;
	m_time.minute = minute;
	m_time.second = second;
}

CDateTime::~CDateTime()
{}

void CDateTime::GetCurDateTime()
{
	time_t te;
	time(&te);

	struct tm *ptm = localtime(&te);
	m_date.year = ptm->tm_year +1900;
	m_date.month = ptm->tm_mon + 1;
	m_date.day = ptm->tm_mday;
	m_time.hour = ptm->tm_hour;
	m_time.minute = ptm->tm_min;
	m_time.second = ptm->tm_sec;
}

void CDateTime::DateTimeShow()
{
	//GetCurDateTime();
	cout<<m_date.year<<"年"<<m_date.month<<"月"<<m_date.day<<"日"<<\
		m_time.hour<<"时"<<m_time.minute<<"分"<<m_time.second<<"秒"<<endl;
}

void CDateTime::DateTimeDShow()
{
	
	HideCursor();
	while(1)
	{
		if(_kbhit())
		{
			//ESC
			int val = getch();
			if(val == ESC)
				break;
		}
		GetCurDateTime();
		DateTimeShow();
		Sleep(1000);
		system("cls");
	}
	ShowCursor();
}

void CDateTime::ShowMenology()
{
	GetCurDateTime();
	_ShowMenology(m_date.year, m_date.month);
}
void CDateTime::_ShowMenology(int year, int month)
{
	char *title[] = {"一","二","三","四","五","六","日"};
	for(int i=0; i<7; ++i)
		printf("%-6s", title[i]);
	printf("\n");

	int mdays = GetMDayByYM(year, month);
	int week = GetWeekByYMD(year, month, 1);

	if(week == 0)
		week = 7;
	for(int i=0; i<week-1; ++i)
		printf("%-6c",' ');

	for(int i=1; i<=mdays; ++i)
	{
		printf("%-6d", i);
		int w = GetWeekByYMD(year, month, i);
		if(w == 0)
		{
			printf("\n");
			printf("\n");
		}
	}
	printf("\n");
}

bool CDateTime::IsLeap(int year)
{
	if((year%4==0&&year%100!=0) || (year%400==0))
		return true;
	return false;
}

int CDateTime::GetMDayByYM(int year, int month)
{
	                //1   2   3  4  5  6  7  8  9  10 11 12
	int days[] = {29,31,  28, 31,30,31,30,31,31,30,31,30,31};
	if(month == 2)
	{
		if(IsLeap(year))
			return days[0];
	}
	return days[month];
}

int CDateTime::GetWeekByYMD(int year, int month, int day)
{
	int count = 0;
	for(int i=1; i<month; ++i)
	{
		count += GetMDayByYM(year, i);
	}
	count += day;

	//蔡勒公式
	int x = (year-1)+(year-1)/4 - (year-1)/100+(year-1)/400 + count;
	return x % 7;
}

CDateTime CDateTime::NextDateTime(int n)  //10
{
	int y = m_date.year;   //2019
	int m = m_date.month;  //10
	int d = m_date.day;    //29

	int mday = GetMDayByYM(y, m);
	while(d+n > mday)
	{
		m++;
		if(m > 12)
		{
			m = 1;
			y++;
		}
		n -= mday;
		mday = GetMDayByYM(y, m);
	}
	d += n;

	return CDateTime(y, m, d, m_time.hour, m_time.minute, m_time.second);
}

CDateTime CDateTime::PrevDateTime(int n)
{
	//
}