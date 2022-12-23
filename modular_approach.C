
#include<stdio.h>
#include<string.h>

void menu(){
    printf("1)DELETE THE DUPLICATE ELEMENTS OF AN ARRAY \n");
    printf("2)FIND COMMISION ON TOTAL SALES \n");
    printf("3)SUM OF ALL ELEMENTS IN ARRAY USING POINTERS \n");
    printf("4)GCD USING RECURSIVE FUNCTION \n");
    printf("5)CHANGE ALL UPPER CASE LETTERS INTO LOWER CASE\n");
    printf("PRESS 0 TO EXIT\n");
    printf("Enter the task you want to perform: \n");
}

void print_array(int arr[30],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void delete_duplicate(int arr[30],int number){
    for(int i=0;i<number;i++){
    for(int j = i+1; j < number; j++){
      if(arr[i] == arr[j]){
         for(int k = j; k <number; k++){
            arr[k] = arr[k+1];
         }
         j--;
         number--;
       }
     }
     } 
     printf("%d",number);
     printf("Your array after deletion of duplicate elements\n");
     print_array(arr,number);
}

int commision(int sales){
    if(sales<100){
        return 0;
    } else if(sales>=100 && sales<=500){
        return sales*0.1;
    } else if(sales>500){
        return(100+(0.08*(sales-500)));
    } else{
        return 0;
    }
}

void addition(int arr[30],int n){
    int* ptr;
    int sum=0;
    ptr=arr;
    for(int i=0;i<n;i++) 
   {
      sum = sum + *ptr;
      ptr++;
   }
   printf("Sum of elements in your array is %d",sum);
   printf("\n");

}

void upperlower(char *s){
    int i=0;
    while(s[i]!='\0'){
        if(s[i]>='a' && s[i]<='z'){
            s[i]=s[i]-32;
        }
        ++i;
    }
}


int greatest(int n1,int n2){
    if (n2 != 0)
        return greatest(n2, n1 % n2);
    else
        return n1;
}



void main(){
    int play=0;
    do{
    int c;
    do{
    menu();
    scanf("%d",&c);
    if(!(c>=0 && c<=5)){
        printf("Enter valid choice(1-5)\n");
    }
    }while(!(c>=0 && c<=5));
    if(c==1){
        int arr[30];
        int n;
        printf("Enter no of elements in array: ");
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            printf("Enter element no %d: ",i+1);
            scanf("%d",&arr[i]);
        }
        printf("\n");
        printf("Your array :\n");
        print_array(arr,n);
        printf("\n");  
        delete_duplicate(arr,n);
        printf("\n");

    }else if(c==2){
        int sales;
        printf("Enter your sales: ");
        scanf("%d",&sales);
        int comm=commision(sales);
        printf("\n");
        printf("Your commision is: %d",comm);
        printf("\n");

    }else if(c==3){
        int arr[30];
        printf("Enter no of elements in your array: ");
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            printf("Enter element no %d ",i+1);
            scanf("%d",&arr[i]);
        }
        addition(arr,n);
    
    }else if(c==4){
        int n1,n2;
        printf("Enter first number and second number: \n");
        scanf("%d%d",&n1,&n2);
        printf("\n");
        int gcd=greatest(n1,n2);
        printf("GCD of n1 and n2 is %d",gcd);
        printf("\n");
    
    }else{
        char str[30];
        printf("Enter your string: ");
        gets(str);
        gets(str);
        upperlower(str);
        printf("\n");
        printf("%s",str);
        printf("\n");
    }
    do{
    printf("Do you want to continue again?\n");
    printf("Press 1 for yes\n");
    printf("Press 0 for no\n");    
    scanf("%d",&play);
    }while(!(play == 1 || play ==0));
}while(play==1);
}
