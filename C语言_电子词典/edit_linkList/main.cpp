#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENG 30
#define CN 50
#define MAX 8000

//����ڵ�
typedef struct word{
    char eng[ENG];
    char cn[CN];
    struct word *next;
}WORD, *pWord;

void doAction(pWord head, int action, int *length, char *filePath);
void printfAction();
//Ӣ��->����
void doEngToCn(pWord head);
//����->Ӣ��
void doCnToEng(pWord head);
//����ڵ�
void insertNode(pWord head, char *eng, char *cn);
//����Ӣ�ĵ���
int searchEngWord(pWord head, char *eng, char *status);
//���Ӣ�ĵ���
void addWord(pWord head, int *length, char *filePath);
//�־û� ����Ϊtxt
void saveWord(pWord head, char *filePath);
//ɾ������
void deleteWord(pWord head, int *length, char *filePath);
//ɾ�������еĽڵ�
int deleteNode(pWord head, char *eng);
//��ȡ�ļ�����txt�ļ���ȡ��������
int readFile(pWord head, char *filePath, int *length);
//��������
void updateWord(pWord head, char *filePath);
int main(){
    int action = -1;

    int count = 0;
    int *pLength = &count;
    char *filePath = "dic2.txt";
    //head ͷָ��
    pWord head = (pWord)malloc(sizeof(WORD));
    head->next = NULL;
    readFile(head, filePath, pLength);
    //    printf("%p\n", head);
    //    printf("%p\n", &head);
    while (action != 0) {
        printf("��ȡ��%d������!\n", count);
        printfAction();
        scanf("%d", &action);
        doAction(head, action, pLength, filePath);
    }

    return 0;
}

