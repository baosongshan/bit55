#include<stdio.h>
#include<windows.h>
#include"Max.h"
#include"Min.h"
#include<assert.h>


int main()
{
	int a = 0;
	int b = 20;
		
	assert(a != 0);

	int max_value = Max(a, b);
	int min_value = Min(a, b);

	printf("max value = %d\n", max_value);
	printf("min value = %d\n", min_value);

	return 0;
}

#if 0
#define FUN

#undef FUN

#ifdef FUN
void fun1()
{
	printf("This is fun 1.\n");
}
#else
void fun1()
{
	printf("This is fun 2.\n");
}
#endif

void main()
{
	fun1();
}



/*

#define MAX(a, b) ((a) > (b) ? (a) : (b))
int main()
{
	int x = 5;
	int y = 8;
	int z = MAX(x++, y++); //z = ((x++) > (y++) ? (x++) : (y++));
	                       //z = 6 > 9
	printf("x = %d, y = %d, z = %d\n", x, y, z);
	     //
}

/*
#define SQUARE(n) printf(#n "*" #n "= %d\n", n*n)

void TestFun()
{
	/*printf("This is Test fun.\n");*/
}
#define MER(x1, x2) x1##x2

#define Student(name) struct \
{\
	char name[10];\
	int age; \
	char sex[3];\
}name##stu

int main()
{
	Student(zcy); //xxxstu

	zcystu.age = 10;

	return 0;
}

/*
//»’÷æ
#define DEFAULT_SIZE 10
#define Add(a, b) ((a)+(b))
#define Sub(a, b) ((a)-(b))
#define Mul(a, b) ((a)*(b))


#define ulong unsigned long

void log(const char *file, size_t line, const char *info)
{
	printf("file:[%s], line:[%d],[%s]\n",file, line, info);
}

#define Log(FORMAT) log(__FILE__, __LINE__, FORMAT)

int main()
{
	int ar[10];
	Log("start assign");
	for (int i = 0; i < 10; ++i)
	{
		ar[i] = i + 1;
		Sleep(1000);
	}
	Log("assign finish.");
	return 0;
}

/*
int main()
{
	int ar[10];
	log(__FILE__, __LINE__, "start assign");
	for (int i = 0; i < 10; ++i)
	{
		ar[i] = i + 1;
		Sleep(1000);
	}
	log(__FILE__, __LINE__, "assign finish.");
	return 0;
}

/*
int main()
{
	int ar[10];
	printf("file:[%s], line:[%d],[%s]\n",
		__FILE__, __LINE__, "start assign.");
	for (int i = 0; i < 10; ++i)
	{
		ar[i] = i + 1;
		Sleep(1000);
	}
	printf("file:[%s], line:[%d],[%s]\n",
		__FILE__, __LINE__, "assign finish.");
	return 0;
}

/*
int main()
{
	int sz = DEFAULT_SIZE;
	printf("%d\n", Add(10, 20));
	printf("%d\n", Sub(100, 20));
	printf("%d\n", Mul(Add(1,2), Add(2,3)));
	printf("%d\n", Add(1, 2)*Add(2, 3));
	               //(1+2)*(2+3)

	ulong value;
}

/*
int main()
{
	int sz = DEFAULT_SIZE;

	printf("file:%s\n", __FILE__);
	printf("line:%d\n", __LINE__);
	printf("line:%s\n", __DATE__);
	printf("line:%s\n", __TIME__);
	return 0;
}

/*
int main()
{
	int a = 10;
	int b = 20;

	int max_value = Max(a, b);
	int min_value = Min(a, b);

	printf("max value = %d\n", max_value);
	printf("min value = %d\n", min_value);

	//system("pause");
	return 0;
}
*/

#endif