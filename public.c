#include "public.h"
/*
����ģ�飬����һЩ������������ѯͼ�顢ע���˺š��ļ�����
*/
void cleanScr(int times)
{//���ָ����������Ļ����
    for(int i=0;i<times;i++)
        system("cls");
}

void cut_line(char *ori,int Start,int End)
{
    //���ַ����и���´�Start��End������
    //���һֱ���������EndֵΪ-1
    char *temp;
    int i,j=0;
    temp=(char*)malloc(sizeof(char)*strlen(ori));
    if(End==-1)
        End=strlen(ori)-1;
    for(i=Start;i<=End;i++)
        temp[j]=ori[i];
    strcpy(ori,temp);
}

int change_line(char *filename,char *origin,char *modified,int lenth,int mode)
{
    /*
    �ı��ļ���ĳһ�е����ݣ������ļ�������Ҫ�޸ĵ�ĳһ�к��޸ĺ���ַ������ļ����ַ�����󳤶�
    ��ʹ��ǰ��ر��ļ���ִ���������´�
    ��֪ȱ�ݣ�  ���ļ����ж�����ͬ������ʱ�޷�����(ֻ�޸ĵ�һ�γ��ֵ�)
    */
    FILE *file,*new_file;
    char *locate,*ori,*mod;
    int status=0,len_o=strlen(origin),len_m=strlen(modified);
    ori=(char*)malloc(sizeof(char)*len_o);//����洢ԭʼ�ַ����Ŀռ�
    mod=(char*)malloc(sizeof(char)*len_m);//�����޸ĺ��ַ����Ŀռ�
    locate=(char*)malloc(sizeof(char)*lenth);//�����������صĿռ�
    strcpy(ori,origin);
    strcpy(mod,modified);
    strcat(ori,"\n");
    strcat(mod,"\n");
    file=fopen(filename,"a+");
    new_file=fopen("temp.txt","a+");
    rewind(file);
    while(!feof(file))
    {//��������Ŀ����֮ǰ�����ݸ��Ƶ����ļ���
        fgets(locate,lenth,file);
        if(!strcmp(locate,ori))
        {//��⵽Ŀ���У�����
            status=1;
            break;
        }
        else
            fputs(locate,new_file);
    }
    if(status)
    {
        switch(mode)
        {
        case(0)://�޸�
            fputs(mod,new_file);
            break;
        case(1)://���
            fputs(locate,new_file);
            fputs(mod,new_file);
            break;
        case(2)://ɾ��
            break;
        }
        while(!feof(file))
        {//��Ŀ����֮������ݸ��Ƶ����ļ�����
            fgets(locate,lenth,file);
            fputs(locate,new_file);
        }
        fclose(file);
        fclose(new_file);
        rename(filename,"old");
        rename("temp.txt",filename);
        remove("old");
        free(locate);//�ͷ��ڴ�
        free(ori);
        free(mod);
        return 0;
    }
    else
    {//û���ҵ�ʱ���ش������-1
        free(locate);//�ͷ��ڴ�
        free(ori);
        free(mod);
        fclose(file);
        fclose(new_file);
        remove("temp.txt");
        return -1;
    }
}
/*
int delete_line(char *filename,char *target,int lenth)
{

    ɾ���ļ���ĳһ�е����ݣ������ļ�������Ҫɾ����ĳһ�У��ļ����ַ�����󳤶�
    ��ʹ��ǰ��ر��ļ���ִ���������´�
    ��֪ȱ�ݣ�  ���ļ����ж�����ͬ������ʱ�޷�����(ֻɾ����һ�γ��ֵ�)

    FILE *file,*new_file;
    char *locate,*del;
    int status=0;
    locate=(char*)malloc(sizeof(char)*lenth);//�����������صĿռ�
    del=(char*)malloc(sizeof(char)*strlen(target));
    strcpy(del,target);
    strcat(del,"\n");
    file=fopen(filename,"a+");
    new_file=fopen("temp.txt","a+");
    rewind(file);
    while(!feof(file))
    {//����Ŀ����
        fgets(locate,lenth,file);
        if(!strcmp(locate,del))
        {//��⵽Ŀ���У�����
            status=1;
            break;
        }
        else
            fputs(locate,new_file);
    }
    if(status)
    {
        while(!feof(file))
        {//��Ŀ����֮������ݸ��Ƶ����ļ�����
            fgets(locate,lenth,file);
            fputs(locate,new_file);
        }
        fclose(file);
        fclose(new_file);
        rename(filename,"old");
        rename("temp.txt",filename);
        remove("old");
        free(locate);//�ͷ��ڴ�
        free(del);
        return 0;
    }
    else
    {//û���ҵ�ʱ���ش������-1
        free(locate);//�ͷ��ڴ�
        free(del);
        fclose(file);
        fclose(new_file);
        remove("temp.txt");
        return -1;
    }
}

int insert_line(char *filename,char *Search,char *Insert,int lenth)
{

    ���ļ���ĳһ�к�����µ�һ�У������ļ�����Ŀ���У��ļ����ַ�����󳤶�
    ��ʹ��ǰ��ر��ļ���ִ���������´�

    FILE *file,*new_file;
    char *locate,*ins,*ser;
    int status=0,len_i=strlen(Insert),len_s=strlen(Search);
    ins=(char*)malloc(sizeof(char)*len_i);//����洢�����ַ����Ŀռ�
    ser=(char*)malloc(sizeof(char)*len_s);//����洢�����ַ����Ŀռ�
    locate=(char*)malloc(sizeof(char)*lenth);//�����������صĿռ�
    strcpy(ins,Insert);
    strcpy(ser,Search);
    strcat(ins,"\n");
    strcat(ser,"\n");
    file=fopen(filename,"a+");
    new_file=fopen("temp.txt","a+");
    rewind(file);
    while(!feof(file))
    {//��������Ŀ����֮ǰ�����ݸ��Ƶ����ļ���
        fgets(locate,lenth,file);
        fputs(locate,new_file);
        if(!strcmp(locate,ser))
        {//��⵽Ŀ���У�����
            status=1;
            break;
        }
    }
    if(status)
    {
        fputs(ins,new_file);
        while(!feof(file))
        {//��Ŀ����֮������ݸ��Ƶ����ļ�����
            fgets(locate,lenth,file);
            fputs(locate,new_file);
        }
        fclose(file);
        fclose(new_file);
        rename(filename,"old");
        rename("temp.txt",filename);
        remove("old");
        free(locate);//�ͷ��ڴ�
        free(ins);
        free(ser);
        return 0;
    }
    else
    {//û���ҵ�ʱ���ش������-1
        free(locate);//�ͷ��ڴ�
        free(ins);
        free(ser);
        fclose(file);
        fclose(new_file);
        remove("temp.txt");
        return -1;
    }
}
*/

