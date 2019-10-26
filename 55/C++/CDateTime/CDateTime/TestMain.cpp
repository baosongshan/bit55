#include"CDateTime.h"

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
		}
	}

	return 0;
}