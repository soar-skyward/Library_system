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
{//��¼��Ĳ˵�
    char *p_name;
    int acc,swi;
    struct account_Admin login_a=login_Admin();
    p_name=login_a.name;
    acc=login_a.account;
    if(p_name[0]!='\0')
    {
        while(swi!=8)
        printf("��ӭ����%s����ѡ�������\n",p_name);
        printf("1.����ͼ�����\n2.����ͼ�鵼��\n3.ͼ���޸�\n4.ͼ��ɾ��\n54.�鿴ͼ��\n6.����ͼ���б�\n7.�鿴�����û�\n8.���ڼ�¼����\n9.�˳�\n");
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
