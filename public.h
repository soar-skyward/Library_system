#ifndef PUBLIC
#define PUBLIC

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <io.h>
#include <windows.h>
#include <conio.h>
#include "admin.h"
#include "borrower.h"

/*
�������ڶ���һЩ����ģ�鶼�����õ��ı������ṹ�Լ�������ͷ�ļ�
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
    int num;//���(10λ���֣����λ��1��ʼ)
    char title[256];//����
    char press[256];//������
    char author[256];//����
    float prize;//�۸񣨻�˵ΪɶҪ����һ�
    int get;//�����������С1�����100��
    /*
    �洢��ʽ��num:1234567890 title:256*char press:256*char author:256*char prize:9*char(max) had:3*char
    ��������ַ�����800+������1000���㣩
    */
};
//�������ܼ�.c�ļ���Ӧע��
void cleanScr(int times);
void cut_line(char *ori,int Start,int End);
int change_line(char *filename,char *origin,char *modified,int lenth,int mode);
//int delete_line(char *filename,char *target,int lenth);
//int insert_line(char *filename,char *Search,char *Insert,int lenth);
void scan_password(char *str);
#endif // PUBLIC

