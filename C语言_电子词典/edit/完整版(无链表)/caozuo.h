/***************Ӣ�뺺��ʼ****************/
int searchEng(data *dictionarysql,int * number,char eng[20])
{
	//���ֲ��� 
	int low,mid,max;
	low=0;
	max=*number;
	while(low<=max)
	{
		mid=(low+max)/2;
		if(strcmp(dictionarysql[mid].eng,eng)>0)
		{
			max=mid-1;
		}
		else if(strcmp(dictionarysql[mid].eng,eng)<0)
		{
			low=mid+1;		
		}
		else
		{
			return mid;	
		}	
	} 
	printf("%d",*number);
	//���ֲ��ҽ���
	//���û�в��ҵ�,��˳�����
	int i;
	for(i=0;i<*number;i++)
	{
		    if(strcmp(dictionarysql[i].eng,eng)==0)
		    {
      			return i;		    	
			}
	}
	//�����ѯ����,�ͷ���һ������
	return -1; 
}
/***************Ӣ�뺺����****************/


/***************����Ӣ��ʼ****************/
int searchCn(data *dictionarysql,int * number,char cn[30])
{
	int i;
	for(i=0;i<*number;i++)
	{
		if(strstr(dictionarysql[i].cn,cn)!=NULL)
		{
			return i;
		}
	}
	return -1;
}
/***************����Ӣ����****************/


/***************���濪ʼ****************/
void savesql(data *dictionarysql,int *number)
{
	FILE *fp=fopen("dic2.txt","w");
  	int i=0;
  	for(i=0;i<*number;i++)
  	{
    	if(dictionarysql[i].eng[0]!='#')
    	{
  			
     		fprintf(fp,"%s\t%s\n",dictionarysql[i].eng,dictionarysql[i].cn);
    	}
  	}
  	fclose(fp);
}
/***************�������****************/


/****************����ϵ�п�ʼ***************/ 
int Find(data *dictionarysql,int * number,char eng[20])
{
	int i;
	int f=-1;
	
	for(i=0;i<*number;i++)
	{
		if(strstr(dictionarysql[i].eng,eng)!=NULL)
		{
			printf("%s\t%s\n",dictionarysql[i].eng,dictionarysql[i].cn);
			f=1;
		}
	} 
	return f;
} 
/****************����ϵ�н���***************/ 
