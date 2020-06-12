#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
void start();
void ender();

int main()
{
    start();
    return 0;
}
void start()
{

    system("cls");
    header();
    printf("\tPlease LOGIN/SIGNUP:\n");
    printf("\t\Press <1> to LOGIN\n\tPress <2> to SIGNUP\n\tPress <3> to EXIT\nPlease enter your choise:");
    int loginvar;
                        //used to store the users choise for login signup or closing the program
    scanf("%d",&loginvar);
    ender();
    if(loginvar==1)
        login();
    else if(loginvar==2)
        signup();
    else if (loginvar==3)
        exit(1);
    else
    {
        printf("Unknown Choice exitting\n");
        system("pause");
    }

}
void header()
{
    printf("==================================================================================================================\n");
    printf("\t\t\t\t\t\t L3GI0N_LAUNCHER\n");
    printf("==================================================================================================================\n");
}

