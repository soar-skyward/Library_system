#include "admin.h"

int login_Admin()
{//����Ա��¼����½��ɺ���������Ա�˵�
    FILE *account_file;

}

int Create_Admin()
{//��������Ա�˺�
    FILE *ac_data;
    struct account_Admin new_acc;
    char pass_check[17],cache[16],account_cache[310];
    int is_exist=0,acc_check,s;
    ac_data=fopen("AdminAccount.txt","a+");
    if(access("AdminAccount.ac",0))//����˻��ļ������ڣ��ڴ�����д��Ĭ���˺�
        fputs("acc:1000000000;name:admin;password:admin;",ac_data);
    printf("������10λѧ�ţ�");
    scanf("%d",&new_acc.account);
    printf("������������");
    gets(new_acc.name);
    printf("������6��16λ���룺");
    gets(new_acc.password);
    printf("���ٴ��������룺");
    gets(pass_check);
    while(!strcmp(new_acc.password,pass_check))
    {//�������벻һ��ʱ�ظ�����
        printf("�����������벻һ�£�����������\n");
        printf("������6��16λ���룺");
        gets(new_acc.password);
        printf("���ٴ��������룺");
        gets(pass_check);
    }
    do
    {//����˺��Ƿ���ڣ������ڣ�����
        fgets(cache,14,ac_data);//
        sscanf(cache,"acc:%d",&acc_check);
        if(new_acc.account==acc_check)
        {
            is_exist=1;
            break;
        }
    }while(!feof(ac_data));
    if(is_exist!=0)
    {//�����˺�ʱ����������ѡ�����
        printf("�˺�%d�Ѿ����ڣ���ѡ�������\n1.ʹ�������˺ŵ�¼\n2.����ע��\n3.�˳�\n",acc_check);
        scanf("%d",&s);
        switch(s)
        {
            case(1): login_Admin(); break;
            case(2): Create_Admin();break;
            case(3): return 2; break;
        }
    }
    else
    {//����ע����˺���Ϣд���˻��ļ��У������û�ת����¼
        printf("ע��ɹ�������ת����¼���档����");
        fprintf(ac_data,"acc:%d;name:%s;password:%s;\n",new_acc.account,new_acc.name,new_acc.password);
        login_Admin();
    }
}

void Admin_menu(char *name)
{//��¼��Ĳ˵�
    int swi;
    while(swi!=8)
    {
        printf("��ӭ����%s����ѡ�������\n",name);
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
{//���ļ�����ӵ���ͼ��ļ�¼
    FILE *book_file;
    book_file=fopen("booklist.txt","a+")
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
