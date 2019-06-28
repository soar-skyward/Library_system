#ifndef PUBLIC
#define PUBLIC

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <io.h>
#include "admin.h"

/*
这是用于定义一些所有模块都可能用到的变量、结构以及函数的头文件
同时兼作更新日志
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
int Create_Admin();
int Create_Borrower();

#endif // PUBLIC

/*
这里是更新日志。。。我保证这东西会传到Github上去的
格式：年.月.日\t日志
2019.6.19   由于复习不下去而创建项目，在创建完成后发现已经是6.20了2333
2019.6.20   修复了强行用颜文字卖萌导致编码变更的bug(这算bug吗)
2019.6.28   基本完善了管理员的登录系统，重新引导了登录逻辑，等待二次检验
*/