/**
* ��ȡ�ļ�
* @param filePath �ļ�·��
* @return -1����ȡ�ļ�ʧ�ܣ�0����ȡ�ɹ�
*/
int readFile(pWord head, char *filePath, int *length){
    char eng[ENG] = { 0 };
    char cn[CN] = { 0 };
    FILE *fp = fopen(filePath, "r");
    if (fp == NULL){
        printf("�ļ���ʧ�ܣ������¼�飡\n");
        return -1;
    }
    //�����ļ�
    //����ÿһ�е����ݣ�Ȼ����ӵ�������
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
* �����û�����ָ�ִ����Ӧ�Ĳ���
* @param head ����ͷָ��
* @param action ָ�����
* @param length ���ʸ���
* @param filePath �ļ�·��
*/
void doAction(pWord head, int action, int *length, char *filePath){
    switch (action) {
        case 0://�˳�
            exit(0);
            break;
        case 1://Ӣ��->����
            doEngToCn(head);
            break;
        case 2://����->Ӣ��
            doCnToEng(head);
            break;
        case 3://��ӵ���
            addWord(head, length, filePath);
            break;
        case 4://ɾ������
            deleteWord(head, length, filePath);
            break;
        case 5://��������
            updateWord(head, filePath);
            break;
        default:
            printf("������0-5֮�������!\n");
            break;
    }
}
/**
 * ��������
 * @param head ����ͷָ��
 * @param filePath �ļ�·��
 */
void updateWord(pWord head, char *filePath){
    WORD wod;
    int status = 0;
    printf("������Ҫ�����ĵ��ʣ�");
    scanf("%s", wod.eng);
    printf("������õ����������������˼��");
    scanf("%s", wod.cn);
    pWord tmp = head->next;
    while (tmp->next != NULL) {
        //�ҵ����� ���޸�
        if (strcmp(tmp->eng, wod.eng) == 0){
            strcpy(tmp->cn, wod.cn);
            saveWord(head, filePath);
            //���ҵ��˵��ʾͽ���
//            return 0;
			break; 
        }
        tmp = tmp->next;
    }
    //û�в��ҵ�
    printf("����ĵ��ʲ����ڣ�");
}

/**
 * ɾ������
 * @param head
 * @param length
 * @param filePath
 */
void deleteWord(pWord head, int *length, char *filePath){
    char eng[ENG] = { 0 };
    int status = 0;
    printf("��������Ҫɾ����Ӣ�ĵ��ʣ�");
    scanf("%s", eng);
    //ɾ�������еĽڵ�
    status = deleteNode(head, eng);
    if (status == 0){
        printf("ɾ���ɹ���\n");
        (*length)--;
        //�������е�ֵд��txt�ĵ�
        saveWord(head, filePath);
    }
    else{
        printf("ɾ��ʧ�ܣ�\n");
    }
}

int deleteNode(pWord head, char *eng){
    pWord tmp = head->next;
    pWord pre = head;
    //��������
    while (tmp != NULL) {
        //�ж��Ƿ�Ϊ�������һ���ڵ�
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
* ��ӵ��ʣ�����굥��֮�󣬰������е�ֵ����Ϊ��txt
* @param head
* @param length
* @param filePath
*/
void addWord(pWord head, int *length, char *filePath){
    WORD wrd;
    printf("��������Ҫ��ӵĵ��ʣ�");
    scanf("%s", wrd.eng);
    //��ѯ�������Ƿ��Ѿ�����˵���
    int pos = searchEngWord(head, wrd.eng, wrd.cn);
    if (pos == -1){
        printf("������õ��ʶ�Ӧ��������˼��");
        scanf("%s", wrd.cn);
        //�������ĵ��ʼ���������
        insertNode(head, wrd.eng, wrd.cn);
        (*length)++;
        //�������е�ֵд��txt�ĵ�
        saveWord(head, filePath);
    }
    else{
        printf("����ӵĵ����Ѿ�������!\n");
    }
}
/**
* �������е�ֵ������Ϊtxt�ĵ�
* @param head
* @param filePath
*/
void saveWord(pWord head, char *filePath){
    FILE * fp = fopen(filePath, "w");
    if (fp == NULL){
        printf("�ļ�����ʧ��\n");
        return;
    }
    pWord tmp = head->next;
    //��������
    while (tmp != NULL) {
        //�ж��Ƿ�Ϊ�������һ���ڵ�
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
* ����->Ӣ��
* @param head
*/
void doCnToEng(pWord head){
    char cn[CN];
    pWord tmp = head->next;
    printf("��������Ҫ���ҵ����ĵ��ʣ�������˼���ɣ���");
    scanf("%s", cn);

    while (tmp->next != NULL) {
        if (strstr(tmp->cn, cn) != NULL){
            printf("\n�����ҵĵ���\'%s\'��Ӣ����˼Ϊ��%s\n", cn, tmp->eng);
            //���ҵ��˵��ʾͽ���
            return;
        }
        tmp = tmp->next;
    }
    printf("����������ĵ��ʵ�Ӣ�ķ��벻����!\n");
}

void doEngToCn(pWord head){
    char eng[30];
    char status[50];
    printf("��������Ҫ��ѯ��Ӣ�ĵ��ʣ�");
    scanf("%s", eng);
    int pos = searchEngWord(head, eng, status);
    if (pos == -1){
        printf("������ĵ��ʲ�����!\n");
    }
    else{
        printf("\'%s\'���ʵ�������˼Ϊ��%s\n", eng, status);
    }
}

int searchEngWord(pWord head, char *eng, char *status){
    pWord tmp = head->next;
    while (tmp->next != NULL) {
        if (strcmp(tmp->eng, eng) == 0){
            //�����ҵ��ĵ���
            strcpy(status, tmp->cn);
            //���ҵ��˵��ʾͽ���
            return 0;
        }
        tmp = tmp->next;
    }
    //û�в��ҵ�
    return -1;
}

void printfAction(){
    printf("-----------------\n");
    printf("1.Ӣ�뺺\t��\n");
    printf("2.����Ӣ\t��\n");
    printf("3.��ӵ�������\t��\n");
    printf("4.ɾ����������\t��\n");
    printf("5.������������\t��\n");
    printf("0.�˳�����\t��\n");
    printf("-----------------\n");
    printf("��������Ҫִ�е�ָ�");
}

/**
* ���ӽڵ�
* @param head ͷָ��
* @param eng ����Ӣ�Ĳ���
* @param cn �������Ĳ���
*/
void insertNode(pWord head, char *eng, char *cn){
    //����һ���ڵ�洢ÿһ������
    pWord node = (pWord)malloc(sizeof(WORD));
    strcpy(node->eng, eng);
    strcpy(node->cn, cn);
    node->next = NULL;

    //���ڵ���ӵ�ͷ�ڵ�͵�һ���ڵ�֮��
    node->next = head->next;
    head->next = node;
}


