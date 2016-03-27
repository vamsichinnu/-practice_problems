#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
char *anagram(char *str1, int len1,char *str2,int len2)
{
	char *ascii, *res;
	int i;
	ascii = (char *)calloc(26, sizeof(char));
	if (str1&&len1>0&&str2&&len2>0)
	{
		for (i = 0; str1[i] != '\0'; i++)
		{
			if (str1[i] >= 65 && str1[i] <= 90)//combining both captial and small letters
			{
				ascii[(str1[i]) - 65]++;

			}
			else if (str1[i] >= 97 && str1[i] <= 122)//hasing technique 
			{
				ascii[(str1[i])- 97]++;
			}
		}
		for (i = 0; str2[i] != '\0'; i++)
		{
			if (str2[i] >= 65 && str2[i] <= 90)
			{
				ascii[(str2[i]) - 65]--;
				if (ascii[(str2[i]) - 65] < 0)//comparining with string2 decresing count in ascii
				{
					return "not anagram";//if ascii array value is less then not anagram 
				}
			}
			else if (str2[i] >= 97 && str2[i] <= 122)
			{
				ascii[(str2[i]) - 97]--;
				if (ascii[(str2[i]) -97] < 0)
				{
					return "not anagram";
				}
			}
		}
		for (i = 0; i < 26; i++)//if ascii value >0 not anagram
		{
			if (ascii[i] != 0)
			{
				return "not anagram";
			}
		}
		return "anagram";
	}
	else
	{
		return "not anagram";
	}
}
void main()
{
	char *str1,*str2;
	int len1,len2;
	printf("enter the length of string1");
	scanf("%d", &len1);
	str1 = (char *)malloc(sizeof(char)*len1);
	printf("enter the length of string2");
	scanf("%d", &len2);
	str2 = (char *)malloc(sizeof(char)*len2);
	printf("enter the string1");
	scanf("%s", str1);
	fflush(stdin);
	printf("enter the string2");
	scanf("%s", str2);
	printf("%s", anagram(str1,len1,str2,len2));
	_getch();
}