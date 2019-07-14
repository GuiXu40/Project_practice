#include<stdio.h>
#include<string.h> 
#include <windows.h>
#include "dic.h"
#include "color.h"
#include "readFile.h"
#include "caozuo.h" 
#include "sort.h"
#include "action.h"


int main()
{
	char *path = "dic2.txt";
	data dictionarysql[9000]; //´Ê»ãÊý¾Ý¿â 
	int wordsNumber=0;
	int *number=&wordsNumber;
	printf("%d+%d\n",wordsNumber,*number);
	wordsNumber=readFile(dictionarysql ,path);
//	printf("%d",keyNum);
	int action=-1;
	while(action!=0)
	{
		printfAction(number);
		scanf("%d",&action);
		printf("-------------------------------------------------\n");
		dealAction(dictionarysql,action,number);
		getchar();
	}
	return 0;	
}
