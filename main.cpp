#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define LEN sizeof(struct record)

void menu();

struct record* insert(struct record* head);
struct record* delet(struct record* head);
struct record* alter(struct record* head);
void search(struct record* head);
void show(struct record* head);
struct record* head;
int n = 0;

struct record
{
    char number[100];
    char name[15];
    char phone[15];
    char adress[100];
    char postcode[15];
    char e_mail[25];
    struct record* next;
};

//****************************************
//****************************************
//****************************************
//****************************************
//******************主函数****************
//****************************************
//****************************************
//****************************************
//****************************************

 int main()
{
    head = NULL;

    menu();

    rewind(stdin);
}

//****************************************
//****************************************
//****************************************
//****************************************
//******************菜单函数**************
//****************************************
//****************************************
//****************************************
//****************************************

 void menu()
{
    int a;

printf("\n\t\t**********主界面**************");
printf("\n\t\t**********1-添加信息**********");
printf("\n\t\t**********2-查询信息**********");
printf("\n\t\t**********3-删除信息**********");
printf("\n\t\t**********4-修改信息**********");
printf("\n\t\t**********5-显示信息**********");
printf("\n\t\t**********6-退出软件**********");
printf("\n\t\t请输入对应功能的数字： ");
scanf("%d", &a);
rewind(stdin);
printf("\n");
switch (a)
{
case 1:
    head = insert(head);
    rewind(stdin);
    menu();
    break;

case 2:
    search(head);
    rewind(stdin);
    menu();
    break;

case 3:
    head = delet(head);
    rewind(stdin);
    menu();
    break;

case 4:
    head = alter(head);
    rewind(stdin);
    menu();
    break;

case 5:
    show(head);
    rewind(stdin);
    menu();
    break;

default:
    printf("\n\t\t感谢使用!下次再见！");
    break;
}
}
//****************************************
//****************************************
//****************************************
//****************************************
//******************添加函数**************
//****************************************
//****************************************
//****************************************
//****************************************
struct record *insert(struct record *head)
{
    struct record * a, * b, * c;
    a = (struct record*)malloc(LEN);
    printf("\n\t\t输入病人信息:");
    printf("\n\t\t输入序号:");
    scanf("%s", a->number);
    rewind(stdin);
    printf("\n\t\t输入姓名:");
    scanf("%s", a->name);
    rewind(stdin);
    printf("\n\t\t输入电话号码:");
    scanf("%s", a->phone);
    rewind(stdin);
    printf("\n\t\t输入地址:");
    scanf("%s", a->adress);
    rewind(stdin);
    printf("\n\t\t输入邮编:");
    scanf("%s", a->postcode);
    rewind(stdin);
    printf("\n\t\t输入e-mail:");
    scanf("%s", a->e_mail);
    rewind(stdin);
    if (head==NULL)
    {
        head = a;

        a->next = NULL;
    }
    else
    {
        b = head;
        while ((strcmp(a->number, b->number) > 0) && (b->next != NULL))
        {
            c = b;

            b = b->next;
        }
        if (strcmp(a->number, b->number) <= 0)
        {
            if (head == b)

                head = a;
            else
                c->next = a;

            a->next = b;
        }
        else
        {
            b->next = a;

            a->next = NULL;
        }
    }
    printf("\t添加成功!请继续选择功能键!\n\n");

    n = n + 1;

    return(head);
}
//****************************************
//****************************************
//****************************************
//****************************************
//******************查询函数**************
//****************************************
//****************************************
//****************************************
//****************************************

void search(struct record *head)
{
    int a;

    char Tname[20], Tnumber[10];

    struct record * b, * c;

    if (head == NULL)
    {
        printf("\t通讯录无该病人的信息记录!请重新输入！\n");
        return;
    }
    else
    {
        printf("\t:请选择你要查找的方式:");

        printf("\n\t\t1:序号");

        printf("\n\t\t2:姓名\n");

        printf("\t\t请选择对应的数字");

        scanf("%d", &a);

        rewind(stdin);

        switch (a)
        {
        case 1:
            printf("\n\t 请输入要查找病人的序号:");

            scanf("%s", &Tnumber);

            rewind(stdin);

            b = head;
            while (strcmp(b->number, Tnumber) != 0)
            {
                if (b->next == NULL)
                {
                    printf("\n\t通讯录无该用户的信息记录!请重新输入！\n");

                    return;
                }
                else
                {
                    c = b->next;

                    b = c;
                }
            }
            printf("\n\t 要查找病人的基本信息为:\n");
            printf("\t\t序号:%s\n\t\t", b->number);
            printf("\t\t姓名:%s\n\t\t",b->name);
            printf("\t\t电话号码:%s\n\t\t",b->phone);
            printf("\t\t地址:%s\n\t\t", b->adress);
            printf("\t\t邮编:%s\n\t\t",b->postcode);
            printf("\t\t电话号码:%s\n\t\t",b->e_mail);
            break;
        case 2:
        printf("\n\t请输入要找病人的姓名 name:");

        scanf("%s",Tname);

            rewind(stdin);

        b = head;
        while (strcmp(b->name, Tname) != 0)
        {
            if (b->next == NULL)
            {
                printf("\n\t通讯录无此病人信息记录！请重新输入！\n");

                return;
            }
            else
            {
                c = b->next;

                b = c;
            }
        }
            printf("\n\t 要查找病人的基本信息为:\n");
            printf("\t\t序号:%s\n", b->number);
            printf("\t\t姓名:%s\n",b->name);
            printf("\t\t电话号码:%s\n",b->phone);
            printf("\t\t地址:%s\n", b->adress);
            printf("\t\t邮编:%s\n",b->postcode);
            printf("\t\t电话号码:%s\n",b->e_mail);
        break;
        }
    }
}

