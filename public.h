#ifndef PUBLIC
#define PUBLIC

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <io.h>
#include "admin.h"

/*
�������ڶ���һЩ����ģ�鶼�����õ��ı������ṹ�Լ�������ͷ�ļ�
ͬʱ����������־
*/

struct DATE
{//�洢����
    int year,month,day;
};
struct record
{//�����¼
    char booknum[256];//���(��ʽ����)
    char title[256];//����
    int b_num;//�������˺�
    struct DATE date;//��������
};
struct book_log
{//һ�������Ϣ
    int num;//���
    char title[256];//����
    char press[256];//������
    char author[256];//����
    float prize;//�۸񣨻�˵ΪɶҪ����һ�
    int had;//�������
};
//�������ܼ�.c�ļ���Ӧע��
void cleanScr(int times);
int Create_Admin();
int Create_Borrower();

#endif // PUBLIC

/*
�����Ǹ�����־�������ұ�֤�ⶫ���ᴫ��Github��ȥ��
��ʽ����.��.��\t��־
2019.6.19   ���ڸ�ϰ����ȥ��������Ŀ���ڴ�����ɺ����Ѿ���6.20��2333
2019.6.20   �޸���ǿ�������������ȵ��±�������bug(����bug��)
2019.6.28   ���������˹���Ա�ĵ�¼ϵͳ�����������˵�¼�߼����ȴ����μ���
*/
