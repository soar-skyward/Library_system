#include "admin.h"

int Login_Admin()
{//管理员登录，登陆完成后跳至管理员菜单
    FILE *file;
  /*  if(access("AdminAccount.ac",0))//如果账户文件不存在，在创建后写入默认账号
    {
        file=fopen("AdminAccount.txt","a");
        fputs("acc:1000000000 name:admin password:admin",file);
        fclose(file);
    }*/
    file=fopen("AdminAccount.txt","r");
    struct account_Admin acc;
    char account[16],password[17],cache[320];
    int is_exist=0,swi=0;
    do
    {
        printf("请输入账号：");
        gets(account);
        printf("请输入密码：");
        gets(password);
        while(!feof(file))
        {
            fgets(cache,320,file);
            printf("%s\n",cache);
            /*sscanf(cache,"%s",acc.account);
            printf("%s\n",acc.account);
            sscanf(cache,"%s%s",acc.account,acc.name);
            printf("%s\t%s\n",acc.account,acc.name);*/
            sscanf(cache,"%s%s%s",acc.account,acc.name,acc.password);
            printf("%s\t%s\t%s\n",acc.account,acc.name,acc.password);
            cut_line(acc.name,acc.name,5,0);
            cut_line(acc.password,acc.password,9,0);
            cut_line(acc.account,acc.account,4,0);//居然和顺序有关。。。我好像明白了
            printf("%s\n%s\n%s\n",acc.account,acc.name,acc.password);
            if(!strcmp(account,acc.account))
            {
                is_exist=1;
                break;
            }
        }
        if(!is_exist)
        {
            printf("账号不存在！\n请选择操作：\n1.注册新账号\n2.重新输入\n3.退出\n");
            while(swi!=3)
            {
                scanf("%d",&swi);
                fflush(stdin);
                switch(swi)
                {
                    case(1):
                        printf("正在转到注册界面...\n");
                        fclose(file);
                        Sleep(1000);
                        Create_Admin();
                        break;
                    case(2):
                        break;
                    case(3):
                        return -1;
                    default:
                        printf("输入错误！\n");
                }
            }
        }
        else if(is_exist==1)
        {
            if(!strcmp(password,acc.password))
            {
                printf("登录成功！正在跳转至管理员界面...\n");
                is_exist=2;
                Sleep(1000);
                Admin_menu(acc.name);
            }
            else
            {
                printf("密码错误！\n");
            }
        }
    }while(is_exist==0);
    fclose(file);
    return 0;
}

int Create_Admin()
{//创建管理员账号

    int debug=0;
    FILE *ac_data;
    struct account_Admin new_acc;
    char pass_check[17],cache[16],acc_check[10],cho;
    int is_exist=0,s,error_times=0;
    ac_data=fopen("AdminAccount.txt","a+");
    if(access("AdminAccount.ac",0))//如果账户文件不存在，在创建后写入默认账号
        fputs("acc:1000000000 name:admin password:admin\n",ac_data);
    printf("请输入10位学号：");
    gets(new_acc.account);
    printf("请输入姓名：");
    gets(new_acc.name);
    printf("请输入6到16位密码：");
    gets(new_acc.password);
    printf("请再次输入密码：");
    gets(pass_check);
    while(strcmp(new_acc.password,pass_check))
    {//两次密码不一致时重复输入
        error_times++;
        if(error_times>=8)
        {
            printf("错误次数过多，是否退出注册界面？(y/n)");
            while(1)
            {
                cho=getchar();
                if(cho=='y'||cho=='Y')
                    return -1;
                else if(cho=='n'||cho=='N')
                    break;
            }
        }
        printf("两次密码输入不一致，请重新输入\n");
        printf("请输入6到16位密码：");
        gets(new_acc.password);
        printf("请再次输入密码：");
        gets(pass_check);
    }

    printf("检查账号是否存在 %d ",debug++);

    /*while(!feof(ac_data))
    {//检查账号是否存在，若存在，跳出
        printf(" %d ",debug++);
        fgets(cache,MAX_LENTH,ac_data);
        cut_line(cache,acc_check,4,14);
        printf("%s\t%s\n",cache,acc_check);
        if(!strcmp(new_acc.account,acc_check))
        {
            is_exist=1;
            break;
        }
    }

    printf("%d ",debug++);

    //if(is_exist!=0)
    if(0)
    {//存在账号时进行引导，选择操作
        printf("账号%s已经存在，请选择操作：\n1.使用现有账号登录\n2.重新注册\n3.退出\n",acc_check);
        scanf("%d",&s);
        fflush(stdin);
        switch(s)
        {
            case(1):
                fclose(ac_data);
                Login_Admin();
                break;
            case(2):
                fclose(ac_data);
                Create_Admin();
                break;
            case(3):
                fclose(ac_data);
                return 0;
        }
        return 0;
    }
    else*/
    {//将刚注册的账号信息写入账户文件中，并将用户转到登录
        printf("注册成功！正在转到登录界面。。。");
        fprintf(ac_data,"acc:%s name:%s password:%s\n",new_acc.account,new_acc.name,new_acc.password);
        fclose(ac_data);
        Sleep(1000);
        Login_Admin();
        return 0;
    }
}

