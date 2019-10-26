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
		cout<<"* [1] 显示日期时间    [0] 退出系统      *"<<endl;
		cout<<"* [3] 动态显示        [4] 显示月历      *"<<endl;
		cout<<"* [5] 上一天          [6] 下一天        *"<<endl;
		cout<<"* [7] N天后           [8] N天前         *"<<endl;
		cout<<"*****************************************"<<endl;
		cout<<"请选择:>";
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