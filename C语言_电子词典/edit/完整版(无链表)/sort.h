//²åÈëÅÅÐò 
void insertSort(data *dic, int *length){
	int i=0;
	data temp;
	for(i=*length-1;i>0;i--){
		if(strcmp(dic[i].eng,dic[i-1].eng)<0){
			temp = dic[i];
			dic[i] = dic[i-1];
			dic[i-1]=temp;
		}
	}
}

//Ã°ÅÝÅÅÐò 
void bubbleSort(data *dic, int* length){
	data temp;
	int i=0, j=0;
	for(i=0;i<*length-1;i++){
		for(j=0;j<*length-i-1;j++){
			if(strcmp(dic[j].eng,dic[j+1].eng)>0){
				temp = dic[j];
				dic[j] = dic[j+1];
				dic[j+1] = temp;
			}
		}
	}
}
//bug¿ìËÙÅÅÐò 
void quickSort(data *dic, int left, int right){
	int low = left;
	int high = right;
	data temp = dic[low];
	if(left >= right)return;
	while(low<high){
		while(low<high &&(strcmp(dic[high].eng,temp.eng)>0))high--;
		dic[low]=dic[high];
		while(low<high &&(strcmp(dic[low].eng,temp.eng)<0))low++;
		dic[high]=dic[low];
	}
	dic[low]=temp;
	quickSort(dic,left,low-1);
	quickSort(dic,low+1,right);
}

