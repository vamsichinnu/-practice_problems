#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
void mergesort(int *input1, int min, int mid, int max)
{
	int *temp;
	int i, j, k, m;
	j = min;
	m = mid + 1;
	temp = (int *)malloc(sizeof(int)*30);
	for (i = min; j <= mid && m <= max; i++)
	{
		if (input1[j]<= input1[m])
		{
			temp[i] = input1[j];
			j++;
		}
		else
		{
			temp[i] =input1[m];
			m++;
		}
	}
	if (j>mid)
	{
		for (k = m; k <= max; k++)
		{
			temp[i] = input1[k];
			i++;
		}
	}
	else
	{
		for (k = j; k <= mid; k++)
		{
			temp[i] = input1[k];
			i++;
		}
	}
	for (k = min; k <= max; k++)
		input1[k] = temp[k];
}
void divide(int *input1, int min, int max)
{
	int mid;
	if (min<max)
	{
		mid = (min + max) / 2;
		divide(input1, min, mid);
		divide(input1, mid + 1, max);
		mergesort(input1, min, mid, max);
	}
}
int binarysearch(int *input1, int check, int len1)
{
	int i = 0, j = len1 - 1,mid;
	mid = i + j / 2;
	while (i <=j)
	{
		if (input1[mid] == check)
		{
			return 1;
		}
		else if (input1[mid]>check)
		{
			j = mid-1;
		}
		else
		{
			i = mid + 1;
		}
		mid = i + j / 2;
	}
	return 0;

}
int check(int ref, int *res, int k)
{
	int i;
	for (i = 1; i<k; i++)
	{
		if (ref == res[i])
		{
			return 0;
		}
	}
	return 1;
}
int *commonelements(int *input1,int *input2,int len2,int len1) {
	int i,k=1,*res;
	res = (int *)malloc(sizeof(int)*1);
	if (len1 > 0&&len2>0)
	{

			divide(input1, 0, len1 - 1);
			for (i = 0; i < len2; i++)
			{
				if (check(input2[i], res, k) == 1)
				{
					if (binarysearch(input1, input2[i], len1) == 1)
					{
						res = (int *)realloc(res, sizeof(int)*(k + 1));
						res[k] = input2[i];
						k++;
					}
				}
			}
			res[0] = k-1;
			return res;
	}
	else
	{
		res[1] = '\0';
		return res;
	}
	
}
void main()
{
	int *input1, *input2,*res;
	int len1, len2,i;
	printf("enter the length1");
	scanf("%d", &len1);
	printf("enter the len2");
	scanf("%d", &len2);
	input1 = (int *)malloc(sizeof(int)*len1);
	input2 = (int *)malloc(sizeof(int)*len2);
	printf("enter input1");
	for (i = 0; i < len1; i++)
	{
		scanf("%d", &input1[i]);
	}
	printf("enter input2");
	for (i = 0; i < len2; i++)
	{
		scanf("%d", &input2[i]);
	}
	res=commonelements(input1, input2, len2, len1);
	printf("result");
	for (i =1; i <= res[0]; i++)
	{
		printf("%d", res[i]);
	}
	_getch();
}