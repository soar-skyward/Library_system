#include "public.h"
/*
����ģ�飬����һЩ������������ѯͼ�顢ע���˺�
*/
void cleanScr(int times)
{//���ָ����������Ļ����
    for(int i=0;i<times;i++)
        system("cls");
}

int change_line(char *filename,char *origin,char *modified,int max_lenth)
{
    //�ı��ļ���ĳһ�е����ݣ������ļ�������Ҫ�޸ĵ�ĳһ�к��޸ĺ���ַ������ļ����ַ�����󳤶�
    //��ʹ��ǰ��ر��ļ���ִ���������´�
    /*
        ��֪ȱ�ݣ����ļ����ж�����ͬ������ʱ�޷�����(ֻ�޸ĵ�һ�γ��ֵģ�������Ľ�)
                  ��ĳ�����ݵ�ǰlenth���ַ�������*origin��������ʱ����
    */
    FILE *file,*new_file;
    char *locate;
    int status=0;
    file=fopen(filename,"a+");
    new_file=fopen("temp.txt","a+");
    locate=(char*)malloc(sizeof(char)*(max_lenth+1));//�����������صĿռ�
    for(int i=0;i<=max_lenth;i++)
    {
        locate[i]='\0'//��ʼ���ռ䣬��ֹ������s
    }
    rewind(file);
    while(!feof(file))
    {
        fgets(locate,max_lenth,file);
        if(!strcmp(locate,origin))
        {
            status=1;
            break;
        }
        else
            fputs(locate,file);
    }
    if(status)
    {
        fputs(modified,file);
        while(!eof)
        {
            fgets(locate,max_lenth,file);
            fputs(locate,file);
    }
    else
    {
        free(locate);
        return -1;
    }
    free(locate);
}
