#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "admin.h"
#include "borrower.h"
#include "public.h"
/*

*/
int CreateNew()
{//创建新用户或管理员
    int new_type,value;
    printf("选择新建用户类型：\n1.借阅用户\n2.管理员\n");
    scanf("%d",&new_type);
    while(1)
    {
    if(new_type==1)
    {
        value=Create_Borrower();
        break;
    }
    else if(new_type==2)
    {
        value=Create_Admin();
        break;
    }
    else printf("输入错误！请重新输入\n");
    }
}

int main()
{
    int swi,re;
    while(swi!=4)
    {
        swi=0;//初始化选项并开始选择
        printf("欢迎使用图书馆管理系统\n");
        printf("1.用户登录\n2.管理员登录\n3.新建用户\n4.退出系统\n");
        printf("\n请选择操作：");
        scanf("%d",&swi);
        cleanScr(6);//清屏
        switch(swi)//打开相应功能
        {
            case(1):
                login_Borrower();
                break;
            case(2):
                login_Admin();
                break;
            case(3):
                CreateNew();
                break;
            case(4):
                printf("图书馆管理系统已退出\n");
                break;
            default: printf("输入错误！请重新选择\n\n");
        }
    }
    printf("祝您有愉快的一天！\n");
    system("pause");
    return 0;
}
