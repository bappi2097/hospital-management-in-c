#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
struct p
{
char SERIAL[20];
char name[25];
char age[3],gender[7],date[15];
char d_doc[150];
}s;
char ser[20];
char doc_ch,doc[150],no_name[25];
void introduction()
{
    printf("\n\t\t\t HOSPITAL MANAGEMENT SYSTEM.\n\n\n\n\n");
    system("pause");
    system("cls");
}
void main_menu()
{
    char n;
    printf("\n\n\n\tMAIN MENU\n\t\t  \t\n");

    printf("\n\t  1.Patient module\n\n\t  2.Doctor module\n\n\t  3.room\n\n\t  4.EXIT\n");

    printf("\n\n\n\n\tEnter Your Choice: ");
    n=getche();
    switch(n)
    {
    case '1':
        patient_module();
        break;
    case '2':
     //   loader();
        system("cls");
        printf("\n\n\t\t\t\tDoctors page\n\t\t\t__________________________\t\n\n");
        break;
    case '3':
      //  loader();
        system("cls");
        printf("\n\n\t\t\t\t\tROOMS\n\t________________________________________________________________\t\n\n");
        break;
    case '4':
     //   loader();
        system("cls");
        recur_exit();
        break;
    default:
        main_menu();
        break;
    }
}
recur_exit()
{
    char ce;
    printf("\n\n\n\n\n\t\t\t\tConfirm Exit\n\n\n");
    printf("\n\n\t\t\tY.Yes\t\t\tN.No\n\n\n\n\n\n\n\n\n");
    fflush(stdin);
    ce='\0';
    printf("\nEnter Your Choice:");
    ce=getche();
    system("cls");
    system("cls");
    switch(ce)
    {
    case 'y':
    case 'Y':
        exit(0);
        return 0;
        break;
    case 'n':
    case 'N':
        main_menu();
        break;
    default:
        recur_exit();
        break;
    }
}
loader_animation()
{
    loader();
    system("cls");
    printf("\n\tSuccessfully Loaded\n\n");
    getch();
}
void loader()
{
    int i;
    system("cls");
    printf("\n\n\n\n\t\t\tLoading...\n");
    printf("\t");
    for(i=0;i<50;i++)
    {
        Sleep(20);
        printf("%c",219);
    }
}
int main()
{
    system("color 5F");
    introduction();
    printf("\n\t\t\tWelcome To HOSPITAL MANAGEMENT SYSTEM .");
    main_menu();
    getch();
}
patient_module()
{
    char ce;
    ce='\0';
    //   loader();
    system("cls");
    printf("\n\n\t\t\t\tpatients page\n\t\t\t__________________________\t\n\n\n\n\t\t1.Select Doctor\n\n\t\t2.BACK\n\n\n\n\t\tPress any key for choice........ ");
    printf("\nEnter Your Choice:");
    ce=getche();
    switch(ce)
    {
    case '1':
        select_doc();
        break;
    case '2':
        main_menu();
        break;
    default:
        printf("\n\n\t\t\t===========WRONG INPUT==============");
        patient_module();
        break;
    }
}

