#include "public.h"
/*
����ģ�飬����һЩ������������ѯͼ�顢ע���˺�
*/
void cleanScr(int times)
{//���ָ����������Ļ����
    for(int i=0;i<times;i++)
        system("cls");
}
int Create_Admin()
{//��������Ա�˺�
    FILE *ac_data;
    struct account_Admin new_acc;
    char pass_check[17],cache[16];
    int is_exist=0,acc_check,s;
    ac_data=fopen("AdminAccount.ac","a+");
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
        printf("�����������벻һ�£�����������");
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
    }while(feof(ac_data)==0);
    if(is_exist!=0)
    {
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
    {
        printf("ע��ɹ�������ת����¼���档����");
        login_Admin();
    }
}
int Create_Borrower()
{

}

