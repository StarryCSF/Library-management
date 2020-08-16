#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
typedef struct _goods
    {
       char name[20];
       int category;
       float prize;
       int shelf_life;
       char time[15];
    }goods;
    goods b[20];
int N;
int switch_num;
int return_num;
char password1[20];
int num_star;
    int input(goods b[],int N);
    void display(goods b[],int N);
    void change(goods b[],int N);
    void _search(goods b[],int N);
    int  _insert(goods b[],int N);
    int  _delete(goods b[],int N);
    void _sort(goods b[],int N);
    void save(goods b[],int N);
    void menu_customer();
    void menu_manager();
    void system_manager();
    void password();
    void modify_password();
    
    int input(goods b[],int N)
    {
        N=0;
        FILE *fp;
        fp=fopen("data.txt","r+");
        if(fp==NULL)
        {
              printf("can't open this file");
              exit(0);
        }
        while(!feof(fp))
        {
             fscanf(fp,"%s%d%f%d%s",b[N].name,&b[N].category,&b[N].prize,&b[N].shelf_life,b[N].time);
             N++;
        }
        Sleep(100);
        printf("恭喜您导入成功");

        return N-1;
     }
   
     void display(goods b[],int N)
     {
        int i;
        for(num_star=0;num_star<18;num_star++)
        {
            printf("*");
            Sleep(5);
        }
        printf("商品信息如下");
        Sleep(50);
        for(num_star=0;num_star<18;num_star++){
            printf("*");
            Sleep(5);
        }
        printf("\n\n");
        printf("图书名称          类别  价格    编号  出厂日期\n");
        for(i=0;i<N;i++){
        printf("%-8s\t%4d\t%.2f\t%4d\t%4s\n",b[i].name,b[i].category,b[i].prize,b[i].shelf_life,b[i].time);
        }
        printf("\n【注；类别1.计算机    2.外语   3.少儿】\n\n");
        for(num_star=0;num_star<48;num_star++)
        {
            printf("*");
            Sleep(5);
        }
        printf("\n\n");
        printf("按1后回车返回");
        scanf("%d",&return_num);
        if(return_num==1)
        {
            system("cls");
            return;
        }
     }
     void change(goods b[],int N)
     {
        int i,n;
        char a[10];
        for(num_star=0;num_star<18;num_star++)
        {
            printf("*");
            Sleep(10);
        }
        printf("欢迎进入修改系统");
        for(num_star=0;num_star<18;num_star++){
            printf("*");
            Sleep(5);
        }
        printf("\n\n");
        printf("-1-请输入需要修改的图书的名称\n   ");
        loop:
        scanf("%s",a);
        for(i=0;i<N;i++)
        {
            if(!strcmp(b[i].name,a))
                break;
        }
        if(i==N)
        {
            printf("\n-1-对不起找不到该书,请重新输入\n   ");
            goto loop;
        }
        else
            printf("\n-2-您需要的修改的图书信息如下：\n   (1)图书名称(2)类别 (3)价格  (4)编号 (5)出厂日期\n   %-9s\t%-3d\t%.2f\t%5d\t%10s\n",b[i].name,b[i].category,b[i].prize,b[i].shelf_life,b[i].time);
            printf("\n-3-请输入需要修改的书籍编号\n   ");
            loop2:
            scanf("%d",&n);
            switch(n)
            {
            case 1:
                printf("\n-4-请输入该书的名称\n   ");
                scanf("%s",b[i].name);
                break;
            case 2:
                printf("\n-4-请选择图书类别*1.外语3.少儿\n   ");
                scanf("%d",&b[i].category);
                break;
            case 3:
                printf("\n-4-请输入该图书的价格\n   ");
                scanf("%f",&b[i].prize);
                break;
            case 4:
                printf("\n-4-请输入该图书的编号*按月计（即输入1-12之间的整数）\n   ");
                scanf("%d",&b[i].shelf_life);
                break;
            case 5:
                printf("\n-4-请输入该图书的出厂日期*例如20170920\n   ");
                scanf("%s",b[i].time);
                break;
            default:
                printf("\n-3-你输入的信息有误请重新输入：\n   ");
                goto loop2;

            }
            printf("\n-5-修改成功\n\n");
            for(num_star=0;num_star<52;num_star++)
            {
                printf("*");
                Sleep(5);
            }
            printf("\n\n");
            printf("按1后回车返回");
            scanf("%d",&return_num);
            if(return_num==1)
            {
            system("cls");
            return;
            }
     }
     
     void _search(goods b[],int N)
     {
        int i,n;
        for(num_star=0;num_star<17;num_star++)
        {
            printf("*");
            Sleep(5);
        }
        printf("欢迎进入搜索系统");

        for(num_star=0;num_star<17;num_star++)
        {
            printf("*");
            Sleep(5);
        }
        printf("\n\n");
           printf("-1-请输入需要查询的内容*1.按名称查询2.按类型查询\n   ");
           scanf("%d",&switch_num);
           switch(switch_num)
           {
                case 1:
                    char a[10];
                    loop:
                    printf("\n-2-请输入需要查询的书的名称:\n   ");
                    scanf("%s",a);
                    for(i=0;i<N;i++)
                    {
                        if(!strcmp(b[i].name,a))
                        {
                            break;
                        }

                    }
                    if(i==N)
                        {
                        printf("\n-2-对不起找不到该图书*1.返回主菜单2.继续查询\n   ");
                        scanf("%d",&switch_num);
                        if(switch_num==1)
                        {
                            goto loop7;
                        }
                        else goto loop;
                    }
                    else
                    {
                    printf("\n-3-您查询的图书信息如下：\n   图书名称       类别  价格    编号  出厂日期\n   %-7s\t%4d\t%.2f\t%4d\t%4s\n",b[i].name,b[i].category,b[i].prize,b[i].shelf_life,b[i].time);
                    break;
                    }
                case 2:
                    int kind,_count=0;
                    printf("\n-2-请输入图书的类别*1.计算机2.外语3.少儿\n   ");
                    loop3:
                    scanf("%d",&kind);
                    printf("\n-3-您查询的图书信息如下：\n   图书名称       类别  价格    编号  出厂日期\n");
                    for(i=0;i<N;i++)
                        {
                        if(b[i].category==kind)
                        {
                            printf("   %-7s\t%4d\t%.2f\t%4d\t%4s\n",b[i].name,b[i].category,b[i].prize,b[i].shelf_life,b[i].time);
                            _count++;
                        }
                    }
                    if(_count==0)
                    {
                    Sleep(100);
                    printf("\n-3-对不起找不到该类别信息请重新输入\n   ");
                    goto loop3;
                    }
           }
                    loop7:
                    printf("\n");
                    for(num_star=0;num_star<50;num_star++)
                    {
                    printf("*");
                    Sleep(5);
                    }
                    printf("\n\n");
                    printf("按1后回车返回");
                    scanf("%d",&return_num);
                    if(return_num==1)
                    {
                    system("cls");
                    return;
                    }
     }
     int _insert(goods b[],int N)
     {
         int n,i=1,t;
        for(num_star=0;num_star<17;num_star++)
        {
            printf("*");
            Sleep(5);
        }
        printf("欢迎进入添加系统");

        for(num_star=0;num_star<17;num_star++)
        {
            printf("*");
            Sleep(5);
        }
         printf("\n\n-1-请输入需要添加的图书的个数：\n   ");
         scanf("%d",&n);
         t=n;
         while(n)
         {
            printf("\n-%d-输入第%d条图书信息:\n",i+1,i);
            printf("   1.名称:");scanf("%s",b[N+i-1].name);
            printf("\n   2.类别*1.计算机2.外语3.少儿：");scanf("%d",&b[N+i-1].category);
            printf("\n   3.价格：");scanf("%f",&b[N+i-1].prize);
            printf("\n   4.编号*按月计（即输入1-12之间的整数)：");scanf("%d",&b[N+i-1].shelf_life);
            printf("\n   5.出厂日期*例如20170920：");scanf("%s",b[N+i-1].time);
            n--;
            i++;
         }
         printf("\n-%d-添加成功\n\n",i+1);
         for(num_star=0;num_star<50;num_star++)
                    {
                    printf("*");
                    Sleep(10);
                    }
        printf("\n\n");
        printf("按1后回车返回");
        scanf("%d",&return_num);
        if(return_num==1)
        {
            system("cls");
            return N+t;
        }
     }
     
     int _delete(goods b[],int N)
     {
        int i,q;
        char c[10];
        for(num_star=0;num_star<16;num_star++)
        {
            printf("*");
            Sleep(5);
        }
        printf("欢迎进入删除系统");

        for(num_star=0;num_star<16;num_star++)
        {
            printf("*");
            Sleep(10);
        }
        printf("\n\n-1-请输入需要删除的图书的名称\n   ");
        loop4:
        scanf("%s",c);
        for(i=0;i<N;i++)
        {
            if(!strcmp(b[i].name,c))
                break;
        }
        if(i==N)
        {
            printf("\n-1-对不起找不到该图书,请重新输入\n   ");
            goto loop4;
        }
        else
            printf("\n-1-您删除的图书信息如下：\n   图书名称       类别  价格    编号  出厂日期\n   %-7s\t%4d\t%.2f\t%4d\t%4s\n",b[i].name,b[i].category,b[i].prize,b[i].shelf_life,b[i].time);
            printf("\n-2-确认删除？*1.确认2.取消\n   ");
            loop5:
            scanf("%d",&q);
            if(q!=2&&q!=1)
            {
                printf("错误请重新输入");
                goto loop5;
            }
            else if(q==1)
            {
                while(i<N-1)
                {
                    b[i]=b[i+1];
                    i++;
                }
                printf("\n-3-删除成功\n\n");
            for(num_star=0;num_star<48;num_star++)
        {
            printf("*");
            Sleep(5);
        }
        printf("\n\n");
                printf("按1后回车返回");
                scanf("%d",&return_num);
                if(return_num==1)
        {
                system("cls");
                return N-1;
        }

            }
            else
            printf("\n");
            for(num_star=0;num_star<50;num_star++){
                printf("*");
                Sleep(5);
            }
            printf("\n\n\n");
            printf("按1后回车返回");
            scanf("%d",&return_num);
            if(return_num==1)
            {
            system("cls");
            return N;
            }

     }
   
     void save(goods b[],int N)
     {
            int i;
            FILE *point;
            point=fopen("data.txt","w");
            if(point==NULL)
            {
                printf("can't find the file");
                exit(0);
            }
            for(i=0;i<N;i++)
            fprintf(point,"%-8s\t%4d\t%.2f\t%4d\t%4s\n",b[i].name,b[i].category,b[i].prize,b[i].shelf_life,b[i].time);
            printf("恭喜导出成功");
            fclose(point);
     }
  
     void _sort(goods b[],int N)
     {
            goods temp;
            int n,i,j;
        for(num_star=0;num_star<16;num_star++)
        {
            printf("*");
            Sleep(5);
        }
        printf("欢迎进入排序系统");
        for(num_star=0;num_star<16;num_star++)
        {
            printf("*");
            Sleep(5);
        }
            printf("\n\n-1-请问您需要按什么排序【1价格        2出厂日期】\n   ");
            scanf("%d",&switch_num);
            switch(switch_num)
            {
            case 1:
                printf("\n-2-请选择排序类型【1.价格从高到低排序2.从低到高】\n   ");
                loop5:
                scanf("%d",&switch_num);
                if(switch_num==1)
                    {
                    for(i=0;i<N-1;i++)
                    {
                        for(j=0;j<N-1-i;j++)
                        {
                            if(b[j].prize<b[j+1].prize)
                            {
                                    temp=b[j];
                                    b[j]=b[j+1];
                                    b[j+1]=temp;
                            }
                        }

                    }
                }
                else if(switch_num==2)
                    {
                    for(i=0;i<N-1;i++)
                    {
                        for(j=0;j<N-1-i;j++)
                        {
                            if(b[j].prize>b[j+1].prize)
                            {
                                    temp=b[j];
                                    b[j]=b[j+1];
                                    b[j+1]=temp;
                            }
                        }
                    }
                }
                else{
                    printf("输入错误请重新输入：\n");
                    goto loop5;
                }
                break;


            case 2:
                {
                printf("\n-2-请选择排序类型【1.出厂日期从早到晚2.从晚到早】\n   ");
                loop6:
                scanf("%d",&switch_num);
                if(switch_num==1)
                    {
                    for(i=0;i<N-1;i++)
                    {
                        for(j=0;j<N-1-i;j++)
                        {
                            if(strcmp(b[j].time,b[j+1].time)>0)
                            {
                                    temp=b[j];
                                    b[j]=b[j+1];
                                    b[j+1]=temp;

                            }
                        }
                    }
                }


                else if(switch_num==2)
                    {
                    for(i=0;i<N-1;i++)
                    {
                        for(j=0;j<N-1-i;j++)
                        {
                            if(strcmp(b[j].time,b[j+1].time)<0)
                            {
                                    temp=b[j];
                                    b[j]=b[j+1];
                                    b[j+1]=temp;
                            }
                        }
                    }
                }
                else{
                    printf("\n-2-输入错误请重新输入：\n   ");
                    goto loop6;
                }
                break;
            }
            default: return;
     }
     printf("\n-3-排序成功【欲显示结果返回主菜单并执行显示功能】\n\n");
     for(num_star=0;num_star<48;num_star++){
                    printf("*");
                    Sleep(5);
     }
     printf("\n\n");
     printf("按1后回车返回");
     scanf("%d",&return_num);
     if(return_num==1)
     {
            system("cls");
            return;
     }
     return;
     }
     void menu_customer()
    {
       printf("\n                 欢迎进入客户查询系统！                     \n");
       printf("*********************系统功能菜单************************\n");
       printf("|                ___1:图书信息导入___                   |\n");
       printf("|                ___2:图书信息显示___                   |\n");
       printf("|                ___3:图书信息查询___                   |\n");
       printf("|                ___4:图书信息排序___                   |\n");
       printf("|                ___0:退出管理系统___                   |\n");
       printf("---------------------------------------------------------\n");
	   printf("*********************************************************\n\n");
	   printf("请先导入文件再进行其他操作！\n输入以上序号使用其功能：\n");

    }
    void menu_manager()
{
    printf("\n                书图书信息管理员系统                   \n\n");
	printf("*********************系统功能菜单************************\n");
	printf("---------------------------------------------------------\n");
	printf("|                ___1:图书信息导入___                   |\n");
	printf("|                ___2:图书信息显示___                   |\n");
	printf("|                ___3:图书信息添加___                   |\n");
	printf("|                ___4:图书信息删除___                   |\n");
	printf("|                ___5:图书信息修改___                   |\n");
	printf("|                ___6:图书信息查询___                   |\n");
	printf("|                ___7:图书信息排序___                   |\n");
	printf("|                ___8:图书信息导出___                   |\n");
	printf("|                ___9:修改登入密码___                   |\n");
    printf("|                ___0:退出管理系统___                   |\n");
	printf("---------------------------------------------------------\n");
	printf("*********************************************************\n\n");
	printf("请先导入文件再进行其他操作！\n输入以上序号使用其功能：\n");
}

