#include <stdio.h>
#include <string.h>
struct movies
{
    char *movie;
    int code;
    int price;
    int time;
    int seats_left;
};
struct ticket
{
    char name[30];
    char *mname;
    int no_of_tickets;
    int timing;
    int t_no;
    int cost;
};
void menu()
{
    printf("------------------------------------------------\n");
    printf("                PVR CINEMAS DEHRADUN            \n");
    printf("------------------------------------------------\n");
    printf("PRESS 1 TO VIEW MOVIES \n");
    printf("PRESS 2 TO BOOK TICKETS\n");
    printf("PRESS 3 TO CANCEL TICKETS\n");
    printf("PRESS 4 TO VIEW ALL BOOKING RECORDS\n");
    printf("PRESS 0 TO EXIT\n");
    printf("------------------------------------------------\n");
    printf("\n");
}
void movies(struct movies movie[7])
{
    printf("MOVIE \t \t      CODE      PRICE    TIME    SEATS LEFT\n");
    printf("\n");
    printf("%s   %d       %d     %d        %d\n", movie[1].movie, movie[1].code, movie[1].price, movie[1].time, movie[1].seats_left);
    printf("%s              %d       %d     %d        %d\n", movie[2].movie, movie[2].code, movie[2].price, movie[2].time, movie[2].seats_left);
    printf("%s            %d       %d     %d        %d\n", movie[3].movie, movie[3].code, movie[3].price, movie[3].time, movie[3].seats_left);
    printf("%s                %d       %d     %d        %d\n", movie[4].movie, movie[4].code, movie[4].price, movie[4].time, movie[4].seats_left);
    printf("%s        %d       %d     %d        %d\n", movie[5].movie, movie[5].code, movie[5].price, movie[5].time, movie[5].seats_left);
    printf("%s          %d       %d      %d        %d\n", movie[6].movie, movie[6].code, movie[6].price, movie[6].time, movie[6].seats_left);
    printf("\n");
}
void update(struct ticket *tc,struct movies *mv,int tb,int stno,int nott){
    tc[tb].mname=mv[stno].movie;
    tc[tb].no_of_tickets=nott;
    tc[tb].timing=mv[stno].time;
    tc[tb].t_no=tb;
    tc[tb].cost=mv[stno].price*nott;
    mv[stno].seats_left-=nott;
    printf("TICKET CONFIRMED. YOUR TOTAL BILL IS %d\n",tc[tb].cost);
}
void delticket(struct ticket *tc,int dn){
    strcpy(tc[dn].name,tc[dn+1].name);
    tc[dn].mname=tc[dn+1].mname;
    tc[dn].no_of_tickets=tc[dn+1].no_of_tickets;
    tc[dn].timing=tc[dn+1].timing;
    tc[dn].t_no=tc[dn+1].t_no;
    tc[dn].cost=tc[dn+1].cost;

}
void view_records(struct ticket *tc,int tb){
    printf("PVR BOOKING RECORDS\n");
        printf("---------------------------------------------------------\n");
        for(int i=1;i<tb;i++){
            printf("---------------------------------------------------------\n");
            printf("CUSTOMER NAME: %s\nMOVIE NAME: %s\nNO OF TICKETS: %d\nTICKET NUMBER: %d\nMOVIE TIME: %d\nPRICE: %d\n",tc[i].name,tc[i].mname,tc[i].no_of_tickets,tc[i].t_no,tc[i].timing,tc[i].cost);
            printf("---------------------------------------------------------\n");
            }
        printf("---------------------------------------------------------\n");
        printf("\n");
}
    



int main()
{   
    int cde;
    int nott;
    int stno;
    int tb = 1;
    struct ticket tc[100];
    struct movies mv[7]={
    {},
    {"HEROES AND VILLIANS", 100, 1100, 2100, 100},
    {"HER LOSS", 106, 1050, 2030, 100},
    {"MR MORALES", 111, 1100, 2130, 100},
    {"NAYAAB", 101, 1200, 2145, 100},
    {"ITS ALMOST DRY", 320, 1000, 2000, 100},
    {"NO THANK YOU", 216, 800, 1900, 100},
    };
    int choice=1;
    int play=0;
    do{
    do
    {
        menu();
        scanf("%d", &choice);
        if (!(0 <= choice && choice <= 4))
        {
            printf("ENTER VALID CHOICE(1-4)");
        }
    } while (!(0 <= choice && choice <= 4));
    if (choice == 1)
    {
        movies(mv);
    }
    else if (choice == 2)
    {
        char name[20];
        printf("Enter your name: ");
        scanf(" %s",&tc[tb].name);
        printf("Enter the code of movie you want to book: ");
        scanf("%d", &cde);
        printf("Enter number of tickets you want to book: ");
        scanf("%d",&nott);
        int flag=1;
        for (int i = 1; i < 7; i++){
        if (mv[i].code == cde){
            stno=i;
            flag=0;
            break;
            }
        }
        if(flag==1){
            printf("INVALID CODE PLEASE TRY AGAIN LATER \n");
        }else{
            if(nott<mv[stno].seats_left){
                update(tc,mv,tb,stno,nott);  
                tb++;
            } else{
                printf("Sorry the show is full!\n");
            }
        }

    }
    else if(choice==3){
        int stno;
        int fm;
        printf("Enter your ticket number: ");
        scanf("%d",&fm);
        int flag=1;
        for (int i = 1; i < 7; i++){
        if (tc[i].t_no== fm){
            stno=i;
            flag=0;
            break;
            }
        }
        if(flag==1){
            printf("INVALID TICKET NUMBER PLEASE TRY AGAIN LATER \n");
        }else{
            mv[stno].seats_left+=tc[stno].no_of_tickets;
            for(int x=stno-1;x<tb;x++){
            delticket(tc,x);
            }
            tb--;
            printf("TICKET CANCELLED! HOPE TO SEE YOU AGAIN!!\n");
        }
    }
    else if(choice == 4){
        printf("\n");
        view_records(tc,tb);
        
    }
    if(choice!=0){
        do{
        printf("Do you want to continue?\n");
        printf("Press 1 to continue.\n");
        printf("Press 0 to exit\n");
        scanf("%d",&choice);
        }while(!(choice==1 || choice ==0));
    }
    }while(choice==1);
    printf("\nTHANK YOU FOR USING PVR SERVICES HAVE A NICE DAY\n");
    return 0;
}
