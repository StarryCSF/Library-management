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
        printf("��ϲ������ɹ�");

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
        printf("��Ʒ��Ϣ����");
        Sleep(50);
        for(num_star=0;num_star<18;num_star++){
            printf("*");
            Sleep(5);
        }
        printf("\n\n");
        printf("ͼ������          ���  �۸�    ���  ��������\n");
        for(i=0;i<N;i++){
        printf("%-8s\t%4d\t%.2f\t%4d\t%4s\n",b[i].name,b[i].category,b[i].prize,b[i].shelf_life,b[i].time);
        }
        printf("\n��ע�����1.�����    2.����   3.�ٶ���\n\n");
        for(num_star=0;num_star<48;num_star++)
        {
            printf("*");
            Sleep(5);
        }
        printf("\n\n");
        printf("��1��س�����");
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
        printf("��ӭ�����޸�ϵͳ");
        for(num_star=0;num_star<18;num_star++){
            printf("*");
            Sleep(5);
        }
        printf("\n\n");
        printf("-1-��������Ҫ�޸ĵ�ͼ�������\n   ");
        loop:
        scanf("%s",a);
        for(i=0;i<N;i++)
        {
            if(!strcmp(b[i].name,a))
                break;
        }
        if(i==N)
        {
            printf("\n-1-�Բ����Ҳ�������,����������\n   ");
            goto loop;
        }
        else
            printf("\n-2-����Ҫ���޸ĵ�ͼ����Ϣ���£�\n   (1)ͼ������(2)��� (3)�۸�  (4)��� (5)��������\n   %-9s\t%-3d\t%.2f\t%5d\t%10s\n",b[i].name,b[i].category,b[i].prize,b[i].shelf_life,b[i].time);
            printf("\n-3-��������Ҫ�޸ĵ��鼮���\n   ");
            loop2:
            scanf("%d",&n);
            switch(n)
            {
            case 1:
                printf("\n-4-��������������\n   ");
                scanf("%s",b[i].name);
                break;
            case 2:
                printf("\n-4-��ѡ��ͼ�����*1.����3.�ٶ�\n   ");
                scanf("%d",&b[i].category);
                break;
            case 3:
                printf("\n-4-�������ͼ��ļ۸�\n   ");
                scanf("%f",&b[i].prize);
                break;
            case 4:
                printf("\n-4-�������ͼ��ı��*���¼ƣ�������1-12֮���������\n   ");
                scanf("%d",&b[i].shelf_life);
                break;
            case 5:
                printf("\n-4-�������ͼ��ĳ�������*����20170920\n   ");
                scanf("%s",b[i].time);
                break;
            default:
                printf("\n-3-���������Ϣ�������������룺\n   ");
                goto loop2;

            }
            printf("\n-5-�޸ĳɹ�\n\n");
            for(num_star=0;num_star<52;num_star++)
            {
                printf("*");
                Sleep(5);
            }
            printf("\n\n");
            printf("��1��س�����");
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
        printf("��ӭ��������ϵͳ");

        for(num_star=0;num_star<17;num_star++)
        {
            printf("*");
            Sleep(5);
        }
        printf("\n\n");
           printf("-1-��������Ҫ��ѯ������*1.�����Ʋ�ѯ2.�����Ͳ�ѯ\n   ");
           scanf("%d",&switch_num);
           switch(switch_num)
           {
                case 1:
                    char a[10];
                    loop:
                    printf("\n-2-��������Ҫ��ѯ���������:\n   ");
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
                        printf("\n-2-�Բ����Ҳ�����ͼ��*1.�������˵�2.������ѯ\n   ");
                        scanf("%d",&switch_num);
                        if(switch_num==1)
                        {
                            goto loop7;
                        }
                        else goto loop;
                    }
                    else
                    {
                    printf("\n-3-����ѯ��ͼ����Ϣ���£�\n   ͼ������       ���  �۸�    ���  ��������\n   %-7s\t%4d\t%.2f\t%4d\t%4s\n",b[i].name,b[i].category,b[i].prize,b[i].shelf_life,b[i].time);
                    break;
                    }
                case 2:
                    int kind,_count=0;
                    printf("\n-2-������ͼ������*1.�����2.����3.�ٶ�\n   ");
                    loop3:
                    scanf("%d",&kind);
                    printf("\n-3-����ѯ��ͼ����Ϣ���£�\n   ͼ������       ���  �۸�    ���  ��������\n");
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
                    printf("\n-3-�Բ����Ҳ����������Ϣ����������\n   ");
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
                    printf("��1��س�����");
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
        printf("��ӭ�������ϵͳ");

        for(num_star=0;num_star<17;num_star++)
        {
            printf("*");
            Sleep(5);
        }
         printf("\n\n-1-��������Ҫ��ӵ�ͼ��ĸ�����\n   ");
         scanf("%d",&n);
         t=n;
         while(n)
         {
            printf("\n-%d-�����%d��ͼ����Ϣ:\n",i+1,i);
            printf("   1.����:");scanf("%s",b[N+i-1].name);
            printf("\n   2.���*1.�����2.����3.�ٶ���");scanf("%d",&b[N+i-1].category);
            printf("\n   3.�۸�");scanf("%f",&b[N+i-1].prize);
            printf("\n   4.���*���¼ƣ�������1-12֮�������)��");scanf("%d",&b[N+i-1].shelf_life);
            printf("\n   5.��������*����20170920��");scanf("%s",b[N+i-1].time);
            n--;
            i++;
         }
         printf("\n-%d-��ӳɹ�\n\n",i+1);
         for(num_star=0;num_star<50;num_star++)
                    {
                    printf("*");
                    Sleep(10);
                    }
        printf("\n\n");
        printf("��1��س�����");
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
        printf("��ӭ����ɾ��ϵͳ");

        for(num_star=0;num_star<16;num_star++)
        {
            printf("*");
            Sleep(10);
        }
        printf("\n\n-1-��������Ҫɾ����ͼ�������\n   ");
        loop4:
        scanf("%s",c);
        for(i=0;i<N;i++)
        {
            if(!strcmp(b[i].name,c))
                break;
        }
        if(i==N)
        {
            printf("\n-1-�Բ����Ҳ�����ͼ��,����������\n   ");
            goto loop4;
        }
        else
            printf("\n-1-��ɾ����ͼ����Ϣ���£�\n   ͼ������       ���  �۸�    ���  ��������\n   %-7s\t%4d\t%.2f\t%4d\t%4s\n",b[i].name,b[i].category,b[i].prize,b[i].shelf_life,b[i].time);
            printf("\n-2-ȷ��ɾ����*1.ȷ��2.ȡ��\n   ");
            loop5:
            scanf("%d",&q);
            if(q!=2&&q!=1)
            {
                printf("��������������");
                goto loop5;
            }
            else if(q==1)
            {
                while(i<N-1)
                {
                    b[i]=b[i+1];
                    i++;
                }
                printf("\n-3-ɾ���ɹ�\n\n");
            for(num_star=0;num_star<48;num_star++)
        {
            printf("*");
            Sleep(5);
        }
        printf("\n\n");
                printf("��1��س�����");
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
            printf("��1��س�����");
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
            printf("��ϲ�����ɹ�");
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
        printf("��ӭ��������ϵͳ");
        for(num_star=0;num_star<16;num_star++)
        {
            printf("*");
            Sleep(5);
        }
            printf("\n\n-1-��������Ҫ��ʲô����1�۸�        2�������ڡ�\n   ");
            scanf("%d",&switch_num);
            switch(switch_num)
            {
            case 1:
                printf("\n-2-��ѡ���������͡�1.�۸�Ӹߵ�������2.�ӵ͵��ߡ�\n   ");
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
                    printf("����������������룺\n");
                    goto loop5;
                }
                break;


            case 2:
                {
                printf("\n-2-��ѡ���������͡�1.�������ڴ��絽��2.�����硿\n   ");
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
                    printf("\n-2-����������������룺\n   ");
                    goto loop6;
                }
                break;
            }
            default: return;
     }
     printf("\n-3-����ɹ�������ʾ����������˵���ִ����ʾ���ܡ�\n\n");
     for(num_star=0;num_star<48;num_star++){
                    printf("*");
                    Sleep(5);
     }
     printf("\n\n");
     printf("��1��س�����");
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
       printf("\n                 ��ӭ����ͻ���ѯϵͳ��                     \n");
       printf("*********************ϵͳ���ܲ˵�************************\n");
       printf("|                ___1:ͼ����Ϣ����___                   |\n");
       printf("|                ___2:ͼ����Ϣ��ʾ___                   |\n");
       printf("|                ___3:ͼ����Ϣ��ѯ___                   |\n");
       printf("|                ___4:ͼ����Ϣ����___                   |\n");
       printf("|                ___0:�˳�����ϵͳ___                   |\n");
       printf("---------------------------------------------------------\n");
	   printf("*********************************************************\n\n");
	   printf("���ȵ����ļ��ٽ�������������\n�����������ʹ���书�ܣ�\n");

    }
    void menu_manager()
{
    printf("\n                ��ͼ����Ϣ����Աϵͳ                   \n\n");
	printf("*********************ϵͳ���ܲ˵�************************\n");
	printf("---------------------------------------------------------\n");
	printf("|                ___1:ͼ����Ϣ����___                   |\n");
	printf("|                ___2:ͼ����Ϣ��ʾ___                   |\n");
	printf("|                ___3:ͼ����Ϣ���___                   |\n");
	printf("|                ___4:ͼ����Ϣɾ��___                   |\n");
	printf("|                ___5:ͼ����Ϣ�޸�___                   |\n");
	printf("|                ___6:ͼ����Ϣ��ѯ___                   |\n");
	printf("|                ___7:ͼ����Ϣ����___                   |\n");
	printf("|                ___8:ͼ����Ϣ����___                   |\n");
	printf("|                ___9:�޸ĵ�������___                   |\n");
    printf("|                ___0:�˳�����ϵͳ___                   |\n");
	printf("---------------------------------------------------------\n");
	printf("*********************************************************\n\n");
	printf("���ȵ����ļ��ٽ�������������\n�����������ʹ���书�ܣ�\n");
}

