#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int findelement(int *a)
{
	int i, res = 0;
	for (i = 0; i <500; i++)
	{
		res = res + a[i];
	}
	return (500 * (500 + 1) / 2) - res;
}
void main()
{
	int *a, i;
	printf("enter 500 eements");
	a = (int *)malloc(sizeof(int)* 500);
	for (i = 0; i <500; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("%d", findelement(a));
	_getch();
}