#ifndef ADMIN
#define ADMIN

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <io.h>
#include "public.h"
//0.��¼1.ͼ�����\n2.ͼ���޸�\n3.ͼ��ɾ��\n4.�鿴ͼ��\n5.����ͼ���б�\n6.�鿴�����û�\n7.���ڼ�¼����
struct account_Admin
{//����Ա�˺�
    int account;//10λ����
    char name[256];//�û���
    char password[17];//��ʱ���ı��������
    //�洢��ʽ��acc:1234567890;name:jack;password:passpass12345678;
};

int login_Admin();

int Create_Admin();
void add_book();
void import_book();
void change_book();
void delete_book();
void check_book_list();
void export_book();
void check_user_list();
void check_overdue();

#endif // ADMIN
