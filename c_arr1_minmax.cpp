#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int *maxmin(int *a, int len)
{
	int *res, max, min, i;
	res = (int *)calloc(2, sizeof(int));
	if (a[0] > a[1])
	{
		max = a[0];
		min = a[1];//placing max and min
	}
	else
	{
		max = a[1];
		min = a[0];
	}
	for (i = 2; i < len; i++)//finiding maax and min
	{
		if (a[i]>max)
		{
			max = a[i];
		}
		else if (a[i]<min)
		{
			min = a[i];
		}
	}
	res[0] = max;//placing max and min in res
	res[1] = min;
	return res;

}
char *convert(char *str, int i, int res)
{
	int temp, temp1 = 1;
	bool t = 0, a = 0;
	temp = res;
	if (temp < 0)
	{
		a = 1;
		temp = (-1)*temp;
		res = (-1)*res;
	}
	while (temp != 0)
	{
		temp = temp / 10;
		temp1 = temp1 * 10;
		t = 1;
	}
	str = (char *)realloc(str, sizeof(char)* 25);//converting number to string 
	if (a == 1)
	{
		str[i++] = '-';
	}
	while (temp1 != 1)
	{
		str[i++] = ((res * 10) / temp1) % 10 + '0';
		temp1 = temp1 / 10;
	}

	if (t == 0)
	{
		str[i++] = 0 + '0';
	}
	str[i] = '\0';
	return str;
}
char *res(int *a, int len)//result function
{
	int *res, i = 0, count = 0;
	bool t = 0;
	char *str;
	str = (char *)malloc(sizeof(char)* 100);
	res = maxmin(a, len);//to find min max
	if (len >= 2)
	{
		if (res[0] == res[1])//if equal
		{


			str[i++] = 'm'; str[i++] = 'a'; str[i++] = 'x'; str[i++] = ' '; str[i++] = 'm';
			str[i++] = 'i'; str[i++] = 'n'; str[i++] = ' '; str[i++] = 'a'; str[i++] = 'r';
			str[i++] = 'e'; str[i++] = ' '; str[i++] = 's'; str[i++] = 'a'; str[i++] = 'm'; str[i++] = 'e';
			str = convert(str, i, res[0]);
			if (res[0] == 0)
			{
				str[17] = '\0';
			}
			return str;
		}
		else//if len>=2 and min and max not equal
		{
			str[i++] = 'm'; str[i++] = 'a'; str[i++] = 'x'; str[i++] = ' '; str[i++] = 'm';
			str[i++] = 'i'; str[i++] = 'n'; str[i++] = ' '; str[i++] = 'a'; str[i++] = 'r';
			str[i++] = 'e';
			convert(str, i, res[0]);
			if (res[0] < 0)
			{
				res[0] = (-1)*res[0];
				t = 1;
			}
			if (res[0] == 0)
			{
				i++;
			}
			while (res[0] != 0)
			{
				res[0] = res[0] / 10;
				count++;
			}
			str[i + count + t] = ' ';
			return convert(str, i + count + 1 + t, res[1]);
		}
	}
	else if (len == 1)// if length 1 no min only max
	{
		str[i++] = 'n'; str[i++] = 'o'; str[i++] = ' '; str[i++] = 'm'; str[i++] = 'i';
		str[i++] = 'n'; str[i++] = ' '; str[i++] = 'm'; str[i++] = 'a'; str[i++] = 'x';
		str[i++] = ' '; str[i++] = 'i'; str[i++] = 's';
		return convert(str, i, res[0]);
	}
	else// if length 0
	{
		return "no max no min";
	}

}

void main()
{
	int *a, len, i;
	printf("enter the length");
	scanf("%d", &len);
	printf("enter the array numbers");
	a = (int *)malloc(sizeof(int)*len);
	for (i = 0; i < len; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("%s", res(a, len));
	_getch();
}