#include "public.h"
/*
����ģ�飬����һЩ������������ѯͼ�顢ע���˺�
*/
void cleanScr(int times)
{//���ָ����������Ļ����
    for(int i=0;i<times;i++)
        system("cls");
}

int change_line(char *filename,char *origin,char *modified,int lenth)
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
        fputs(mod,new_file);
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

int delete_line(char *filename,char *target,int lenth)
{
    /*
    �ı��ļ���ĳһ�е����ݣ������ļ�������Ҫ�޸ĵ�ĳһ�к��޸ĺ���ַ������ļ����ַ�����󳤶�
    ��ʹ��ǰ��ر��ļ���ִ���������´�
    ��֪ȱ�ݣ�  ���ļ����ж�����ͬ������ʱ�޷�����(ֻ�޸ĵ�һ�γ��ֵ�)
    */
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

int insert_line(char *filename,char *search,char *inserted,int lenth)
{
    /*
    ���ļ���ĳһ�к�����µ�һ�У������ļ�����Ŀ���С��ļ����ַ�����󳤶�
    ��ʹ��ǰ��ر��ļ���ִ���������´�
    */
    FILE *file,*new_file;
    char *locate,*ins,*ser;
    int status=0,len_i=strlen(inserted),len_s=strlen(search);
    ins=(char*)malloc(sizeof(char)*len_i);//����洢�����ַ����Ŀռ�
    ser=(char*)malloc(sizeof(char)*len_s);//����洢�����ַ����Ŀռ�
    locate=(char*)malloc(sizeof(char)*lenth);//�����������صĿռ�
    strcpy(ins,inserted);
    strcpy(ser,search);
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
