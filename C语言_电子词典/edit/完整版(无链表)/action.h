/*************������ƿ�ʼ****************/
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
	color(3);printf("��ǰ��������%d",*number);color(12);
	printf("           * * *\n");
	printf(" *                                       * * *\n");
	printf(" *                                       * * *\n");
	printf(" *              1.Ӣ�뺺                 * * *\n");
	printf(" *              2.����Ӣ                 * * *\n");
	printf(" *              3.��ӵ�������           * * *\n");
	printf(" *              4.ɾ����������           * * *\n");
	printf(" *              5.�޸ĵ�������           * * *\n");
	printf(" *              6.����ͳ��               * * *\n");
	printf(" *              0.�رմʵ�               * * *\n");
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
	printf("��ѡ������Ҫ�Ĺ��ܣ�"); 
}
/*************������ƽ���****************/

/***************�¼�����ʼ****************/
void dealAction(data *dictionarysql,int action,int *number)
{
	if(action==1)
	{
		char word[20];
		int pos;
		printf("����������Ҫ��ѯ�ĵ���:");
		scanf("%s",word);
		printf("-------------------------------------------------\n");
		pos=searchEng(dictionarysql,number,word);
		if(pos!=-1)
		{
			printf("����ҵĵ���%s��������˼��:%s\n\n\n",word,dictionarysql[pos].cn);
		}
		else
		{
			printf("�Բ���,û������ҵĵ���!\n\n\n"); 
		}
	}
	else if(action==2)
	{
		char cn[30];
		int pos;
		printf("����������Ҫ����Ĵ�:");
		scanf("%s",cn);
		printf("-------------------------------------------------\n");
		pos=searchCn(dictionarysql,number,cn);
		if(pos!=-1)
		{
			printf("������Ĵ���%s�ķ�����%s\t%s\n\n\n",cn,dictionarysql[pos].eng,dictionarysql[pos].cn);	
		}	
		else
		{
			printf("�Բ���,û���ҵ����뷭��Ĵ�!\n\n\n");
		}
	} 
	else if(action==3)
	{
		char eng[20];
		char cn[30];
		printf("������������ӵ�Ӣ��:");
		scanf("%s",eng);
		strcpy(dictionarysql[*number].eng,eng);
		printf("������������ӵ����Ĳ���:");
		scanf("%s",cn);
		printf("-------------------------------------------------\n");
		strcpy(dictionarysql[*number].cn,cn);
		printf("%s+%s\n",dictionarysql[*number].eng,dictionarysql[*number].cn);
		(*number)++;
		printf("%d\n",*number);
		insertSort(dictionarysql, number);
		savesql(dictionarysql,number);
		
		printf("********��ӵ������!********\n"); 
	}
	else if(action==4)
	{
		//˼·:���ҵ��ĵ������Ϊ�����ַ�
		char eng[20];
		int pos;
		char judge;
		printf("����������Ҫɾ���ĵ���:");
		scanf("%s",eng);
		pos=searchEng(dictionarysql,number,eng);
		getchar();
		if(pos!=-1)
		{
			char a[5]="#";
			printf("ȷ��Ҫɾ����?'Y'or'N'");
			scanf("%c",&judge);
			if(judge=='Y' || judge=='y')
			{
				strcpy(dictionarysql[pos].eng,a);	
				strcpy(dictionarysql[pos].cn,a);
				savesql(dictionarysql,number);
				(*number)--;
				printf("-------------------------------------------------\n");
				printf("********ɾ���ɹ�!********\n"); 
			}
			else
			{
				printf("********ȡ��ɾ��!********\n");
			}
		}	
		else
		{
			printf("-------------------------------------------------\n");
			printf("û��������Ҫɾ���ĵ���!\n");
		}
	} 
	else if(action==5)
	{
		char eng[20];
		int pos;
		printf("����������Ҫ�޸ĵĵ���:");
		scanf("%s",eng);
		pos=searchEng(dictionarysql,number,eng);
		if(pos!=-1)
		{
			char cn[30];
			printf("�����������޸ĵ�����:\n");
			scanf("%s",cn); 
			strcpy(dictionarysql[pos].cn,cn);
			savesql(dictionarysql,number);
			printf("-------------------------------------------------\n");
			printf("********�޸ĳɹ���********\n"); 
		}
		else
		{
			printf("û�������޸ĵĴ�!\n");
		} 
	}
	else if(action==6)
	{
		char eng[20];
		printf("����������Ҫͳ��ĵ���:");
		scanf("%s",eng);
		while(strlen(eng)<3 )
		{
			printf("����������:\n");
			scanf("%s",eng);	
		}
		int f;
		f=Find(dictionarysql,number,eng);
		if(f==-1)
		{
			printf("û��������ѯ�ĵ��ʶ�\n");
			printf("-------------------------------------------------\n");
		}
	}
}
/***************�¼��������****************/
