#include<windows.h>
#include<stdlib.h>
#include <stdio.h>
#include <dirent.h>
struct loc
{
    char pat[100];
}loc1,loc2;


struct exn
{
    char exname[100];
}exn1,exn2;
FILE *fptr;//HAVE TO ADD VARIABLE SEARCH WITH PATH
FILE *fptr2;

void search(char path[100],int k)
{


    fptr2=fopen("exe_list.bin","r");
    if(fptr2==NULL)
    {
        printf("ERROR:game exe database not found exitting ");
        system("pause");
        exit(1);
    }
    struct dirent *de;  // Pointer for directory entry


    DIR *dr = opendir(path);//path goes here


    if (dr == NULL)  // opendir returns NULL if couldn't open directory (not necessary for now)
    {
        printf("Could not open the specified directory\n" );
        return 0;
    }


    while(fread(&exn2,sizeof(struct exn),1,fptr2)==1)
    {
        dr=opendir(path);
        //printf("under feof\n");

        //printf("under fread");
        while ((de = readdir(dr)) != NULL)
        {
            //printf(" under de\n");


            if(!strcmp(de->d_name,exn2.exname))//if(strcmp(de->d_name,exn2.exname)==0)
             {
                // printf("under if\n");

              printf("\tPress <%d> to open %s \n",k,de->d_name);//need to figure out i
              break;


             }

             if(!strcmp(de->d_name,exn2.exname))
                continue;

        }

    }

    //printf("outside loop\n");
    closedir(dr);
    fclose(fptr2);
}

FILE *fptr3;
FILE *fptr4;
void execute(char ch)
{
    int i=ch-'0';
    fptr3=fopen("game_dir.bin","r");
    for(int n=0;n<i;n++)
    fread(&loc2,sizeof(struct loc),1,fptr3);
    run(loc2.pat);

}
void run(char path2[100])
{

    fptr4=fopen("exe_list.bin","r");
    if(fptr4==NULL)
    {
        printf("ERROR:game exe database not found exitting ");
        system("pause");
        exit(1);
    }
    struct dirent *de;  // Pointer for directory entry


    DIR *dr = opendir(path2);//path goes here


    if (dr == NULL)  // opendir returns NULL if couldn't open directory (not necessary for now)
    {
        printf("Could not open the specified directory\n" );
        return 0;
    }


    while(fread(&exn2,sizeof(struct exn),1,fptr2)==1)//basically (!feof) but without reading the last line twice
    {
        dr=opendir(path2);
        //printf("under feof\n");

        //printf("under fread");
        while ((de = readdir(dr)) != NULL)
        {
            //printf(" under de\n");


            if(!strcmp(de->d_name,exn2.exname))//if(strcmp(de->d_name,exn2.exname)==0)
             {
               // printf("under if\n");
              printf("Please be patient this might take a few seconds depending on your PC\n");
              printf("running %s",strcat(strcat(path2,"\\"),de->d_name));
              char pannada[100];
              strcpy(pannada,path2);//strcat(strcat(path2,"\\"),de->d_name));
              ShellExecute(NULL,"open",pannada,NULL,NULL,SW_SHOWNORMAL);
              system("pause");//need to figure out i
              break;


             }

             if(!strcmp(de->d_name,exn2.exname))
                continue;

        }
    }

}

void addir(char c[100])
{

  fptr=fopen("game_dir.bin","ab");
  strcpy(loc1.pat,c);
  fwrite(&loc1,sizeof(struct loc),1,fptr);
  printf("directory added successfully");
  fclose(fptr);
  system("pause");
  launcher();
}
void dispgames()
{
    int i=1;
    fptr=fopen("game_dir.bin","r");
    if(fptr==NULL)
    {
        printf("Invalid Directory does not exist are you sure you added one?\n");
        return;
    }
    while(fread(&loc2,sizeof(struct loc),1,fptr)==1)
 {
    search(loc2.pat,i);
    i++;
 }
 fclose(fptr);

}

void addexe(char ex[100])
{
fptr=fopen("exe_list.bin","ab");
strcpy(exn1.exname,ex);
fwrite(&exn1,sizeof(struct exn),1,fptr);
printf("Missing exe file added");
fclose(fptr);
system("pause");
launcher();
}

