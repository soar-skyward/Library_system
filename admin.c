#include "admin.h"

struct account_Admin login_Admin()
{
    /*switch(out)
    {
        case(0):break;
        case(1):break;
    }*/
}

void Admin_menu()
{//登录后的菜单
    char *p_name;
    int acc,swi;
    struct account_Admin login_a=login_Admin();
    p_name=login_a.name;
    acc=login_a.account;
    if(p_name[0]!='\0')
    {
        while(swi!=8)
        printf("欢迎您，%s，请选择操作：\n",p_name);
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
