#ifndef ADMIN
#define ADMIN

#include "public.h"
//1.��¼2.ע��3.ͼ�����4.��������5.ͼ���޸�6.ͼ��ɾ��7.�鿴ͼ��8.����ͼ���б�9.�鿴�����û�10.���ڼ�¼����
struct account_Admin
{//����Ա�˺�
    char account[10];//10λ����(����int��long������������char�洢)
    char name[256];//�û���
    char password[17];//��ʱ���ı��������
    //�洢��ʽ��account:1234567890 name:jack password:passpass12345678(�ո����)
    //������󳤶ȣ�305(��320����)
};
//�������ܼ�.c�ļ���Ӧע��
int Login_Admin();
int Create_Admin();
int add_book();
void import_book();
void change_book();
void delete_book();
void check_book_list();
void export_book();
void check_user_list();
void check_overdue();

#endif // ADMIN
