#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
char *charcatermax(char *str,int len)

{
	char *ascii, *res;
	int i,k=1;
	ascii = (char *)calloc(26,sizeof(char));
	if (str&&len>0)
	{
		for (i = 0; str[i] != '\0'; i++)
		{
			if (str[i] >= 65 && str[i] <= 90)
			{
				ascii[str[i]- 65]++;

			}
			else if (str[i] >= 97 && str[i] <= 122)
			{
				ascii[str[i]- 97]++;
			}
		}
		res = (char *)malloc(sizeof(char)* 2);
		res[k - 1] = (97);
		res[k] = ascii[0] + '0';
		for (i = 1; i < 26; i++)
		{
			if (res[k] - '0' < ascii[i])
			{
				k = 1;
		res = (char *)malloc(sizeof(char)* 2);
				res[k - 1] = (i + 97);
				res[k] = ascii[i] + '0';
			}
			else if (res[k] - '0' == ascii[i] && ascii[i]>0)
			{
				k = k + 2;
				res = (char *)realloc(res, sizeof(char)*(k + 1));
				res[k - 1] = (i + 97);
				res[k] = ascii[i] + '0';
			}
		}
		res[k + 1] = '\0';
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
	scanf("%s",str);
	printf("%s",charcatermax(str,len));
	_getch();
}