void Admin_menu(char *name)
{//登录后的菜单
    int swi;
    while(swi!=9)
    {
        printf("欢迎您，%s，请选择操作：\n",name);
        printf("1.单本图书入库\n2.批量图书导入\n3.图书修改\n4.图书删除\n5.查看图书\n6.导出图书列表\n7.查看所有用户\n8.逾期记录管理\n9.退出\n");
        scanf("%d",&swi);
        switch(swi)
        {
            case(1):
                add_book();
                break;
            case(2):
                import_book();
                break;
            case(3):
                change_book();
                break;
            case(4):
                delete_book();
                break;
            case(5):
                check_book_list();
                break;
            case(6):
                export_book();
                break;
            case(7):
                check_user_list();
                break;
            case(8):
                check_overdue();
                break;
            case(9):
                break;
            default:
                printf("输入错误！请重新输入\n");
        }
    }
}

int add_book()
{
    //向文件中添加单本图书的记录
    //成功返回0
    FILE *book_file;
    struct book_log new_book;
    struct book_log check;
    char cache[1000],choice;
    int book_num,swi_1=1,get_num;
    book_file=fopen("booklist.txt","a+");
    while(!feof(book_file))
    {
        fgets(cache,1000,book_file);
        if(cache[0]!='\0')
        {
            sscanf(cache,"num:%d %s %s %s %s %s",&book_num);
        }
        else
            book_num=1000000000;
    }
    book_num++;
    do
    {
        printf("请输入图书标题:");
        gets(new_book.title);
        printf("请输入图书出版社:");
        gets(new_book.press);
        printf("请输入图书作者:");
        gets(new_book.author);
        printf("请输入图书价格:");
        scanf("%f",&new_book.prize);
        printf("请输入图书入库数量:");
        scanf("%d",&new_book.get);
        rewind(book_file);
        while(!feof(book_file))
        {
            fgets(cache,1000,book_file);
            sscanf(cache,"num:%d %s %s %s prize:%f get:%d",&check.num,check.title,check.press,check.author,&check.prize,&get_num);
            cut_line(check.title,check.title,6,0);
            cut_line(check.press,check.press,6,0);
            cut_line(check.author,check.author,7,0);
            if(!strcmp(new_book.title,check.title))
            {//图书重名
                printf("书库中已经有同名图书，出版社为%s，作者为%s，现有%d本\n");
                printf("是否直接增加该图书数量？(是：y/否：n)\n");
                do{
                scanf("%c",&choice);
                if(choice=='y'||choice=='Y')
                {
                    //更改
                }
                else if(choice=='n'||choice=='N')
                {
                    printf("是否重新输入信息？(确定：y/放弃：n)\n");
                    scanf("%c",&choice);
                    if(choice=='y'||choice=='Y')
                        swi_1=1;
                    else if(choice=='n'||choice=='N')
                        swi_1=0;
                    break;
                }
                }while(1);
            }
        }
    }while(swi_1);
    //写入图书信息
    return 0;
}

void import_book()
{
    printf("这是用于批量导入的函数\n");
    printf("开发中\n");

}

void change_book()
{
    printf("这是用于改变单本书的函数\n");
    printf("开发中\n");

}

void delete_book()
{
    printf("这是用于删除单本书的函数\n");
    printf("开发中\n");

}

void check_book_list()
{
    printf("这是用于查看图书列表的函数\n");
    printf("开发中\n");

}

void export_book()
{
    printf("这是用于导出书库的函数\n");
    printf("开发中\n");

}

void check_user_list()
{
    printf("这是用于查看用户列表的函数\n");
    printf("开发中\n");

}

void check_overdue()
{
    printf("这是用于检查用户借书逾期情况的函数\n");
    printf("开发中\n");

}
