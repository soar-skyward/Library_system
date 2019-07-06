#include "public.h"
/*
公共模块，负责一些基本操作：查询图书、注册账号、文件操作
*/
void cleanScr(int times)
{//清除指定行数的屏幕内容
    for(int i=0;i<times;i++)
        system("cls");
}

void cut_line(char *ori,int Start,int End)
{
    //将字符串切割，留下从Start到End的内容
    //如果一直留到最后则End值为-1
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
    改变文件中某一行的数据，输入文件名、想要修改的某一行和修改后的字符串、文件中字符串最大长度
    在使用前需关闭文件，执行完再重新打开
    已知缺陷：  当文件中有多行相同的数据时无法作用(只修改第一次出现的)
    */
    FILE *file,*new_file;
    char *locate,*ori,*mod;
    int status=0,len_o=strlen(origin),len_m=strlen(modified);
    ori=(char*)malloc(sizeof(char)*len_o);//申请存储原始字符串的空间
    mod=(char*)malloc(sizeof(char)*len_m);//申请修改后字符串的空间
    locate=(char*)malloc(sizeof(char)*lenth);//申请用于搜素的空间
    strcpy(ori,origin);
    strcpy(mod,modified);
    strcat(ori,"\n");
    strcat(mod,"\n");
    file=fopen(filename,"a+");
    new_file=fopen("temp.txt","a+");
    rewind(file);
    while(!feof(file))
    {//在搜索到目标行之前将数据复制到新文件中
        fgets(locate,lenth,file);
        if(!strcmp(locate,ori))
        {//检测到目标行，跳出
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
        case(0)://修改
            fputs(mod,new_file);
            break;
        case(1)://添加
            fputs(locate,new_file);
            fputs(mod,new_file);
            break;
        case(2)://删除
            break;
        }
        while(!feof(file))
        {//将目标行之后的数据复制到新文件当中
            fgets(locate,lenth,file);
            fputs(locate,new_file);
        }
        fclose(file);
        fclose(new_file);
        rename(filename,"old");
        rename("temp.txt",filename);
        remove("old");
        free(locate);//释放内存
        free(ori);
        free(mod);
        return 0;
    }
    else
    {//没有找到时返回错误代码-1
        free(locate);//释放内存
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

    删除文件中某一行的数据，输入文件名、想要删除的某一行，文件中字符串最大长度
    在使用前需关闭文件，执行完再重新打开
    已知缺陷：  当文件中有多行相同的数据时无法作用(只删除第一次出现的)

    FILE *file,*new_file;
    char *locate,*del;
    int status=0;
    locate=(char*)malloc(sizeof(char)*lenth);//申请用于搜素的空间
    del=(char*)malloc(sizeof(char)*strlen(target));
    strcpy(del,target);
    strcat(del,"\n");
    file=fopen(filename,"a+");
    new_file=fopen("temp.txt","a+");
    rewind(file);
    while(!feof(file))
    {//搜索目标行
        fgets(locate,lenth,file);
        if(!strcmp(locate,del))
        {//检测到目标行，跳出
            status=1;
            break;
        }
        else
            fputs(locate,new_file);
    }
    if(status)
    {
        while(!feof(file))
        {//将目标行之后的数据复制到新文件当中
            fgets(locate,lenth,file);
            fputs(locate,new_file);
        }
        fclose(file);
        fclose(new_file);
        rename(filename,"old");
        rename("temp.txt",filename);
        remove("old");
        free(locate);//释放内存
        free(del);
        return 0;
    }
    else
    {//没有找到时返回错误代码-1
        free(locate);//释放内存
        free(del);
        fclose(file);
        fclose(new_file);
        remove("temp.txt");
        return -1;
    }
}

int insert_line(char *filename,char *Search,char *Insert,int lenth)
{

    向文件中某一行后插入新的一行，输入文件名、目标行，文件中字符串最大长度
    在使用前需关闭文件，执行完再重新打开

    FILE *file,*new_file;
    char *locate,*ins,*ser;
    int status=0,len_i=strlen(Insert),len_s=strlen(Search);
    ins=(char*)malloc(sizeof(char)*len_i);//申请存储插入字符串的空间
    ser=(char*)malloc(sizeof(char)*len_s);//申请存储插入字符串的空间
    locate=(char*)malloc(sizeof(char)*lenth);//申请用于搜素的空间
    strcpy(ins,Insert);
    strcpy(ser,Search);
    strcat(ins,"\n");
    strcat(ser,"\n");
    file=fopen(filename,"a+");
    new_file=fopen("temp.txt","a+");
    rewind(file);
    while(!feof(file))
    {//在搜索到目标行之前将数据复制到新文件中
        fgets(locate,lenth,file);
        fputs(locate,new_file);
        if(!strcmp(locate,ser))
        {//检测到目标行，跳出
            status=1;
            break;
        }
    }
    if(status)
    {
        fputs(ins,new_file);
        while(!feof(file))
        {//将目标行之后的数据复制到新文件当中
            fgets(locate,lenth,file);
            fputs(locate,new_file);
        }
        fclose(file);
        fclose(new_file);
        rename(filename,"old");
        rename("temp.txt",filename);
        remove("old");
        free(locate);//释放内存
        free(ins);
        free(ser);
        return 0;
    }
    else
    {//没有找到时返回错误代码-1
        free(locate);//释放内存
        free(ins);
        free(ser);
        fclose(file);
        fclose(new_file);
        remove("temp.txt");
        return -1;
    }
}
*/

