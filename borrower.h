#ifndef BORROWER
#define BORROWER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <io.h>
#include "public.h"

struct account_Borrower
{//�������˺�
    int account;//10λ����
    char name[256];//�û���
    char password[17];//��ʱ���ı��������
    char book_log[5][16];//�����¼��һ�˿����ͬʱ��5��,����ֻ��¼���
    /*�洢��ʽ��account:1234567890 name:jack password:passpass12345678(�ո����)
                ������󳤶ȣ�305
                log_1:���.������(û�н����ʱ���Ϊ-1.0)
                etc.
                ������󳤶�
    */
};
//�������ܼ�.c�ļ���Ӧע��
int login_Borrower();
int Create_Borrower();


#endif // BORROWER
