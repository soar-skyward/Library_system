#ifndef ADMIN
#define ADMIN

#include "public.h"
//1.登录2.注册3.图书入库4.批量导入5.图书修改6.图书删除7.查看图书8.导出图书列表9.查看所有用户10.逾期记录管理
struct account_Admin
{//管理员账号
    char account[10];//10位数字(由于int和long型限制所以用char存储)
    char name[256];//用户名
    char password[17];//暂时明文保存的密码
    //存储格式：account:1234567890 name:jack password:passpass12345678(空格隔开)
    //单行最大长度：305(按320计算)
};
//函数功能见.c文件相应注释
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
