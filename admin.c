#include "admin.h"

int Login_Admin()
{//����Ա��¼����½��ɺ���������Ա�˵�
    FILE *file;
    file=fopen("AdminAccount.txt","r");
    struct account_Admin acc;
    char account[16];password[17],pass_check[17],cache[320],swi;
    int is_exist=0;
    do
    {
        printf("�������˺ţ�\n");
        gets(account);
        printf("���������룺\n");
        gets(password);
        while(!feof(file))
        {
            fgets(cache,320,file);
            sscanf(cache,"account:%s name:%s password:%s",acc.account,acc.name,acc.password);
            if(!strcmp(account,acc.account))
            {
                is_exist=1;
                break;
            }
        }
        if(!is_exist)
        {
            printf("�˺Ų����ڣ�\n��ѡ�������\n1.ע�����˺�\n2.��������\n3.�˳�");
            while(1)
            {
                swi=getch();
                if(swi=='1')
                {
                    printf("����ת��ע�����...\n");
                    sleep(1000);
                    Create_Admin();
                    break;
                }
                else if(swi=='2')
                    break;
                else if(swi=='3')
                    return -1;
            }
        }
        else if(is_exist==1)
        {
            if(!strcmp(password,acc.password))
            {
                printf("��¼�ɹ���������ת������Ա����...\n")
                Sleep(1000);
                Admin_menu(acc.name);
            }
            else
            {
                printf("�������\n")
            }
        }
    }while(is_exist==0);
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
        fprintf(ac_data,"account:%d name:%s password:%s\n",new_acc.account,new_acc.name,new_acc.password);
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
            case(1):
                break;
            case(2):
                break;
            case(3):
                break;
            case(4):
                break;
            case(5):
                break;
            case(6):
                break;
            case(7):
                break;
        }
    }
}

int add_book()
{
    //���ļ�����ӵ���ͼ��ļ�¼
    //�ɹ�����0
    FILE *book_file;
    struct book_log new_book;
    struct book_log check;
    char cache[1000],*Null,choice;
    int book_num,is_exist=0,swi_1=1;
    book_file=fopen("booklist.txt","a+");
    while(!feof(book_file))
    {
        fgets(cache,1000,book_file);
        if(cache[0]!='\0')
        {
            sscanf(cache,"num:%d %s %s %s %s %s",&book_num);
        }
        else
            book_num=1000000000;
    }
    book_num++;
    do
    {
        printf("������ͼ�����:");
        gets(new_book.title);
        printf("������ͼ�������:");
        gets(new_book.press);
        printf("������ͼ������:");
        gets(new_book.author);
        printf("������ͼ��۸�:");
        scanf("%f",&new_book.prize);
        printf("������ͼ���������:");
        scanf("%d",&new_book.get);
        rewind(book_file);
        while(!feof(book_file))
        {
            fgets(cache,1000,book_file);
            sscanf(cache,"num:%d %s %s %s prize:%f get:%d",&check.num,check.title,check.press,check.author,&check.prize,Null);
            cut_line(check.title,6,-1);
            cut_line(check.press,6,-1);
            cut_line(check.author,7,-1);
            if(!strcmp(new_book.title,check.title))
            {
                printf("������Ѿ���ͬ��ͼ�飬������Ϊ%������Ϊ%s������%d��\n");
                printf("�Ƿ�ֱ�����Ӹ�ͼ��������(y/n)\n");
                do{
                choice=getch();
                printf("%c",choice);
                if(choice=='y'||choice=='Y');
                {
                    //����
                }
                else if(choice==n
                }while(1)
            }
        }
    }while(swi_1);
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
