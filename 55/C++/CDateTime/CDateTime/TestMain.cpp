#include"CDateTime.h"

void main()
{
	CDateTime dt;
	dt._ShowMenology(2020, 3);
	//cout<<dt.GetWeekByYMD(2019,8,6)<<endl;
}

/*
int main()
{
	CDateTime dt;
	int select = 1;
	while(select)
	{
		cout<<"*****************************************"<<endl;
		cout<<"* [1] ��ʾ����ʱ��    [0] �˳�ϵͳ      *"<<endl;
		cout<<"* [3] ��̬��ʾ        [4] ��ʾ����      *"<<endl;
		cout<<"* [5] ��һ��          [6] ��һ��        *"<<endl;
		cout<<"* [7] N���           [8] N��ǰ         *"<<endl;
		cout<<"*****************************************"<<endl;
		cout<<"��ѡ��:>";
		cin>>select;
		switch(select)
		{
		case 1:
			dt.DateTimeShow();
			break;
		case 3:
			dt.DateTimeDShow();
			break;
		case 4:
			dt.ShowMenology();
			break;
		}
	}

	return 0;
}
*/