#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include "records.h"
int main()
{
    SetConsoleOutputCP(1250);
    setlocale(LC_ALL, "hu_HU.ISO8859-2");
    Record records[100];
    char *content;
    int n=0;

    content = (char*)malloc(sizeof(char));
    if (content==NULL)
    {
        printf("Memory problem");
        return -1;
    }
    FILE *fp;
    if(!(fp=fopen("database.txt","r"))){

                fprintf(stderr,"hiba a file megnyitasakor !\n");
                return(-1);
    }
    input(fp, content, records,&n);
    printf("Üdvözlöm a Telefonkönyv programban!\n\nA programból bármelyik parancs közben visszaléphet a főmenübe/kilephet a programból a 'q' billentyû lenyomásával.\nVégrehajtható feladatok: új személy felvétele (N) \nkeresés (S)\nTeljes telefonkönyv kiírása (O) ");
    char be[10];
    while(!check(be[0]))
    {
        printf("Kérem a parancsot!");
        scanf("%s",be);
        switch (*be)
        {
            case 'N':
            {
                char name[40];
                char prof[40];
                char place[40];
                char number[40];
                printf("Kérem a nevet!");
                scanf("%s",name);
                if (check(name[0]))break;
                printf("Kérem a foglalkozást!");
                scanf("%s",prof);
                if (check(prof[0]))break;
                printf("Kérem a helyet");
                scanf("%s",place);
                if (check(place[0]))break;
                printf("Kérem a számot");
                scanf("%s",number);
                if (check(number[0]))break;
                n++;
                strcpy(records[n].name,name);
                strcpy(records[n].profession,prof);
                strcpy(records[n].place,place);
                strcpy(records[n].number,number);
                /*puts(records[n].name);
                puts(records[n].profession);
                puts(records[n].place);
                puts(records[n].number);*/
                printf("A beolvasas sikeresen megtortent!\n");

                break;

            }//case new

            case 'S':
            {
                printf("Adja meg a keresett szavat!");
                char in[50];
                scanf("%s",in);
                int i;
                char *p;
                p=(Record*)malloc(sizeof(Record));
                //Dinamikus tömmbe tárolom
                for (i=0;i<n;i++)
                {

                }
            break;
            }            // case search

        }   //switch
    }       // nagy while
}
