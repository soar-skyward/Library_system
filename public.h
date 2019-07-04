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
这是用于定义一些所有模块都可能用到的变量、结构以及函数的头文件
*/

struct DATE
{//存储日期
    int year,month,day;
};
struct record
{//借书记录
    char booknum[256];//书号(格式待定)
    char title[256];//书名
    int b_num;//借阅者账号
    struct DATE date;//借阅日期
};
struct book_log
{//一本书的信息
    int num;//编号
    char title[256];//标题
    char press[256];//出版社
    char author[256];//作者
    float prize;//价格（话说为啥要有这一项）
    int had;//入库数量
};
//函数功能见.c文件相应注释
void cleanScr(int times);
int change_line(char *filename,char *origin,char *modified,int lenth);
int delete_line(char *filename,char *target,int lenth);
int insert_line(char *filename,char *Search,char *Insert,int lenth);
void scan_password(char *str);

#endif // PUBLIC

