#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
	int* p = NULL;
	int a = 12;
	p = &a;
	return 0;
}


//------------------
//official answer

int main()
{
	int* p = new int;
	*p = 42;
	delete p;
	return 0;
}


