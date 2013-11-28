#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "records.h"
#include <locale.h>



void input(FILE *fp,char *content, Record records[], int *n){

    //FILE *fp;
    //fopen("database.txt","r");
    int i=0;
    while (!feof(fp))
        {

            fgets(content,100,fp);
            content [strlen(content)+1]=0;
            split(&(records[i].name), content, ':');
            split(&(records[i].profession), content, ':');
            split(&(records[i].place),content, ':');
            split(&(records[i].number),content, ':');
            i++;
        }
        *n=i-1;
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
