#include "admin.h"

int Login_Admin()
{//����Ա��¼����½��ɺ���������Ա�˵�
    FILE *file;
  /*  if(access("AdminAccount.ac",0))//����˻��ļ������ڣ��ڴ�����д��Ĭ���˺�
    {
        file=fopen("AdminAccount.txt","a");
        fputs("acc:1000000000 name:admin password:admin",file);
        fclose(file);
    }*/
    file=fopen("AdminAccount.txt","r");
    struct account_Admin acc;
    char account[16],password[17],cache[320];
    int is_exist=0,swi=0;
    do
    {
        printf("�������˺ţ�");
        gets(account);
        printf("���������룺");
        gets(password);
        while(!feof(file))
        {
            fgets(cache,320,file);
            printf("%s\n",cache);
            /*sscanf(cache,"%s",acc.account);
            printf("%s\n",acc.account);
            sscanf(cache,"%s%s",acc.account,acc.name);
            printf("%s\t%s\n",acc.account,acc.name);*/
            sscanf(cache,"%s%s%s",acc.account,acc.name,acc.password);
            printf("%s\t%s\t%s\n",acc.account,acc.name,acc.password);
            cut_line(acc.name,acc.name,5,0);
            cut_line(acc.password,acc.password,9,0);
            cut_line(acc.account,acc.account,4,0);//��Ȼ��˳���йء������Һ���������
            printf("%s\n%s\n%s\n",acc.account,acc.name,acc.password);
            if(!strcmp(account,acc.account))
            {
                is_exist=1;
                break;
            }
        }
        if(!is_exist)
        {
            printf("�˺Ų����ڣ�\n��ѡ�������\n1.ע�����˺�\n2.��������\n3.�˳�\n");
            while(swi!=3)
            {
                scanf("%d",&swi);
                fflush(stdin);
                switch(swi)
                {
                    case(1):
                        printf("����ת��ע�����...\n");
                        fclose(file);
                        Sleep(1000);
                        Create_Admin();
                        break;
                    case(2):
                        break;
                    case(3):
                        return -1;
                    default:
                        printf("�������\n");
                }
            }
        }
        else if(is_exist==1)
        {
            if(!strcmp(password,acc.password))
            {
                printf("��¼�ɹ���������ת������Ա����...\n");
                is_exist=2;
                Sleep(1000);
                Admin_menu(acc.name);
            }
            else
            {
                printf("�������\n");
            }
        }
    }while(is_exist==0);
    fclose(file);
    return 0;
}

int Create_Admin()
{//��������Ա�˺�

    int debug=0;
    FILE *ac_data;
    struct account_Admin new_acc;
    char pass_check[17],cache[16],acc_check[10],cho;
    int is_exist=0,s,error_times=0;
    ac_data=fopen("AdminAccount.txt","a+");
    if(access("AdminAccount.ac",0))//����˻��ļ������ڣ��ڴ�����д��Ĭ���˺�
        fputs("acc:1000000000 name:admin password:admin\n",ac_data);
    printf("������10λѧ�ţ�");
    gets(new_acc.account);
    printf("������������");
    gets(new_acc.name);
    printf("������6��16λ���룺");
    gets(new_acc.password);
    printf("���ٴ��������룺");
    gets(pass_check);
    while(strcmp(new_acc.password,pass_check))
    {//�������벻һ��ʱ�ظ�����
        error_times++;
        if(error_times>=8)
        {
            printf("����������࣬�Ƿ��˳�ע����棿(y/n)");
            while(1)
            {
                cho=getchar();
                if(cho=='y'||cho=='Y')
                    return -1;
                else if(cho=='n'||cho=='N')
                    break;
            }
        }
        printf("�����������벻һ�£�����������\n");
        printf("������6��16λ���룺");
        gets(new_acc.password);
        printf("���ٴ��������룺");
        gets(pass_check);
    }

    printf("����˺��Ƿ���� %d ",debug++);

    /*while(!feof(ac_data))
    {//����˺��Ƿ���ڣ������ڣ�����
        printf(" %d ",debug++);
        fgets(cache,MAX_LENTH,ac_data);
        cut_line(cache,acc_check,4,14);
        printf("%s\t%s\n",cache,acc_check);
        if(!strcmp(new_acc.account,acc_check))
        {
            is_exist=1;
            break;
        }
    }

    printf("%d ",debug++);

    //if(is_exist!=0)
    if(0)
    {//�����˺�ʱ����������ѡ�����
        printf("�˺�%s�Ѿ����ڣ���ѡ�������\n1.ʹ�������˺ŵ�¼\n2.����ע��\n3.�˳�\n",acc_check);
        scanf("%d",&s);
        fflush(stdin);
        switch(s)
        {
            case(1):
                fclose(ac_data);
                Login_Admin();
                break;
            case(2):
                fclose(ac_data);
                Create_Admin();
                break;
            case(3):
                fclose(ac_data);
                return 0;
        }
        return 0;
    }
    else*/
    {//����ע����˺���Ϣд���˻��ļ��У������û�ת����¼
        printf("ע��ɹ�������ת����¼���档����");
        fprintf(ac_data,"acc:%s name:%s password:%s\n",new_acc.account,new_acc.name,new_acc.password);
        fclose(ac_data);
        Sleep(1000);
        Login_Admin();
        return 0;
    }
}

