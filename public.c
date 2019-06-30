#include "public.h"
/*
公共模块，负责一些基本操作：查询图书、注册账号
*/
void cleanScr(int times)
{//清除指定行数的屏幕内容
    for(int i=0;i<times;i++)
        system("cls");
}

int change_line(char *filename,char *origin,char *modified,int max_lenth)
{
    //改变文件中某一行的数据，输入文件名、想要修改的某一行和修改后的字符串、文件中字符串最大长度
    //在使用前需关闭文件，执行完再重新打开
    /*
        已知缺陷：当文件中有多行相同的数据时无法作用(只修改第一次出现的，看情况改进)
                  当某行数据的前lenth个字符正好是*origin包含内容时会误报
    */
    FILE *file,*new_file;
    char *locate;
    int status=0;
    file=fopen(filename,"a+");
    new_file=fopen("temp.txt","a+");
    locate=(char*)malloc(sizeof(char)*(max_lenth+1));//申请用于搜素的空间
    for(int i=0;i<=max_lenth;i++)
    {
        locate[i]='\0'//初始化空间，防止出问题s
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
