#ifndef ADMIN
#define ADMIN

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <io.h>
#include "public.h"
//0.登录1.图书入库\n2.图书修改\n3.图书删除\n4.查看图书\n5.导出图书列表\n6.查看所有用户\n7.逾期记录管理
struct account_Admin
{//管理员账号
    int account;//10位数字
    char name[256];//用户名
    char password[17];//暂时明文保存的密码
    //存储格式：acc:1234567890;name:jack;password:passpass12345678;
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
