/***************英译汉开始****************/
int searchEng(data *dictionarysql,int * number,char eng[20])
{
	//二分查找 
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
	//二分查找结束
	//如果没有查找到,则顺序查找
	int i;
	for(i=0;i<*number;i++)
	{
		    if(strcmp(dictionarysql[i].eng,eng)==0)
		    {
      			return i;		    	
			}
	}
	//如果查询不到,就返回一个负数
	return -1; 
}
/***************英译汉结束****************/


/***************汉译英开始****************/
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
/***************汉译英结束****************/


/***************保存开始****************/
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
/***************保存结束****************/


/****************查找系列开始***************/ 
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
/****************查找系列结束***************/ 
