/*************读取词汇库开始****************/ 
int readFile(data *sql,char *path)
{
	int i=0;
	char eng[30]={0};
	char cn[30]={0};
	FILE *fp=fopen(path,"r");
	if(fp==NULL)
	{
		printf("打开文件失败!");
		return -1; 
	}
	else
	{
//		while(!feof(fp))
//		{
//			fscanf(fp,"%s\t%s",(sql+i)->eng,(sql+i)->cn);
////			printf("%s    %s\n",eng,cn);(sql+i)->word,(sql+i)->cn)  调试代码 
////			printf("%s\t%s\n",(sql+i)->eng,(sql+i)->cn);
//			i++;
//		}
 		while(fscanf(fp,"%s\t%s",(sql+i)->eng,(sql+i)->cn)!=EOF)
  		{
    		i++;
  		}
		fclose(fp);
//		printf("共计%d个单词!\n",i);
//		printf("请开始下面的操作:\n"); 
		return i;
	}
}
/*************读取词汇库结束****************/


