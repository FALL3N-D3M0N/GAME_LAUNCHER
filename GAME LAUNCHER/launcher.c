#include<windows.h>

char path[100];
char exename[100];
void launcher()
{

    system("cls");
    header();
    printf("\t\t\t\tMAIN MENU\n ");
    printf("GAME TOOLS:\n");
    printf("\tpress <a> to open SPOTIFY\n\tPress <b> to go back to login screen\n\tPress <c> to Close app\n\tPress <d> to Add a game directory\n\tPress <e> to Add missing game exe");
    char choise='1';
    printf("\nYOUR GAMES:\n");
    dispgames();                   //variable to get user choise
    printf("Enter your Choise:");
    ender();
    choise = getchar();
    if(choise=='a')
     system("spotify");
    else if(choise=='b')
     start();
    else if(choise=='c')
    {
      exit(1);
    }
    else if(choise=='d')
     {
         printf("Enter path:\n");
         scanf("%",path);
         addir(path);

     }
     else if(choise=='e')
     {

         printf("enter name of exe file");
         scanf("%s",exename);
         addexe(exename);
     }
     else if(choise>47&&choise<58)
     {
         execute(choise);
     }
    launcher();

}
