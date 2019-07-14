#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENG 30
#define CN 50
#define MAX 8000

//定义节点
typedef struct word{
    char eng[ENG];
    char cn[CN];
    struct word *next;
}WORD, *pWord;

void doAction(pWord head, int action, int *length, char *filePath);
void printfAction();
//英文->中文
void doEngToCn(pWord head);
//中文->英文
void doCnToEng(pWord head);
//插入节点
void insertNode(pWord head, char *eng, char *cn);
//搜索英文单词
int searchEngWord(pWord head, char *eng, char *status);
//添加英文单词
void addWord(pWord head, int *length, char *filePath);
//持久化 保存为txt
void saveWord(pWord head, char *filePath);
//删除单词
void deleteWord(pWord head, int *length, char *filePath);
//删除链表中的节点
int deleteNode(pWord head, char *eng);
//读取文件，将txt文件读取到链表中
int readFile(pWord head, char *filePath, int *length);
//更正单词
void updateWord(pWord head, char *filePath);
int main(){
    int action = -1;

    int count = 0;
    int *pLength = &count;
    char *filePath = "dic2.txt";
    //head 头指针
    pWord head = (pWord)malloc(sizeof(WORD));
    head->next = NULL;
    readFile(head, filePath, pLength);
    //    printf("%p\n", head);
    //    printf("%p\n", &head);
    while (action != 0) {
        printf("读取到%d个单词!\n", count);
        printfAction();
        scanf("%d", &action);
        doAction(head, action, pLength, filePath);
    }

    return 0;
}

/**
* 读取文件
* @param filePath 文件路径
* @return -1，读取文件失败；0，读取成功
*/
int readFile(pWord head, char *filePath, int *length){
    char eng[ENG] = { 0 };
    char cn[CN] = { 0 };
    FILE *fp = fopen(filePath, "r");
    if (fp == NULL){
        printf("文件打开失败，请重新检查！\n");
        return -1;
    }
    //遍历文件
    //读出每一行的内容，然后添加到链表中
    while (!feof(fp))
    {
        fscanf(fp, "%s\t%s", eng, cn);
        (*length)++;
        insertNode(head, eng, cn);
    }
    fclose(fp);
    return 0;
}
/**
* 根据用户输入指令，执行相应的操作
* @param head 链表头指针
* @param action 指令代码
* @param length 单词个数
* @param filePath 文件路径
*/
void doAction(pWord head, int action, int *length, char *filePath){
    switch (action) {
        case 0://退出
            exit(0);
            break;
        case 1://英文->中文
            doEngToCn(head);
            break;
        case 2://中文->英文
            doCnToEng(head);
            break;
        case 3://添加单词
            addWord(head, length, filePath);
            break;
        case 4://删除单词
            deleteWord(head, length, filePath);
            break;
        case 5://修正单词
            updateWord(head, filePath);
            break;
        default:
            printf("请输入0-5之间的数字!\n");
            break;
    }
}
/**
 * 修正单词
 * @param head 链表头指针
 * @param filePath 文件路径
 */
void updateWord(pWord head, char *filePath){
    WORD wod;
    int status = 0;
    printf("请输入要修正的单词：");
    scanf("%s", wod.eng);
    printf("请输入该单词修正后的中文意思：");
    scanf("%s", wod.cn);
    pWord tmp = head->next;
    while (tmp->next != NULL) {
        //找到单词 并修改
        if (strcmp(tmp->eng, wod.eng) == 0){
            strcpy(tmp->cn, wod.cn);
            saveWord(head, filePath);
            //查找到了单词就结束
//            return 0;
			break; 
        }
        tmp = tmp->next;
    }
    //没有查找到
    printf("输入的单词不存在！");
}

/**
 * 删除单词
 * @param head
 * @param length
 * @param filePath
 */
void deleteWord(pWord head, int *length, char *filePath){
    char eng[ENG] = { 0 };
    int status = 0;
    printf("请输入你要删除的英文单词：");
    scanf("%s", eng);
    //删除链表中的节点
    status = deleteNode(head, eng);
    if (status == 0){
        printf("删除成功！\n");
        (*length)--;
        //将链表中的值写入txt文档
        saveWord(head, filePath);
    }
    else{
        printf("删除失败！\n");
    }
}

