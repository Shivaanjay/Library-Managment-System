#include <stdio.h>
struct book_st
{
    int book_cd;
    char book_nm[30];
    char author[30];
    int copies;
};
struct date_st
{
    int month;
    int day;
    int year;
};
struct tran_st
{
    int book_code;
    char tran_type;
    struct date_st tran_dt;
};
void sorttran(struct tran_st tran[], int size);
int main()
{
    int choice = 1, i;
    char addflag;
    struct book_st books[5];
    struct tran_st trans[10];
    int trans_count = 0;
    while(choice != 4)
    {
        printf("\nSelect from MENU\n");
        printf("\n1. Add Book Names\n");
        printf("\n2. Record Issue/Return\n");
        printf("\n3. Sort Transactions\n");
        printf("\n4. EXIT\n\n");
        printf("\nEnter Choice : ");
        scanf("%d", &choice);
        if(choice == 1)
        {
            addflag = 'y';
            for(i = 0; i < 5 && addflag == 'y'; i++)
            {
                books[i].book_cd = i + 1;
                printf("\n\nBook Code : %d", i + 1);
                printf("\n\nBook Name : ");
                scanf("%s", books[i].book_nm);
                printf("\nAuthor : ");
                scanf("%s", books[i].author);
                printf("\nNumber of copies : ");
                scanf("%d", &books[i].copies);
                printf("\n\nContinue? (y/n) : ");
                getchar(); // Consume newline character left in buffer
                scanf("%c", &addflag);
            }
        }
        else if(choice == 2)
        {
            addflag = 'y';
            for(i = trans_count; i < 10 && addflag == 'y'; i++)
            {
                printf("\n\nBook Code : ");
                scanf("%d", &trans[i].book_code);
                printf("\nIssue or Return? (I/R): ");
                getchar();
                scanf("%c", &trans[i].tran_type);
                printf("\nDate (mm dd yyyy) : ");
                scanf("%d %d %d", &trans[i].tran_dt.month, &trans[i].tran_dt.day, &trans[i].tran_dt.year);
                printf("\n\nContinue? (y/n) : ");
                getchar();
                scanf("%c", &addflag);
                trans_count++;
            }
        }
        else if(choice == 3)
        {
            sorttran(trans, trans_count);
            printf("\n\n");
        }
    }
    return 0;
}
void sorttran(struct tran_st tran[], int size)
{
    int i, j, tempcode;
    struct tran_st temptran;
    for(i = 0; i < size - 1; i++)
    {
        for(j = 0; j < size - 1 - i; j++)
        {
            if(tran[j].book_code > tran[j + 1].book_code)
            {
                temptran = tran[j];
                tran[j] = tran[j + 1];
                tran[j + 1] = temptran;
            }
        }
    }
    for(i = 0; i < size; i++)
    {
        tempcode = tran[i].book_code;
        int count = 0;
        while(i < size && tran[i].book_code == tempcode)
        {
            count++;
            i++;
        }
        printf("\nBook code %d had %d transactions", tempcode, count);
        i--;
    }
}