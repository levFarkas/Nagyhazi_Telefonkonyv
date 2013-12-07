#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "records.h"
#include <locale.h>

void add_data(char data1[], char data2[], char data3[], char data4[], Record *start){

    Record *iter, *uj;
    uj = (Record*)malloc(sizeof(Record));
    strcpy(uj->name,data1);strcpy(uj->profession,data2);strcpy(uj->place,data3);strcpy(uj->number,data4);
    uj->next=NULL;
    for (iter=start;iter->next!=NULL;iter=iter->next);
    iter->next=uj;
}
Record* input(FILE *fp, char *content, Record *start){

    Record *uj;

    //fp=fopen("database.txt","r");

    while (!feof(fp))
        {
            if (start==NULL)
            {
                    fgets(content,100,fp);

                    uj = (Record*)malloc(sizeof(Record));

                    split(uj->name,content,':');
                   // puts(uj->name);
                    split(uj->profession,content,':');
                   // puts(uj->profession);
                    split(uj->place,content,':');
                    //puts(uj->place);
                    split(uj->number,content,':');
                    //puts(uj->number);
                    uj->next=NULL;
                    start=uj;

            }

            fgets(content,100,fp);
            content [strlen(content)+1]=0;
            /*if (start->next==0)
            {
                split(start->name,content,':');
                split(start->profession,content,':');
                split(start->place,content,':');
                split(start->number,content,':');

            }*/
            uj = (Record*)malloc(sizeof(Record));

            char name[100],prof[100],place[100],numb[100];

            split(name,content,':');
            //add_data(temp,"name",start);
            //puts(temp);
            split(prof,content,':');
            //add_data(temp,"profession",start);
            //puts(temp);
            split(place,content,':');
            //add_data(temp,"place",start);
            //puts(temp);
            split(numb,content,':');
            add_data(name,prof,place,numb,start);

            //iter->next=uj;
            //uj->next=NULL;

       }

    return start;
}
void split(char string[], char content[], char separation){
    char temp[100]="";
    int i;
    for  (i=0;content[i]!=separation;i++)
    {
        if (content[i]=='\0')
        {
            temp[i]='\0';
            //puts(temp);
            strcpy(string, temp);
            return;
        }

        temp[i]=content[i];
    }

    temp[i+1]=0;

   // puts(temp);
    strcpy(string,temp);

    //string[strlen(string)+1]=0;
    delete_string(content,separation);


}
void print_list(Record *start){
    Record *iter;
    int i=0;
    for (iter = start; iter!=NULL; iter = iter->next)
    {
        if (i==24)
        {
            printf("folytatashoz nyomjon egy billentyut");
            getchar();
        }
        printf("%s:%s:%s:%s\n",iter->name,iter->profession,iter->place,iter->number);
        i++;
    }
}
void delete_string (char content[], char separation){
    char temp[100]="";
    int i;
    for (i=0;content[i]!=separation;i++)
        if (content[i]=='\0'){
            content=0;
            return;
        }
    int j;
    for (j=i+1;content[j]!='\0';j++)
    {
        if(content[j]=='\n') continue;
        temp[j-i-1]=content[j];
    }
    temp[j-i]='\0';


    strcpy(content,temp);//puts(content);


}
int check(char c){

return c=='Q';

}
int search_inlist(Record *p, char word[]){
   int length=strlen(word);
   int i,j,db=0;
   for (i=0,j=0;p->name[i]!=0;i++)
   {

        if(word[j]==p->name[i]||word[j]==p->name-('a'-'A'))
           {
               db++;
               j++;
           }
           else{
                j=0;db=0;
           }
   if (db==length)return 1;
   }

i,j,db=0;
   for (i=0,j=0;p->profession[i]!=0;i++)
   {
        if(word[j]==p->profession[i])
           {
               db++;
               j++;
           }
           else{
                j=0;db=0;
           }
   if (db==length)return 1;
   }
i,j,db=0;
   for (i=0,j=0;p->place[i]!=0;i++)
   {
        if(word[j]==p->place[i])
           {
               db++;
               j++;
           }
           else{
                j=0;db=0;
           }
   if (db==length)return 1;
   }
i,j,db=0;
   for (i=0,j=0;p->number[i]!=0;i++)
   {

        if(word[j]==p->number[i])
           {
               db++;
               j++;
           }
           else{
                j=0;db=0;
           }
    if (db==length)return 1;
   }

   return 0;
}
void free_list(Record *p){
    Record *iter;
    iter=p;
    while (iter != NULL) {
       Record *temp = iter->next; /* második elem */
       free(iter);
       iter = temp;
    }
}
Record* Dbox(Record *p, Record *start){
    Record *iter, *iter2;

    for (iter2=NULL,iter=start;iter->next!=NULL; iter2=iter,iter=iter->next)
    {
       // printf("iter_number: %s \np_number: %s ",iter->number, p->number);
        if (strcmp(iter->number,p->number)==0)
            {
                    if (iter == NULL)      /* üres vagy nincs ilyen elem? */
                        return start;
                    if (iter2 == NULL) { /* első elemet kell törölni? */
                      Record *ujeleje = iter->next;
                      free(iter);
                      return ujeleje;
                   } else {              /* a lista közepéről/végéről törlünk */
                      iter2->next = iter->next;
                      free(iter);
                      return start;
                   }
            }

    }
    return start;
}
Record* delete_from_list(Record *origin, Record *list){
    Record *iter;
    for (iter=list;iter!=NULL;iter=iter->next)
    {
        origin=Dbox(iter,origin);
    }
    return origin;
}
void string_to_csv(char string[]){
    int length=strlen(string);
    string[length]='.';
    string[length+1]='c';
    string[length+2]='s';
    string[length+3]='v';
    string[length+4]=0;
}
void export_to_csv(Record *start){
    FILE *out;
    printf ("adjon meg egy fajlnevet");
    char *filename;
    filename=(char*)malloc(sizeof(char));
    scanf("%s",filename);
    string_to_csv(filename);
    out = fopen(filename,"w");
    Record *iter;
    for (iter=start;iter->next!=NULL;iter=iter->next)
    {
        fprintf(out,"%s %s %s %s",iter->name,iter->profession,iter->place,iter->number);
        fprintf(out,"\n");

    }
}
