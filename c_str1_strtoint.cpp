#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
int stringtoint(char *str, int len)
{
	int i=0,res=0;
	bool t = 0;
	if (str&&len > 0)
	{
		if (str[0]=='-')//if negative
		{
			t = 1;
		}
		while (str[i] != '\0')
		{
			if ((str[i] >= 0 + '0') && (str[i] <= 9 + '0') && (t == 0 || i != 0))
			{
				res = res * 10 + (str[i] - '0');//placing in res->result
			}
			else if (str[i] != '-'&&i==0)
			{
				return NULL;
			}
			i++;
		}
		if (t == 1)
		{
			res = res*(-1);//for  negative
		}
		return res;
	}
	else
	{
		return NULL;
	}
}
void main()
{
	char *str;
	int len;
	printf("enter the length of string");
	scanf("%d", &len);
	str = (char *)malloc(sizeof(char)*len);
	printf("enter the string");
	scanf("%s", str);
	printf("%d", stringtoint(str, len));
	_getch();
}