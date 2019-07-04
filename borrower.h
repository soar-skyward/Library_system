#ifndef BORROWER
#define BORROWER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <io.h>
#include "public.h"

struct account_Borrower
{//借阅者账号
    int account;//10位数字
    char name[256];//用户名
    char password[17];//暂时明文保存的密码
    char book_log[5][16];//借书记录，一人可最多同时借5本,这里只记录书号
    /*存储格式：account:1234567890 name:jack password:passpass12345678(空格隔开)
                单行最大长度：305
                log_1:书号.个体编号(没有借书的时候记为-1.0)
                etc.
                单行最大长度
    */
};
//函数功能见.c文件相应注释
int login_Borrower();
int Create_Borrower();


#endif // BORROWER
