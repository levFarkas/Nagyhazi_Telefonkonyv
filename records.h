

typedef struct record {
    char name[50];
    char profession[50];
    char place[50];
    char number[50];
    struct record *next;
} Record;
Record* input(FILE *fp,char *content, Record *start);
void split(char string[], char content[], char separation);
void delete_string (char content[], char separation);
void print_list(Record *start);
void add_data(char data1[], char data2[], char data3[], char data4[], Record *start);
int check(char c);
int search_inlist(Record *p, char word[]);
void free_list(Record *p);
Record* delete_from_list(Record *origin, Record *list);
Record* Dbox (Record *p, Record *start);
