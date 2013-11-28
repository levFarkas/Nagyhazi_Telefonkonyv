#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "records.h"
#include <locale.h>

void add_data(char data1[], char data2[], char data3[], char data4[], Record *start)
{
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
void print_list(Record *start)
{
    Record *iter;
    for (iter = start; iter!=NULL; iter = iter->next)
    {
        printf("%s:%s:%s:%s\n",iter->name,iter->profession,iter->place,iter->number);
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

return c=='q';

}
int search(Record record, char word[]){
   int length=strlen(word);
   int i,j,db=0;
   for (i=0,j=0;record.name[i]!=0;i++,j++)
   {
        if (db==length)return 1;
        if(word[j]==record.name[i])
           {
               db++;
           }
           else{
                j=0;db=0;
           }
   }

i,j,db=0;
   for (i=0,j=0;record.profession[i]!=0;i++,j++)
   {
        if (db==length)return 1;
        if(word[j]==record.profession[i])
           {
               db++;
           }
           else{
                j=0;db=0;
           }
   }
i,j,db=0;
   for (i=0,j=0;record.place[i]!=0;i++,j++)
   {
        if (db==length)return 1;
        if(word[j]==record.place[i])
           {
               db++;
           }
           else{
                j=0;db=0;
           }
   }
i,j,db=0;
   for (i=0,j=0;record.number[i]!=0;i++,j++)
   {
        if (db==length)return 1;
        if(word[j]==record.number[i])
           {
               db++;
           }
           else{
                j=0;db=0;
           }
   }
}
