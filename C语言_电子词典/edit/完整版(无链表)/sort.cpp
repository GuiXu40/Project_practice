#include<stdio.h>
#include<string.h>
typedef struct dic
{
	char eng[30];
	char cn[30];
}data;
int str_compare(char *src,char *dst);
void sort_string(char *strs[],int number);
int main()
{
	int i;
	data dictionarysql[5];
	for(i=0;i<5;i++)
	{
		scanf("%s",dictionarysql[i].eng);
	}
	char *ps[5];
	for(i=0;i<5;i++)
	{
		ps[i]=dictionarysql[i].eng;
	}
	sort_string(ps,5);
}
int str_compare(char src1[],char dst1[])
{
	char* src=src1;
	char* dst=dst1;
	int ret = 0;
	if (src == dst)
	{
		return 0;
	}
	if (dst == NULL)
	{
		return -1;
	}
	while (!(ret = *(unsigned char*)src - *(unsigned char*)dst)&& *dst)   //good   able
	{
		++src,++dst;
	}
	if (ret < 0)
	{
		ret = -1;
	}
	else if (ret > 0)
	{
		ret = 1;
	}
	return ret;
}
 //ÅÅĞòº¯Êı
void sort_string(char *strs[],int number)
{
	int i=0,j;

	for(i=0;i<number;i++)
	{
		for ( j = 1; j < number- i; j++)
		{
			if(str_compare(strs[j-1],strs[j]) >0)
			{
				char *tmp=0;
				tmp = strs[j-1];
				strs[j-1] = strs[j];
				strs[j] = tmp;
			}
		}
 
	}
//		//Êä³öÅÅĞòºóµÄ×Ö·û´®
//	for( i=0;i<number;i++)
//	{
//		printf("%s\n",strs[i]);
//	}
}
