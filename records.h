typedef struct record {
    char name[50];
    char profession[50];
    char place[50];
    char number[50];
} Record;
void input(FILE *fp,char *content, Record records[], int *n);
void split(char string[], char content[], char separation);
void delete_string (char content[], char separation);
int check(char c);
int search(Record record, char word[]);
