/******************���ý��濪ʼ******************/
void color(short x)  
{  
    if(x>=0 && x<=15)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);  
    else
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);  
} 
/******************���ý������******************/
