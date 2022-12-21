#include<stdio.h>
#include<string.h>
void print_pattern(){
    int end=7;
    for(int i=0;i<end;i++){
        for(int j=end-1-i;j>=0;j--){
            printf("%d ",j);
        }
        printf("\n");
    }
    printf("\n");
}
void swap(int* a,int* b){
    int c;
    c=*a;
    *a=*b;
    *b=c;
}
void menu(){
    printf("Enter your choice(1-4)\n");
    printf("1)Printing pattern\n");
    printf("2)Counting votes\n");
    printf("3)Counting occurence of a character\n");
    printf("4)HCF and LCM of two numbers\n");
    printf("PRESS 0 TO QUIT \n");
}
void total_votes(){
    int A=0;
    int B=0;
    char vote;
    char invalid_votes[10];
    int y=0;
    for(int i=0;i<10;i++){
        printf("Person %d please enter your vote: ",i+1);
        scanf(" %c",&vote);
       //toupper(vote);
        if(vote=='A'){
            A++;
        } else if(vote=='B'){
            B++;
        } else{
            invalid_votes[y]=vote;
            y++;
        }
    }
    printf("\n");
    printf("Votes for party A: \n");
    for(int i=1;i<=A;i++){
        printf("A ");
    }
    printf("\n");
    printf("Total votes for party A: %d",A);
    printf("\n");
    printf("\n");
    printf("Votes for party B: \n");
    for(int i=1;i<=B;i++){
        printf("B ");
    }
    printf("\n");
    printf("Total votes for party B: %d",B);
    printf("\n");
    printf("\n");
    printf("Invalid votes are: \n");
    for(int i=0;i<y;i++){
        printf("%c ",invalid_votes[i]);
    }
    printf("\n");
    printf("\n");
}
void count_char(){
    char str[30];
    char ch;
    int cnt=0;
    printf("Enter your string: ");
    scanf(" %s",&str);
    printf("Enter the character whose occurence you want to count: ");
    scanf(" %c",&ch);
    int a=strlen(str);
    for(int i=0;i<a;i++){
        if(str[i]==ch){
            cnt++;
        }
    }
    printf("Your character %c occurs %d times in your string %s.",ch,cnt,str);
    printf("\n");
    printf("\n");
}
void lcm_hcf(){
    int a,b,hcf,lcm;
    printf("Enter first number: ");
    scanf("%d",&a);
    printf("Enter second number: ");
    scanf("%d",&b);
    if(a>b){
        swap(&a,&b);
    }
    for(int i=1;i<=a;i++){
        if(a%i==0 && b%i==0){
            hcf=i;
        }
    }
    lcm=(a*b)/hcf;
    printf("\n");
    printf("HCF of %d and %d is %d\n",a,b,hcf);
    printf("LCM of %d & %d is %d\n",a,b,lcm);
    printf("\n");
}

int main(){
    int n;
    do{
    menu();
    scanf("%d",&n);
    printf("\n");
    if(n==1){
        print_pattern();
    } else if(n==2){
        total_votes();
    } else if(n==3){
        count_char();
    } else if(n==4){
        lcm_hcf();
    } else if(n==0){
        n=0;
    } else{
        printf("Enter valid choice");
    }
    }while(n!=0);
    return 0;
}





