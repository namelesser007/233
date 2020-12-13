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
//******************������****************
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
//******************�˵�����**************
//****************************************
//****************************************
//****************************************
//****************************************

 void menu()
{
    int a;

printf("\n\t\t**********������**************");
printf("\n\t\t**********1-�����Ϣ**********");
printf("\n\t\t**********2-��ѯ��Ϣ**********");
printf("\n\t\t**********3-ɾ����Ϣ**********");
printf("\n\t\t**********4-�޸���Ϣ**********");
printf("\n\t\t**********5-��ʾ��Ϣ**********");
printf("\n\t\t**********6-�˳����**********");
printf("\n\t\t�������Ӧ���ܵ����֣� ");
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
    printf("\n\t\t��лʹ��!�´��ټ���");
    break;
}
}
//****************************************
//****************************************
//****************************************
//****************************************
//******************��Ӻ���**************
//****************************************
//****************************************
//****************************************
//****************************************
struct record *insert(struct record *head)
{
    struct record * a, * b, * c;
    a = (struct record*)malloc(LEN);
    printf("\n\t\t���벡����Ϣ:");
    printf("\n\t\t�������:");
    scanf("%s", a->number);
    rewind(stdin);
    printf("\n\t\t��������:");
    scanf("%s", a->name);
    rewind(stdin);
    printf("\n\t\t����绰����:");
    scanf("%s", a->phone);
    rewind(stdin);
    printf("\n\t\t�����ַ:");
    scanf("%s", a->adress);
    rewind(stdin);
    printf("\n\t\t�����ʱ�:");
    scanf("%s", a->postcode);
    rewind(stdin);
    printf("\n\t\t����e-mail:");
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
    printf("\t��ӳɹ�!�����ѡ���ܼ�!\n\n");

    n = n + 1;

    return(head);
}
//****************************************
//****************************************
//****************************************
//****************************************
//******************��ѯ����**************
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
        printf("\tͨѶ¼�޸ò��˵���Ϣ��¼!���������룡\n");
        return;
    }
    else
    {
        printf("\t:��ѡ����Ҫ���ҵķ�ʽ:");

        printf("\n\t\t1:���");

        printf("\n\t\t2:����\n");

        printf("\t\t��ѡ���Ӧ������");

        scanf("%d", &a);

        rewind(stdin);

        switch (a)
        {
        case 1:
            printf("\n\t ������Ҫ���Ҳ��˵����:");

            scanf("%s", &Tnumber);

            rewind(stdin);

            b = head;
            while (strcmp(b->number, Tnumber) != 0)
            {
                if (b->next == NULL)
                {
                    printf("\n\tͨѶ¼�޸��û�����Ϣ��¼!���������룡\n");

                    return;
                }
                else
                {
                    c = b->next;

                    b = c;
                }
            }
            printf("\n\t Ҫ���Ҳ��˵Ļ�����ϢΪ:\n");
            printf("\t\t���:%s\n\t\t", b->number);
            printf("\t\t����:%s\n\t\t",b->name);
            printf("\t\t�绰����:%s\n\t\t",b->phone);
            printf("\t\t��ַ:%s\n\t\t", b->adress);
            printf("\t\t�ʱ�:%s\n\t\t",b->postcode);
            printf("\t\t�绰����:%s\n\t\t",b->e_mail);
            break;
        case 2:
        printf("\n\t������Ҫ�Ҳ��˵����� name:");

        scanf("%s",Tname);

            rewind(stdin);

        b = head;
        while (strcmp(b->name, Tname) != 0)
        {
            if (b->next == NULL)
            {
                printf("\n\tͨѶ¼�޴˲�����Ϣ��¼�����������룡\n");

                return;
            }
            else
            {
                c = b->next;

                b = c;
            }
        }
            printf("\n\t Ҫ���Ҳ��˵Ļ�����ϢΪ:\n");
            printf("\t\t���:%s\n", b->number);
            printf("\t\t����:%s\n",b->name);
            printf("\t\t�绰����:%s\n",b->phone);
            printf("\t\t��ַ:%s\n", b->adress);
            printf("\t\t�ʱ�:%s\n",b->postcode);
            printf("\t\t�绰����:%s\n",b->e_mail);
        break;
        }
    }
}

//****************************************
//****************************************
//****************************************
//****************************************
//******************��ʾ����**************
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
        printf("\t\t�޲�����Ϣ��¼�����������룡\n ");
    }
    else
    {
        for (i = 1; i <= n; i++)
        {
            printf("\n\t��%d�����˵Ļ�����ϢΪ:", i);
            printf("\t\t���:%s\n", b->number);
            printf("\t\t����:%s\n",b->name);
            printf("\t\t�绰����:%s\n",b->phone);
            printf("\t\t��ַ:%s\n", b->adress);
            printf("\t\t�ʱ�:%s\n",b->postcode);
            printf("\t\t�绰����:%s\n",b->e_mail);
            c = b->next;

            b = c;
        }
    }
}

