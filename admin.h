#ifndef ADMIN
#define ADMIN

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <io.h>
#include "public.h"
//1.��¼2.ע��3.ͼ�����4.��������5.ͼ���޸�6.ͼ��ɾ��7.�鿴ͼ��8.����ͼ���б�9.�鿴�����û�10.���ڼ�¼����
struct account_Admin
{//����Ա�˺�
    int account;//10λ����
    char name[256];//�û���
    char password[17];//��ʱ���ı��������
    //�洢��ʽ��acc:1234567890;name:jack;password:passpass12345678;
};
//�������ܼ�.c�ļ���Ӧע��
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