//****************************************
//****************************************
//****************************************
//****************************************
//******************显示函数**************
//****************************************
//****************************************
//****************************************
//****************************************

void show(struct record* head)
{
    int i;

    struct record* b, * c;

    b = head;
    if (head == NULL)
    {
        printf("\t\t无病人信息记录！请重新输入！\n ");
    }
    else
    {
        for (i = 1; i <= n; i++)
        {
            printf("\n\t第%d个病人的基本信息为:", i);
            printf("\t\t序号:%s\n", b->number);
            printf("\t\t姓名:%s\n",b->name);
            printf("\t\t电话号码:%s\n",b->phone);
            printf("\t\t地址:%s\n", b->adress);
            printf("\t\t邮编:%s\n",b->postcode);
            printf("\t\t电话号码:%s\n",b->e_mail);
            c = b->next;

            b = c;
        }
    }
}

//****************************************
//****************************************
//****************************************
//****************************************
//******************修改函数**************
//****************************************
//****************************************
//****************************************
//****************************************

struct record*alter(struct record*head)
{
    struct record* b, * c;
    int a=0;
    int choice1;
    char alter_number[10], alter_name[20], alter_phone[20], alter_adress[40], alter_postcode[10], alter_e_mail[30], choice2;
    b = head;

    if (head == NULL)
    {
        printf("\t\t无病人信息记录！请重新输入！\n");
        return(head);
    }
    printf("\t请输入要修改的病人的序号:");
    scanf("%s", alter_number);
    rewind(stdin);
    while (strcmp(b->number, alter_number) != 0)
    {
        if (b->next == NULL)
        {
            printf("\n\t无此病人信息记录！请重新输入！\n");

            return (head);
        }
        else
        {
            c = b;

            b = b->next;
        }
    }
    if (strcmp(b->number, alter_number) != 0)
    {
        printf("通无此病人信息记录！请重新输入！\n");

        return (head);
    }
    else
    {
        printf("\t要修改的病人的基本信息为:\n");
            printf("\t\t序号:%s\n", b->number);
            printf("\t\t姓名:%s\n",b->name);
            printf("\t\t电话号码:%s\n",b->phone);
            printf("\t\t地址:%s\n", b->adress);
            printf("\t\t邮编:%s\n",b->postcode);
            printf("\t\t电话号码:%s\n",b->e_mail);
    }
    while (1)
    {
        if(a==0)
        {
            printf("\t 你是否要修改病人的基本信息? (y&n)");
        }
        if(a==1)
        {
            printf("\t当前项目修改成功！\n");
            printf("\t 你是否要继续修改病人的基本信息? (y&n)");
        }
        scanf("%c", &choice2);
        rewind(stdin);
        if (choice2 == 'y')
        {
            printf("\t请选择你要修改的项目:\n");
            printf("\t\t1:姓名;\n");
            printf("\t\t2:电话号码;\n");
            printf("\t\t3:地址;\n");
            printf("\t\t4:邮编;\n");
            printf("\t\t5:e_mail;\n");
            printf("\t请输入你要修改项目的序号:");
            scanf("%d", &choice1);
            rewind(stdin);
            switch (choice1)
            {
            case 1: printf("\t请输入更改后的姓名:");
                scanf("%s", alter_name);
                rewind(stdin);
                strcpy(b->name, alter_name);
                a=1;
                continue;

            case 2: printf("\t请输入更改后的电话号码:");
                scanf("%s", alter_phone);
                rewind(stdin);
                strcpy(b->phone, alter_phone);
                a=1;
                continue;

            case 3:printf("\t请输入更改后的地址:");
                scanf("%s", alter_adress);
                rewind(stdin);
                strcpy(b->adress, alter_adress);
                a=1;
                continue;

            case 4: printf("\t请输入更改后的邮编");
                scanf("%s", &alter_postcode);
                rewind(stdin);
                strcpy(b->postcode, alter_postcode);
                a=1;
                continue;

            case 5: printf("\t请输入更改后的e_mail:");
                scanf("%s", alter_e_mail);
                rewind(stdin);
                strcpy(b->e_mail, alter_e_mail);
                a=1;
                continue;
            }
        }
        else
        {
            printf("\n\t修改后病人的基本信息为:\n");
            printf("\t\t序号:%s\n", b->number);
            printf("\t\t姓名:%s\n",b->name);
            printf("\t\t电话号码:%s\n",b->phone);
            printf("\t\t地址:%s\n", b->adress);
            printf("\t\t邮编:%s\n",b->postcode);
            printf("\t\t电话号码:%s\n",b->e_mail);
            printf("\n\t修改结束!\n");
            break;
        }

    }
    return(head);
}

//****************************************
//****************************************
//****************************************
//****************************************
//******************删除函数**************
//****************************************
//****************************************
//****************************************
//****************************************

struct record*delet(struct record *head)
{
    struct record * b, * c;

    char number[15];

    printf("\t请输入要删除病人的序号 number:");

    scanf("%s", &number);

    rewind(stdin);

    if (head==NULL)
    {
        printf("\n\t 查询无此病人信息记录!!请重新输入！\n");

        return(head);
    }
    b = head;

    while (strcmp(number, b->number) != 0 && b->next != NULL)
    {
        c = b;

        b = b->next;
    }
    if (strcmp(number, b->number) == 0)
    {
        if (b == head)
        {
            head = b->next;

            printf("\t删除成功!请继续选择功能键!\n\n");
        }
        else
        {
            c = b->next;

            printf("已删除的病人的序号为:%s\n", number);

            printf("\t删除成功!请继续选择功能键!\n\n");
        }
        n = n - 1;
    }
    else;

        printf("\t查询无此该病人的信息记录!请重新输入！\n");

    return(head);
}
