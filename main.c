#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "admin.h"
#include "borrower.h"
#include "public.h"
/*

*/
int CreateNew()
{//�������û������Ա
    int new_type,value;
    printf("ѡ���½��û����ͣ�\n1.�����û�\n2.����Ա\n");
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
    else printf("�����������������\n");
    }
}

int main()
{
    int swi,re;
    while(swi!=4)
    {
        swi=0;//��ʼ��ѡ���ʼѡ��
        printf("��ӭʹ��ͼ��ݹ���ϵͳ\n");
        printf("1.�û���¼\n2.����Ա��¼\n3.�½��û�\n4.�˳�ϵͳ\n");
        printf("\n��ѡ�������");
        scanf("%d",&swi);
        cleanScr(6);//����
        switch(swi)//����Ӧ����
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
                printf("ͼ��ݹ���ϵͳ���˳�\n");
                break;
            default: printf("�������������ѡ��\n\n");
        }
    }
    printf("ף��������һ�죡\n");
    system("pause");
    return 0;
}
