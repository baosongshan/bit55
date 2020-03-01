#include<iostream>
#include"Everything.h"
using namespace std;

void main()
{
	Everything_SetMatchCase(TRUE);
	Everything_SetSearch("shejimoshi");
	Everything_Query(TRUE);
	
	DWORD i;
		
	for(i=0;i<Everything_GetNumResults();i++)
	{
		cout << Everything_GetResultFileName(i) << "\n";
	}
	
}