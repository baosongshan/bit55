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
	GetCurDateTime();
	cout<<m_date.year<<"��"<<m_date.month<<"��"<<m_date.day<<"��"<<\
		m_time.hour<<"ʱ"<<m_time.minute<<"��"<<m_time.second<<"��"<<endl;
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