int deleteNode(pWord head, char *eng){
    pWord tmp = head->next;
    pWord pre = head;
    //遍历链表
    while (tmp != NULL) {
        //判断是否为链表最后一个节点
        if (strcmp(tmp->eng, eng) == 0){
            pre->next = tmp->next;
            free(tmp);
            return 0;
        }
        else{
            pre = tmp;
            tmp = tmp->next;
        }
    }
    return -1;
}
/**
* 添加单词，添加完单词之后，把链表中的值保存为了txt
* @param head
* @param length
* @param filePath
*/
void addWord(pWord head, int *length, char *filePath){
    WORD wrd;
    printf("请输入你要添加的单词：");
    scanf("%s", wrd.eng);
    //查询链表中是否已经添加了单词
    int pos = searchEngWord(head, wrd.eng, wrd.cn);
    if (pos == -1){
        printf("请输入该单词对应的中文意思：");
        scanf("%s", wrd.cn);
        //将新增的单词加入链表中
        insertNode(head, wrd.eng, wrd.cn);
        (*length)++;
        //将链表中的值写入txt文档
        saveWord(head, filePath);
    }
    else{
        printf("你添加的单词已经存在了!\n");
    }
}
/**
* 将链表中的值，保存为txt文档
* @param head
* @param filePath
*/
void saveWord(pWord head, char *filePath){
    FILE * fp = fopen(filePath, "w");
    if (fp == NULL){
        printf("文件保存失败\n");
        return;
    }
    pWord tmp = head->next;
    //遍历链表
    while (tmp != NULL) {
        //判断是否为链表最后一个节点
        if (tmp->next == NULL){
            fprintf(fp, "%s\t%s", tmp->eng, tmp->cn);
        }
        else{
            fprintf(fp, "%s\t%s\n", tmp->eng, tmp->cn);
        }
        tmp = tmp->next;
    }
    fclose(fp);
}
/**
* 中文->英文
* @param head
*/
void doCnToEng(pWord head){
    char cn[CN];
    pWord tmp = head->next;
    printf("请输入你要查找的中文单词（大致意思即可）：");
    scanf("%s", cn);

    while (tmp->next != NULL) {
        if (strstr(tmp->cn, cn) != NULL){
            printf("\n您查找的单词\'%s\'的英文意思为：%s\n", cn, tmp->eng);
            //查找到了单词就结束
            return;
        }
        tmp = tmp->next;
    }
    printf("你输入的中文单词的英文翻译不存在!\n");
}

void doEngToCn(pWord head){
    char eng[30];
    char status[50];
    printf("请输入你要查询的英文单词：");
    scanf("%s", eng);
    int pos = searchEngWord(head, eng, status);
    if (pos == -1){
        printf("你输入的单词不存在!\n");
    }
    else{
        printf("\'%s\'单词的中文意思为：%s\n", eng, status);
    }
}

int searchEngWord(pWord head, char *eng, char *status){
    pWord tmp = head->next;
    while (tmp->next != NULL) {
        if (strcmp(tmp->eng, eng) == 0){
            //返回找到的单词
            strcpy(status, tmp->cn);
            //查找到了单词就结束
            return 0;
        }
        tmp = tmp->next;
    }
    //没有查找到
    return -1;
}

void printfAction(){
    printf("-----------------\n");
    printf("1.英译汉\t｜\n");
    printf("2.汉译英\t｜\n");
    printf("3.添加单词数据\t｜\n");
    printf("4.删除单词数据\t｜\n");
    printf("5.修正单词数据\t｜\n");
    printf("0.退出程序\t｜\n");
    printf("-----------------\n");
    printf("请输入您要执行的指令：");
}

/**
* 增加节点
* @param head 头指针
* @param eng 单词英文部分
* @param cn 单词中文部分
*/
void insertNode(pWord head, char *eng, char *cn){
    //创建一个节点存储每一行数据
    pWord node = (pWord)malloc(sizeof(WORD));
    strcpy(node->eng, eng);
    strcpy(node->cn, cn);
    node->next = NULL;

    //将节点添加到头节点和第一个节点之间
    node->next = head->next;
    head->next = node;
}