select_doc()
{
    system("cls");
    printf("\t\t\t\tSELECT DOCTOR\n");
    printf("\n\n\n\n\t\t\t\tNAME\t\tSpecialist Type\n");
    printf("\n\t\t\t1. Dr. Bappi Saha\tCardiologists");
    printf("\n\t\t\t2. Dr. Badhhon Sarkar\tGastroenterologists");
    printf("\n\t\t\t3. Dr. Ashiqur Rahman\tDermatologists");
    printf("\n\t\t\t4. Dr. Mehedi Hasan\tEndocrinologists ");
    printf("\n\t\t\t5. Dr. Hadaitu Islam\tMedicine Specialists");
    printf("\n\n\n\t\tEnter Your Choice:");
    doc_ch='\0';
    doc_ch=getche();
    int i=0;
    for(i=0;i<150;i++)
    {
        doc[i]='\0';
    }
    switch(doc_ch)
    {
    case '1':
        strcpy(doc," Dr.Bappi Saha Cardiologist ");
        recursive();
        break;
    case '2':
        strcpy(doc," Dr.Badhhon Sarkar  Gastroenterologists ");
        recursive();
        break;
    case '3':
        strcpy(doc," Dr.Ashiqur Rahman  Dermatologists ");
        recursive();
        break;
    case '4':
        strcpy(doc," Dr.Mehedi Hasan  Endocrinologists ");
        recursive();
        break;
    case '5':
        strcpy(doc,"Dr.Hadaitu Islam  Medicine Specialists");
        recursive();
        break;
    default:
        select_doc();
        break;
    }
}
int recursive()
{
    //  loader();
    system("cls");
    printf("\n\n\t\t\t\tpatients page\n\t\t\t__________________________\t\n\n\n\n\t\t1.Patient's Registration\n\n\t\t2.Registered Patients\n\n\t\t3.search patient\n\n\t\t4.BACK\n\n\n\n\t\tPress any key for choice........ ");
    char choose;
    printf("\n\n\t\tEnter your choice: ");
    choose=getche();
    switch(choose)
    {
    case '1':
        insert();
        break;
    case '2':
        view();
        break;
    case '3':
        search();
        break;
    case '4':
        system("cls");
        main_menu();
        break;
    default:
        printf("\nWrong Input");
        recursive();
        break;
    }
}
int insert()
{
    FILE*fp;
    struct p s;
    fp=fopen("pol.txt","r");
    printf("\nEnter serial: ");
    scanf("%s",&ser);
    while(fread(&s,sizeof(s),1,fp))
    {
        if(strcmp(s.d_doc,doc)==0)
        {
            if(strcmp(s.SERIAL,ser)==0)
            {
                printf("\n\nSorry This Serial Exists\n");
                system("pause");
                recursive();
                break;
            }
        }
    }
    fclose(fp);
    fp=fopen("pol.txt","a");
    strcpy(s.SERIAL,ser);
    printf("\nEnter Name: ");
    scanf("%s",&s.name);
    strcpy(no_name,s.name);
    printf("\nEnter Age: ");
    scanf("%s",&s.age);
    int i=0;
    for(i=0;i<150;i++)
    {
        s.d_doc[i]='\0';
    }
    strcpy(s.d_doc,doc);
    strcpy(doc,s.d_doc);
    printf("\nEnter Date(DD/MM/YYYY):");
    scanf("%s",&s.date);
    fwrite(&s,sizeof(s),1,fp);
    fclose(fp);
   // recursive();
    notify();
}
notify()
{
    FILE*fp;
    fp=fopen("pol.txt","r");
    struct p s;
    while(fread(&s,sizeof(s),1,fp))
    {
        if(strcmp(s.d_doc,doc)==0)
        {
            if(strcmp(s.SERIAL,ser)==0)
            {
                printf("\n\tDear %s,\n\tYour Doctor Is %s , Meeting Date %s .\n\tPlease Attend In At 7.00am . Serial No. %s",s.name,s.d_doc,s.date,s.SERIAL);
            }
        }
    }
    getch();
    fclose(fp);
    recursive();
}
int view()
{
    FILE*fp;
    fp=fopen("pol.txt","r");
    struct p s;
    printf("\nSERIAL\t  Name\t  Age\t  Date\t\n");
    while(fread(&s,sizeof(s),1,fp))
    {
        if(strcmp(doc,s.d_doc)==0)
        {
            printf("%s\t  %s   %s \t %s\n",s.SERIAL,s.name,s.age,s.date);
        }
    }
    getch();
    fclose(fp);
    recursive();
}
int search()
{
    char serial[20];
    FILE*fp;
    fp=fopen("pol.txt","r");
    struct p s;
    printf("\nsearch serial: ");
    scanf("%s",&serial);
    while(fread(&s,sizeof(s),1,fp))
    {
        if(strcmp(s.d_doc,doc)==0)
        {
            if(strcmp(serial,s.SERIAL)==0)
            {
                printf("SERIAL\tName\tAge\tDate\n");
                printf("%s\t %s\t %s\t %s\t %s\n",s.SERIAL,s.name,s.age,s.d_doc,s.date);
                getch();
            }
        }
    }
    fclose(fp);
    recursive();
}
