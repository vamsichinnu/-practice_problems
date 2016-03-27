#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
void swap(int j, int i,char *str)
{
	str[j] = str[j] + str[i];
	str[i] = str[j] - str[i];//swapping two character misplaced
	str[j] = str[j] - str[i];
}
char *fixing(char *str, int len)
{
	int i,j;
	bool t = 0;
	if (str&&len > 0)
	{
		for (i = 0; str[i] != '\0'&&str[i + 1] != '\0'; i++)
		{
			if (str[i] - '0' > str[i + 1] - '0'&&t == 0)//finding first misplaced
			{
				j = i;
				t = 1;
			}
			else if (str[i] - '0' > str[i + 1] - '0')//second misplaced
			{
				swap(j, i + 1, str);
				break;
			}
		}
		if (str[i + 1] == '\0'&&t == 1)//if misplaced is at end
		{
			swap(j, i, str);
		}
		return str;
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
	printf("%s",fixing(str, len));
	_getch();
}