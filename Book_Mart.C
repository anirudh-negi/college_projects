#include<stdio.h>
struct books
{
    int bno;
    char bname[50];
    int bprice;
    char bwr[50];
    int copies;
};

void menu(){
printf("\t Welcome to THE DOON BOOK MART\n");
printf("\n");
printf("\t\tBOOKMART MENU\n");
printf("\n");
printf("\t\t1.AVAIBALITY\n");
printf("\t\t2.PURCHASE\n");
printf("\t\t3.EXIT\n");
}

int ask(){
    int ans;
    do{
    printf("Do you want to continue?\n");
    printf("Press 1 for YES\n");
    printf("Press 0 for NO\n");
    scanf("%d",&ans);
    }while(!(ans==1 || ans==0));
    return ans;
}

void view(struct books b[]){
    printf("BOOK CODE\tBOOK NAME\t\tPRICE\tAUTHOR\t\tQUANTITY\n");
    printf("\n");
    for(int i=1;i<7;i++){
        if(i<5){
        printf("%d\t\t%s\t\t%d\t%s\t%d\n",b[i].bno,b[i].bname,b[i].bprice,b[i].bwr,b[i].copies);    
        }
        else{
        printf("%d\t\t%s\t%d\t%s\t%d\n",b[i].bno,b[i].bname,b[i].bprice,b[i].bwr,b[i].copies);     
        }
}
}
int main(){
    struct books b[8]={
        {},
        {111,"HARRY POTTER",1500,"J.K ROWLING",15},
        {320,"THE ALCHEMIST",1200,"PAULO COELHO",15},
        {83,"DA VINCI CODE",1600,"DAN BROWN",10},
        {410,"THE HOBBIT",1450,"J.R.R. TOLKIEN",5},
        {505,"A TALE OF TWO CITIES",1100,"CHARLES DICKENS",20},
        {333,"THE LORD OF THE RINGS",200,"J.R.R TOLKIEN",15}
    };
    int choice;
    int play=0;
    do{
    menu();
    do{
        scanf("%d",&choice);
        if(!(choice>=1 && choice<=3)){
            printf("Enter valid choice!\n");
        }
    }while(!(choice>=1 && choice<=3));
    if(choice==1){
        view(b);
        printf("\n");
        play=ask();

    } else if(choice==2){
        int find;
        int sno,nob;
        sno=0;
        printf("Enter the code of book you want to purchase: ");
        scanf("%d",&find);
        for(int i=1;i<7;i++){
            if (b[i].bno==find){
                sno=i;
                break;
            }
            else{
                sno=0;
            }
        }
        if(sno==0){
            printf("SORRY WE DONT HAVE ANY BOOK WITH CODE %d\n",find);
        }else{ 
        printf("Enter number of books you want to purchase: ");
        scanf("%d",&nob);
        if(nob<=b[sno].copies){
            printf("YOUR TOTAL BILL IS INR %d\n",b[sno].bprice*nob);
            printf("Thank you for buying %d %s book(s) from THE DOON BOOK MART, have a nice day!\n",nob,b[sno].bname);
            b[sno].copies-=nob;
        }else{
            printf("SORRY WE DONT HAVE %d NO OF %s BOOKS!\n",nob,b[sno].bname);
        }
        }
        printf("\n");
        play=ask();

    } else{
        play=0;
    }
    }while(play==1);
    return 0;
}