void password()
{
    int count=0;
    char a[20];
    FILE *fp;
    fp=fopen("password.txt","r+");
    if(fp==NULL)
        {
              printf("对不起找不到密码");
              exit(0);
        }
    fscanf(fp,"%s",password1);
    printf("*************欢迎进入图书信息管理系统登录窗口*************\n\n\n");
    printf("请输入密码(初始化密码1)：");
    scanf("%s",a);
    while(count<2)
    {
        if(strcmp(password1,a))
            {
                printf("\n************密码错误,您还有%d次机会，请谨慎输入密码************\n\n",2-count);
                printf("请再次输入密码");
                scanf("%s",a);
                count++;
            }
        else goto loop;
    }
        if(!strcmp(password1,a))
            goto loop;
        printf("\n*****************密码错误次数过多,请稍后再试******************\n");
        exit(0);
        loop:
            system("cls");
            printf("*********************欢迎进入系统************************\n");
            system("cls");
    printf("请稍等.");
    Sleep(200);
    system("cls");
    printf("请稍等..");
    Sleep(200);
    system("cls");
    printf("请稍等...");
            Sleep(200);
        fclose(fp);
}

void modify_password()
{
    FILE *fp;
    fp=fopen("password.txt","w+");
    char new_password[20];
    char confirm_password[20];
    for(num_star=0;num_star<14;num_star++)
        {
            printf("*");
            Sleep(5);
        }
    printf("欢迎进入密码修改系统");
    for(num_star=0;num_star<14;num_star++)
    {
            printf("*");
            Sleep(5);
    }
    printf("\n\n-1-请输入新密码：\n   ");
    scanf("%s",new_password);
    printf("\n-2-请确认密码:\n   ");
    scanf("%s",confirm_password);
    if(!strcmp(new_password,confirm_password))
    {
        printf("\n-3-修改成功");
        fprintf(fp,"%s",new_password);
        fclose(fp);
    }
    else
        printf("\n-3-两次密码不相同修改失败");
    printf("\n\n");
    for(num_star=0;num_star<48;num_star++)
    {
            printf("*");
            Sleep(5);
    }
    printf("\n\n");
    printf("按1后回车返回");
    scanf("%d",&return_num);
    if(return_num==1)
     {
            system("cls");
            return;
     }
}

