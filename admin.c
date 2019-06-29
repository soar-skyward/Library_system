#include "admin.h"

int login_Admin()
{

}

int Create_Admin()
{//创建管理员账号
    FILE *ac_data;
    struct account_Admin new_acc;
    char pass_check[17],cache[16];
    int is_exist=0,acc_check,s;
    ac_data=fopen("AdminAccount.ac","a+");
    if(access("AdminAccount.ac",0))//如果账户文件不存在，在创建后写入默认账号
        fputs("acc:1000000000;name:admin;password:admin;",ac_data);
    printf("请输入10位学号：");
    scanf("%d",&new_acc.account);
    printf("请输入姓名：");
    gets(new_acc.name);
    printf("请输入6到16位密码：");
    gets(new_acc.password);
    printf("请再次输入密码：");
    gets(pass_check);
    while(!strcmp(new_acc.password,pass_check))
    {//两次密码不一致时重复输入
        printf("两次密码输入不一致，请重新输入");
        printf("请输入6到16位密码：");
        gets(new_acc.password);
        printf("请再次输入密码：");
        gets(pass_check);
    }
    do
    {//检查账号是否存在，若存在，跳出
        fgets(cache,14,ac_data);//
        sscanf(cache,"acc:%d",&acc_check);
        if(new_acc.account==acc_check)
        {
            is_exist=1;
            break;
        }
    }while(feof(ac_data)==0);
    if(is_exist!=0)
    {
        printf("账号%d已经存在，请选择操作：\n1.使用现有账号登录\n2.重新注册\n3.退出\n",acc_check);
        scanf("%d",&s);
        switch(s)
        {
            case(1): login_Admin(); break;
            case(2): Create_Admin();break;
            case(3): return 2; break;
        }
    }
    else
    {
        printf("注册成功！正在转到登录界面。。。");
        login_Admin();
    }
}

void Admin_menu(char *name)
{//登录后的菜单
    int swi;
    while(swi!=8)
    {
        printf("欢迎您，%s，请选择操作：\n",name);
        printf("1.单本图书入库\n2.批量图书导入\n3.图书修改\n4.图书删除\n54.查看图书\n6.导出图书列表\n7.查看所有用户\n8.逾期记录管理\n9.退出\n");
        scanf("%d",&swi);
        switch(swi)
        {
            case(1):break;
            case(2):break;
            case(3):break;
            case(4):break;
            case(5):break;
            case(6):break;
            case(7):break;
        }
    }
}

void add_book()
{

}

void import_book()
{

}

void change_book()
{

}

void delete_book()
{

}

void check_book_list()
{

}

void export_book()
{

}

void check_user_list()
{

}

void check_overdue()
{

}
