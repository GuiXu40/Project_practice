/*************��ȡ�ʻ�⿪ʼ****************/ 
int readFile(data *sql,char *path)
{
	int i=0;
	char eng[30]={0};
	char cn[30]={0};
	FILE *fp=fopen(path,"r");
	if(fp==NULL)
	{
		printf("���ļ�ʧ��!");
		return -1; 
	}
	else
	{
//		while(!feof(fp))
//		{
//			fscanf(fp,"%s\t%s",(sql+i)->eng,(sql+i)->cn);
////			printf("%s    %s\n",eng,cn);(sql+i)->word,(sql+i)->cn)  ���Դ��� 
////			printf("%s\t%s\n",(sql+i)->eng,(sql+i)->cn);
//			i++;
//		}
 		while(fscanf(fp,"%s\t%s",(sql+i)->eng,(sql+i)->cn)!=EOF)
  		{
    		i++;
  		}
		fclose(fp);
//		printf("����%d������!\n",i);
//		printf("�뿪ʼ����Ĳ���:\n"); 
		return i;
	}
}
/*************��ȡ�ʻ�����****************/


