#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "records.h"
int main()
{
    //SetConsoleOutputCP(1250);
    Record *start=NULL;
    //Precords->next=NULL;
    char *content;

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

    start=input(fp, content, start);
    //print_list(start);
    printf("Udvozlom a Telefonkonyv programban!\n\nA programbol bármelyik parancs közben visszalephet a fomenube/kilephet a programból a 'q' billentyu lenyomasaval.\nVegrehajthato feladatok: \n\nuj személy felvetele (N) \nkereses (S)\nTeljes telefonkonyv kiírása (P) ");
    //free(content);
    char be[2];


    while(!check(be[0]))
    {
        printf("Kérem a parancsot!");
        scanf("%s",be);
        fflush(stdin);
        be[0]=toupper(be[0]);
        //puts(be);
        switch (*be)
        {
            case 'N':
            {
                char name[40];
                char prof[40];
                char place[40];
                char number[40];
                printf("Kérem a nevet!");
                //scanf("%s",name);
                if (check(name[0]))break;
                gets(name);
                printf("Kérem a foglalkozást!");
                //scanf("%s",prof);
                if (check(prof[0]))break;
                gets(prof);
                printf("Kérem a helyet");
                //scanf("%s",place);
                if (check(place[0]))break;
                gets(place);
                printf("Kérem a számot");
                //scanf("%s",number);
                if (check(number[0]))break;
                gets(number);
                add_data(name,prof,place,number,start);

           //     add_data(name,prof,place,number);
               /* strcpy(records[n].name,name);
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
                char answer='y';
                Record *start2=start;
                char in[50];

                while(answer=='y')
                {
                    printf("Mit keres?");
                    gets(in);
                    int i;
                    Record *iter;
                    Record *p=NULL;
                    for (iter=start2; iter!=NULL;iter=iter->next)
                    {
                        if (search_inlist(iter, in))
                        {
                            if (p==NULL)
                            {
                                Record *uj;
                                uj=(Record*)malloc(sizeof(Record));
                                strcpy(uj->name,iter->name);
                                strcpy(uj->profession,iter->profession);
                                strcpy(uj->place,iter->place);
                                strcpy(uj->number,iter->number);
                                p=uj;
                                uj->next=NULL;

                            }
                            else{
                                add_data(iter->name,iter->profession,iter->place,iter->number, p);
                            }
                        }

                    }

                    start2=p;
                    //free_list(p) ;
                    //printf("%s",start2->name);
                    printf("szeretne meg ezen belul is keresni?\ny/n");
                    scanf("%c",&answer);
                    fflush(stdin);
                }
                printf("szeretne-e törölni az adott listat az eredetibol?\ny/n");


                scanf("%c",&answer);
                fflush(stdin);
                if (answer=='y')
                {
                    start=delete_from_list(start, start2);
                    printf("törlés sikeres");
                }
                printf("szeretne-e exportani egy tablazatba?\ny/n");
                scanf("%c",&answer);
                fflush(stdin);
                if (answer=='y')
                {
                    export_to_csv(start2);
                    printf("export sikeres");
                }

                //free(p);
            break;
            }            // case search

        case 'P':
            {
            print_list(start);
            break;
            }
        }   //switch

    }       // nagy while
}
