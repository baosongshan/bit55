#include<iostream>
#include<string>
#include<fstream>
using namespace std;

void main()
{
	char *str = "-12 345";
	int value = atoi(str);
	cout<<value<<endl;
}

/*
void Test()
{
	for(int i=1; i<=9; ++i)
	{
		for(int j=1; j<=i; ++j)
		{
			printf("%d*%d = %d  ", i, j, i*j);
		}
		printf("\n");
	}
}

void main()
{
	int ar[] = {1234,23,34,45,56,67,78,89,90,100};
	int n = sizeof(ar) / sizeof(int);

	for(int i=0; i<n; ++i)
	{
		cout.width(5);
		cout.flags(ios::left);
		cout<<ar[i];
	}
	//Test();
	cout<<endl;
}

/*
void main()
{
	int num = 1234;
	cout<<num<<endl;

	cout.flags(ios::hex | ios::uppercase |ios::showbase);
	cout<<num<<endl;
	//cout<<hex<<"0x"<<num<<endl;
}

/*
typedef struct ServerInfo
{
	char _ip[16]; // 192.168.xxx.xxx
	short _port;
}ServerInfo;

class ConfigManager
{
public:
	ConfigManager(const string &congfile) : configfile(congfile)
	{
		ifstream ifile(configfile.c_str(), ios::in);
		if(!ifile)
			return;

		ifile>>ser_info._ip;
		ifile>>ser_info._port;
		ifile>>count;

		ifile.close();
	}
	~ConfigManager()
	{
		ofstream ofile(configfile.c_str(), ios::out);
		if(!ofile)
			return;

		//ofile<<info._ip<<":"<<info._port<<endl;
		ofile<<ser_info._ip<<endl;
		ofile<<ser_info._port<<endl;
		ofile<<count<<endl;

		ofile.close();
	}
public:
	void Connect()
	{
		count++;
	}
	int GetConnectCount()const
	{return count;}
public:
	void TestWrite(const ServerInfo &info)
	{
		ofstream ofile(configfile.c_str(), ios::out);
		if(!ofile)
			return;

		//ofile<<info._ip<<":"<<info._port<<endl;
		ofile<<info._ip<<endl;
		ofile<<info._port<<endl;

		ofile.close();
	}
	void TestRead(ServerInfo &info)
	{
		ifstream ifile(configfile.c_str(), ios::in);
		if(!ifile)
			return;

		ifile>>info._ip;
		ifile>>info._port;

		ifile.close();
	}
private:
	ServerInfo ser_info;
	string configfile;
	static int count;
};

int ConfigManager::count = 0;

void main()
{
	//192.168.0.100
	//8080
	string config("ServerInfo.ini");
	ConfigManager server(config);
	server.Connect();
	server.Connect();
	cout<<"Server Connect Count = "<<server.GetConnectCount()<<endl;
	server.Connect();
	server.Connect();

	cout<<"Server Connect Count = "<<server.GetConnectCount()<<endl;

}


/*
typedef struct ServerInfo
{
	char _ip[16]; // 192.168.xxx.xxx
	short _port;
}ServerInfo;

class ConfigManager
{
public:
	ConfigManager(const string &congfile) : configfile(congfile)
	{}
public:
	void TestWrite(const ServerInfo &info)
	{
		ofstream ofile(configfile.c_str(), ios::out);
		if(!ofile)
			return;

		//ofile<<info._ip<<":"<<info._port<<endl;
		ofile<<info._ip<<endl;
		ofile<<info._port<<endl;

		ofile.close();
	}
	void TestRead(ServerInfo &info)
	{
		ifstream ifile(configfile.c_str(), ios::in);
		if(!ifile)
			return;

		ifile>>info._ip;
		ifile>>info._port;

		ifile.close();
	}
private:
	string configfile;
};

void main()
{
	string config("ServerInfo.ini");
	ConfigManager cm(config);

	ServerInfo info={"192.168.0.100", 8080};
	ServerInfo tmp;
	//cm.TestWrite(info);
	cm.TestRead(tmp);
}

/*
void main()
{
	FILE *fp = fopen("Test1.txt","r");
	int pos = 1;
	int value;
	while(1)
	{
		cout<<"input pos:>";
		cin>>pos;

		fseek(fp, pos*3, SEEK_SET);
		fscanf(fp, "%d", &value);
		printf("value = %d\n", value);

	}
	fclose(fp);
}

void TestCWrite(int ar[], int n)
{
	FILE *fp = fopen("Test1.txt", "w");
	if(fp == NULL)
	{
		return;
	}

	for(int i=0; i<n; ++i)
	{
		fprintf(fp, "%d ", ar[i]);
	}

	fclose(fp);
}

void TestCRead(int ar[], int n)
{
	FILE *fp = fopen("Test1.txt", "r");
	if(fp == NULL)
		return;

	for(int i=0; i<n; ++i)
	{
		fscanf(fp, "%d", &ar[i]);
	}

	fclose(fp);
}

void TestCppWrite(int ar[], int n)
{
	//ofstream ofile;  //1
	//ofile.open("Test2.txt", ios::out);  //2

	ofstream ofile("Test3.txt", ios::out);

	if(!ofile)
	{
		cout<<"Open File Error."<<endl;
		return;
	}

	for(int i=0; i<n; ++i)
	{
		ofile<<ar[i]<<" ";  //3
	}

	ofile.close();     //4
}

void TestCppRead(int ar[], int n)
{
	ifstream ifile;
	ifile.open("Test2.txt", ios::in);
	if(!ifile)
		return;

	for(int i=0; i<n; ++i)
	{
		ifile>>ar[i];
	}

	ifile.close();
}

//////////////////////////////////////////////////////////
//二进制文件
void TestCBinWrite(int ar[], int n)
{
	FILE *fp = fopen("Test3.txt", "wb");
	if(fp == NULL)
	{
		return;
	}
	fwrite(ar, sizeof(int), n, fp); //C
	fclose(fp);
}

void TestCBinRead(int ar[], int n)
{
	FILE *fp = fopen("Test3.txt", "rb");
	if(fp == NULL)
		return;

	fread(ar, sizeof(int), n, fp);

	fclose(fp);
}

void TestCppBinWrite(int ar[], int n)
{
	//ofstream ofile;  //1
	//ofile.open("Test2.txt", ios::out);  //2

	ofstream ofile("Test4.txt", ios::out|ios::binary);

	if(!ofile)
	{
		cout<<"Open File Error."<<endl;
		return;
	}

	ofile.write((const char*)ar, sizeof(int)*n);

	ofile.close();     //4
}

void TestCppBinRead(int ar[], int n)
{
	ifstream ifile;
	ifile.open("Test4.txt", ios::in|ios::binary);
	if(!ifile)
		return;

	ifile.read((char*)ar, sizeof(int)*n);

	ifile.close();
}

void main()
{
	int ar[] = {12,23,34,45,56,67,78,89,90,100};
	int n = sizeof(ar) / sizeof(int);
	//TestCWrite(ar, n);
	//TestCppWrite(ar, n);

	int br[10];
	int cr[10];
	//TestCRead(br, 10);
	//TestCppRead(cr, 10);

	//TestCBinWrite(ar, n);
	//TestCppBinWrite(ar, n);

	TestCBinRead(br, 10);
	TestCppBinRead(cr, 10);

}
*/