void password()
{
    int count=0;
    char a[20];
    FILE *fp;
    fp=fopen("password.txt","r+");
    if(fp==NULL)
        {
              printf("�Բ����Ҳ�������");
              exit(0);
        }
    fscanf(fp,"%s",password1);
    printf("*************��ӭ����ͼ����Ϣ����ϵͳ��¼����*************\n\n\n");
    printf("����������(��ʼ������1)��");
    scanf("%s",a);
    while(count<2)
    {
        if(strcmp(password1,a))
            {
                printf("\n************�������,������%d�λ��ᣬ�������������************\n\n",2-count);
                printf("���ٴ���������");
                scanf("%s",a);
                count++;
            }
        else goto loop;
    }
        if(!strcmp(password1,a))
            goto loop;
        printf("\n*****************��������������,���Ժ�����******************\n");
        exit(0);
        loop:
            system("cls");
            printf("*********************��ӭ����ϵͳ************************\n");
            system("cls");
    printf("���Ե�.");
    Sleep(200);
    system("cls");
    printf("���Ե�..");
    Sleep(200);
    system("cls");
    printf("���Ե�...");
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
    printf("��ӭ���������޸�ϵͳ");
    for(num_star=0;num_star<14;num_star++)
    {
            printf("*");
            Sleep(5);
    }
    printf("\n\n-1-�����������룺\n   ");
    scanf("%s",new_password);
    printf("\n-2-��ȷ������:\n   ");
    scanf("%s",confirm_password);
    if(!strcmp(new_password,confirm_password))
    {
        printf("\n-3-�޸ĳɹ�");
        fprintf(fp,"%s",new_password);
        fclose(fp);
    }
    else
        printf("\n-3-�������벻��ͬ�޸�ʧ��");
    printf("\n\n");
    for(num_star=0;num_star<48;num_star++)
    {
            printf("*");
            Sleep(5);
    }
    printf("\n\n");
    printf("��1��س�����");
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


            case 0:printf("*********************��лʹ�ã�**************************");
			break;

            default:
			printf("��Ŀ������\n");
			break;
		}
	}
	return;
}

void system_customer()
{
	
    system("cls");
    printf("���Ե�.");
    Sleep(200);
    system("cls");
    printf("���Ե�..");
    Sleep(200);
    system("cls");
    printf("���Ե�...");
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

            case 0:printf("*********************��лʹ�ã�**************************");
			break;
            default:
			printf("��Ŀ������\n");
			break;
		}
	}
	return;
}

int main()
{
    printf("*********************��ѡ�����ͻ�ϵͳ�����Աϵͳ*********************\n");
    printf("    *********************1=�ͻ�ϵͳ��2=����Աϵͳ*********************\n");
    printf("                                  ��ѡ��                    \n");
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
        printf("������Ϣ�����������룺");
        goto loop7;
    }
}
