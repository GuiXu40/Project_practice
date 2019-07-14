/*************界面设计开始****************/
void printfAction(int * number)
{
	color(12);
	printf("-------------------------------------------------\n");
	printf(" * * * * * * * * * * * * * * * * * * * * *\n");
	printf(" *             Welcome to                * *\n");
	printf(" *                                       * * *\n");
	printf(" *        Electronic dictionary          * * *\n");
	printf(" *                                       * * *\n");
	printf(" *            ");
	color(3);printf("当前单词数：%d",*number);color(12);
	printf("           * * *\n");
	printf(" *                                       * * *\n");
	printf(" *                                       * * *\n");
	printf(" *              1.英译汉                 * * *\n");
	printf(" *              2.汉译英                 * * *\n");
	printf(" *              3.添加单词数据           * * *\n");
	printf(" *              4.删除单词数据           * * *\n");
	printf(" *              5.修改单词数据           * * *\n");
	printf(" *              6.单词统查               * * *\n");
	printf(" *              0.关闭词典               * * *\n");
	printf(" *                                       * * *\n");
	printf(" *                                       * * *\n");
	printf(" *           ");
	color(7);printf("Made by Group 04");color(12);
	printf("            * * *\n");
	printf(" *                                       * * *\n");
	printf(" *                                       * * *\n");
	printf(" * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("   * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("     * * * * * * * * * * * * * * * * * * * * *\n");
	printf("-------------------------------------------------\n");
	printf("请选择您需要的功能："); 
}
/*************界面设计结束****************/

/***************事件处理开始****************/
void dealAction(data *dictionarysql,int action,int *number)
{
	if(action==1)
	{
		char word[20];
		int pos;
		printf("请输入你想要查询的单词:");
		scanf("%s",word);
		printf("-------------------------------------------------\n");
		pos=searchEng(dictionarysql,number,word);
		if(pos!=-1)
		{
			printf("你查找的单词%s的中文意思是:%s\n\n\n",word,dictionarysql[pos].cn);
		}
		else
		{
			printf("对不起,没有你查找的单词!\n\n\n"); 
		}
	}
	else if(action==2)
	{
		char cn[30];
		int pos;
		printf("请输入你需要翻译的词:");
		scanf("%s",cn);
		printf("-------------------------------------------------\n");
		pos=searchCn(dictionarysql,number,cn);
		if(pos!=-1)
		{
			printf("你输入的词语%s的翻译是%s\t%s\n\n\n",cn,dictionarysql[pos].eng,dictionarysql[pos].cn);	
		}	
		else
		{
			printf("对不起,没有找到你想翻译的词!\n\n\n");
		}
	} 
	else if(action==3)
	{
		char eng[20];
		char cn[30];
		printf("请输入你所添加的英文:");
		scanf("%s",eng);
		strcpy(dictionarysql[*number].eng,eng);
		printf("请输入你所添加的中文部分:");
		scanf("%s",cn);
		printf("-------------------------------------------------\n");
		strcpy(dictionarysql[*number].cn,cn);
		printf("%s+%s\n",dictionarysql[*number].eng,dictionarysql[*number].cn);
		(*number)++;
		printf("%d\n",*number);
		insertSort(dictionarysql, number);
		savesql(dictionarysql,number);
		
		printf("********添加单词完成!********\n"); 
	}
	else if(action==4)
	{
		//思路:将找到的单词替代为其他字符
		char eng[20];
		int pos;
		char judge;
		printf("请输入你所要删除的单词:");
		scanf("%s",eng);
		pos=searchEng(dictionarysql,number,eng);
		getchar();
		if(pos!=-1)
		{
			char a[5]="#";
			printf("确定要删除吗?'Y'or'N'");
			scanf("%c",&judge);
			if(judge=='Y' || judge=='y')
			{
				strcpy(dictionarysql[pos].eng,a);	
				strcpy(dictionarysql[pos].cn,a);
				savesql(dictionarysql,number);
				(*number)--;
				printf("-------------------------------------------------\n");
				printf("********删除成功!********\n"); 
			}
			else
			{
				printf("********取消删除!********\n");
			}
		}	
		else
		{
			printf("-------------------------------------------------\n");
			printf("没有你所想要删除的单词!\n");
		}
	} 
	else if(action==5)
	{
		char eng[20];
		int pos;
		printf("输入你所想要修改的单词:");
		scanf("%s",eng);
		pos=searchEng(dictionarysql,number,eng);
		if(pos!=-1)
		{
			char cn[30];
			printf("请输入你所修改的中文:\n");
			scanf("%s",cn); 
			strcpy(dictionarysql[pos].cn,cn);
			savesql(dictionarysql,number);
			printf("-------------------------------------------------\n");
			printf("********修改成功！********\n"); 
		}
		else
		{
			printf("没有你想修改的词!\n");
		} 
	}
	else if(action==6)
	{
		char eng[20];
		printf("输入你所想要统查的单词:");
		scanf("%s",eng);
		while(strlen(eng)<3 )
		{
			printf("请重新输入:\n");
			scanf("%s",eng);	
		}
		int f;
		f=Find(dictionarysql,number,eng);
		if(f==-1)
		{
			printf("没有你所查询的单词段\n");
			printf("-------------------------------------------------\n");
		}
	}
}
/***************事件处理结束****************/
