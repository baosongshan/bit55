#ifndef _COMMON_H_
#define _COMMON_H_

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef enum{FALSE, TRUE} BOOL;

#define DataType char

#define DEFAULT_SIZE 8
#define INC_SIZE      3

void Swap(DataType *a, DataType *b)
{
	DataType tmp = *a;
	*a = *b;
	*b = tmp;
}

#endif /* _COMMON_H_ */