//****************************************
//****************************************
//****************************************
//****************************************
//******************�޸ĺ���**************
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
        printf("\t\t�޲�����Ϣ��¼�����������룡\n");
        return(head);
    }
    printf("\t������Ҫ�޸ĵĲ��˵����:");
    scanf("%s", alter_number);
    rewind(stdin);
    while (strcmp(b->number, alter_number) != 0)
    {
        if (b->next == NULL)
        {
            printf("\n\t�޴˲�����Ϣ��¼�����������룡\n");

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
        printf("ͨ�޴˲�����Ϣ��¼�����������룡\n");

        return (head);
    }
    else
    {
        printf("\tҪ�޸ĵĲ��˵Ļ�����ϢΪ:\n");
            printf("\t\t���:%s\n", b->number);
            printf("\t\t����:%s\n",b->name);
            printf("\t\t�绰����:%s\n",b->phone);
            printf("\t\t��ַ:%s\n", b->adress);
            printf("\t\t�ʱ�:%s\n",b->postcode);
            printf("\t\t�绰����:%s\n",b->e_mail);
    }
    while (1)
    {
        if(a==0)
        {
            printf("\t ���Ƿ�Ҫ�޸Ĳ��˵Ļ�����Ϣ? (y&n)");
        }
        if(a==1)
        {
            printf("\t��ǰ��Ŀ�޸ĳɹ���\n");
            printf("\t ���Ƿ�Ҫ�����޸Ĳ��˵Ļ�����Ϣ? (y&n)");
        }
        scanf("%c", &choice2);
        rewind(stdin);
        if (choice2 == 'y')
        {
            printf("\t��ѡ����Ҫ�޸ĵ���Ŀ:\n");
            printf("\t\t1:����;\n");
            printf("\t\t2:�绰����;\n");
            printf("\t\t3:��ַ;\n");
            printf("\t\t4:�ʱ�;\n");
            printf("\t\t5:e_mail;\n");
            printf("\t��������Ҫ�޸���Ŀ�����:");
            scanf("%d", &choice1);
            rewind(stdin);
            switch (choice1)
            {
            case 1: printf("\t��������ĺ������:");
                scanf("%s", alter_name);
                rewind(stdin);
                strcpy(b->name, alter_name);
                a=1;
                continue;

            case 2: printf("\t��������ĺ�ĵ绰����:");
                scanf("%s", alter_phone);
                rewind(stdin);
                strcpy(b->phone, alter_phone);
                a=1;
                continue;

            case 3:printf("\t��������ĺ�ĵ�ַ:");
                scanf("%s", alter_adress);
                rewind(stdin);
                strcpy(b->adress, alter_adress);
                a=1;
                continue;

            case 4: printf("\t��������ĺ���ʱ�");
                scanf("%s", &alter_postcode);
                rewind(stdin);
                strcpy(b->postcode, alter_postcode);
                a=1;
                continue;

            case 5: printf("\t��������ĺ��e_mail:");
                scanf("%s", alter_e_mail);
                rewind(stdin);
                strcpy(b->e_mail, alter_e_mail);
                a=1;
                continue;
            }
        }
        else
        {
            printf("\n\t�޸ĺ��˵Ļ�����ϢΪ:\n");
            printf("\t\t���:%s\n", b->number);
            printf("\t\t����:%s\n",b->name);
            printf("\t\t�绰����:%s\n",b->phone);
            printf("\t\t��ַ:%s\n", b->adress);
            printf("\t\t�ʱ�:%s\n",b->postcode);
            printf("\t\t�绰����:%s\n",b->e_mail);
            printf("\n\t�޸Ľ���!\n");
            break;
        }

    }
    return(head);
}

//****************************************
//****************************************
//****************************************
//****************************************
//******************ɾ������**************
//****************************************
//****************************************
//****************************************
//****************************************

struct record*delet(struct record *head)
{
    struct record * b, * c;

    char number[15];

    printf("\t������Ҫɾ�����˵���� number:");

    scanf("%s", &number);

    rewind(stdin);

    if (head==NULL)
    {
        printf("\n\t ��ѯ�޴˲�����Ϣ��¼!!���������룡\n");

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

            printf("\tɾ���ɹ�!�����ѡ���ܼ�!\n\n");
        }
        else
        {
            c = b->next;

            printf("��ɾ���Ĳ��˵����Ϊ:%s\n", number);

            printf("\tɾ���ɹ�!�����ѡ���ܼ�!\n\n");
        }
        n = n - 1;
    }
    else;

        printf("\t��ѯ�޴˸ò��˵���Ϣ��¼!���������룡\n");

    return(head);
}
