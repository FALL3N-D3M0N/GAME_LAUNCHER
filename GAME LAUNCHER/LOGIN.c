#include<stdio.h>
#include<string.h>
#include<time.h>
time_t t;
struct users
{
    char username[100];
    char password[100];
}u1,u2;
FILE *fptr;    //pointer for handling files
void login();
void signup();


void login() // has to show stars instead know more
{
    system("cls");
    header();
    int verify;
    verify=0;
    printf("\t\tLOGIN\n");
    printf("Enter Username:");
    scanf("%s",u1.username);
    printf("Enter Password:");
    scanf("%s",u1.password);
    fptr=fopen("login_info.bin","r");
    while(!feof(fptr))
    {
       fread(&u2,sizeof(u1),1,fptr);
       if(strcmp(u1.username,u2.username)==0)
        {
            if(strcmp(u1.password,u2.password)==0)
              {
                  verify=1;
                   break;
              }
             else
             {
                 verify=0;
                 continue;
             }
        }
        else
        {
            verify=0;
            continue;
        }

    }
    if (verify==1)
        {
            printf("logged in successfully");
            system("pause");
            launcher();
        }
    else if(verify==0)
    {
        char ch1;//character for return to main menu choise
        printf("login failed check ur username and password\n");
        system("pause");
        login();

    }

}
void signup()
{
    fptr=fopen("login_info.bin","ab");//login info is stored in login_info.bin, ab is for appending
    system("cls");
    header();
    printf("\t\tSIGNUP\n");
    printf("Enter Username:");
    scanf("%s",u1.username);
    printf("Enter Password");
    scanf("%s",u1.password);
    fwrite(&u1,sizeof(struct users),1,fptr);
    fclose(fptr);
    printf("Username and Password added successfully  :) \n");
    printf("returning to main screen\n");
    system("pause");

    start();
}


void ender()
{
    time(&t);
    printf("\n-------------------------------------------------------------------------------------------------\n");
    printf("\n logged in as: %s\t\t%s\n",u1.username,ctime(&t));
    printf("\n-------------------------------------------------------------------------------------------------\n");
}