void system_manager()
{
    system("cls");
    password();
    system("cls");
	int i=1;
	while(i)
	{
        menu_manager();
        scanf("%d",&i);
		switch (i)
		{
            case 1: system("cls");
                    N=input(b,N);break;

            case 2: system("cls");
                    display(b,N);break;

            case 3: system("cls");
                    N=_insert(b,N);break;

			case 4: system("cls");
                    N=_delete(b,N);break;

            case 5: system("cls");
                    change(b,N);break;

            case 6: system("cls");
                    _search(b,N);break;

            case 7: system("cls");
                    _sort(b,N);break;

            case 8: system("cls");
                    save(b,N);break;

            case 9: system("cls");
                    modify_password();break;


            case 0:printf("*********************感谢使用！**************************");
			break;

            default:
			printf("项目不存在\n");
			break;
		}
	}
	return;
}

void system_customer()
{
	
    system("cls");
    printf("请稍等.");
    Sleep(200);
    system("cls");
    printf("请稍等..");
    Sleep(200);
    system("cls");
    printf("请稍等...");
    Sleep(700);
    system("cls");
    int i=1;
    while(i)
	{
        menu_customer();
        scanf("%d",&i);
		switch (i)
		{
            case 1: system("cls");
                    N=input(b,N);break;

            case 2: system("cls");
                    display(b,N);break;

            case 3: system("cls");
                    _search(b,N);break;

            case 4: system("cls");
                    _sort(b,N);break;

            case 0:printf("*********************感谢使用！**************************");
			break;
            default:
			printf("项目不存在\n");
			break;
		}
	}
	return;
}

int main()
{
    printf("*********************请选择进入客户系统或管理员系统*********************\n");
    printf("    *********************1=客户系统，2=管理员系统*********************\n");
    printf("                                  请选择：                    \n");
    loop7:
    scanf("%d",&switch_num);
    switch(switch_num)
    {
    case 1:
        system_customer();
        break;
    case 2:
        system_manager();
        break;
    default:
        printf("错误信息，请重新输入：");
        goto loop7;
    }
}