void Admin_menu(char *name)
{//��¼��Ĳ˵�
    int swi;
    while(swi!=9)
    {
        printf("��ӭ����%s����ѡ�������\n",name);
        printf("1.����ͼ�����\n2.����ͼ�鵼��\n3.ͼ���޸�\n4.ͼ��ɾ��\n5.�鿴ͼ��\n6.����ͼ���б�\n7.�鿴�����û�\n8.���ڼ�¼����\n9.�˳�\n");
        scanf("%d",&swi);
        switch(swi)
        {
            case(1):
                add_book();
                break;
            case(2):
                import_book();
                break;
            case(3):
                change_book();
                break;
            case(4):
                delete_book();
                break;
            case(5):
                check_book_list();
                break;
            case(6):
                export_book();
                break;
            case(7):
                check_user_list();
                break;
            case(8):
                check_overdue();
                break;
            case(9):
                break;
            default:
                printf("�����������������\n");
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
    char cache[1000],choice;
    int book_num,swi_1=1,get_num;
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
            sscanf(cache,"num:%d %s %s %s prize:%f get:%d",&check.num,check.title,check.press,check.author,&check.prize,&get_num);
            cut_line(check.title,check.title,6,0);
            cut_line(check.press,check.press,6,0);
            cut_line(check.author,check.author,7,0);
            if(!strcmp(new_book.title,check.title))
            {//ͼ������
                printf("������Ѿ���ͬ��ͼ�飬������Ϊ%s������Ϊ%s������%d��\n");
                printf("�Ƿ�ֱ�����Ӹ�ͼ��������(�ǣ�y/��n)\n");
                do{
                scanf("%c",&choice);
                if(choice=='y'||choice=='Y')
                {
                    //����
                }
                else if(choice=='n'||choice=='N')
                {
                    printf("�Ƿ�����������Ϣ��(ȷ����y/������n)\n");
                    scanf("%c",&choice);
                    if(choice=='y'||choice=='Y')
                        swi_1=1;
                    else if(choice=='n'||choice=='N')
                        swi_1=0;
                    break;
                }
                }while(1);
            }
        }
    }while(swi_1);
    //д��ͼ����Ϣ
    return 0;
}

void import_book()
{
    printf("����������������ĺ���\n");
    printf("������\n");

}

void change_book()
{
    printf("�������ڸı䵥����ĺ���\n");
    printf("������\n");

}

void delete_book()
{
    printf("��������ɾ��������ĺ���\n");
    printf("������\n");

}

void check_book_list()
{
    printf("�������ڲ鿴ͼ���б�ĺ���\n");
    printf("������\n");

}

void export_book()
{
    printf("�������ڵ������ĺ���\n");
    printf("������\n");

}

void check_user_list()
{
    printf("�������ڲ鿴�û��б�ĺ���\n");
    printf("������\n");

}

void check_overdue()
{
    printf("�������ڼ���û�������������ĺ���\n");
    printf("������\n");

}
