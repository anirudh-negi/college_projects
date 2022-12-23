#include<stdio.h> 
 void ask(char* gender,char* nat,char* fit,int* age); 
 int main(){ 
     char gender; 
     char nat; 
     char fit; 
     char ans; 
     char name[20]; 
     int age; 
     do{ 
         ask(&gender,&nat,&fit,&age); 
         if(age>=25 && age<=45 && toupper(gender)=='M' && toupper(nat)=='Y' && toupper(fit)=='Y'){ 
             printf("Your premium is 4K/month\n"); 
             printf("Your policy amount is 5 Lakh.\n"); 
         } 
         else if(age>=25 && age<=45 && toupper(gender)=='F' && toupper(nat)=='Y' && toupper(fit)=='Y'){ 
             printf("Your premium is 3K/month\n"); 
             printf("Your policy amount is 3 Lakh.\n"); 
         } 
         else if(age>=25 && age<=45 && toupper(nat)=='Y' && toupper(fit)=='N'){ 
             printf("Your premium is 2K/month\n"); 
             printf("Your policy amount is 2 Lakh.\n"); 
         } 
         else{ 
             printf("Sorry you are not insured.\n"); 
         } 
         do{ 
         printf("Do you want to continue for another person(Y/N): "); 
         scanf("%c%c",&ans,&ans); 
           scanf("%c",&gender);
         }while(!(toupper(ans)=='Y' || toupper(ans)=='N')); 
     }while(toupper(ans=='Y')); 
     printf("Thank you for using our service!\n"); 
     return 0; 
  
 } 
 void ask(char* gender,char* nat,char* fit,int* age){ 
     char name[20]; 
     printf("Enter name: ");
     gets(name);
     do{ 
     printf("Enter age: "); 
     scanf("%d",age); 
     if(!(0<=*age && *age<=100)){ 
         printf("Enter valid age! \n"); 
     } 
     }while(!(0<=*age && *age<=100)); 
     do{ 
     printf("Enter Gender(M/F): "); 
     scanf("%c%c",gender,gender); 
     if(!(*gender=='M' || *gender=='F')){ 
         printf("Enter valid gneder! \n"); 
     } 
     }while(!(*gender=='M' || *gender=='F')); 
     do{ 
     printf("Indian citizen(Y/N): "); 
     scanf("%c%c",nat,nat); 
     if(!(*nat=='Y' || *gender=='N')){ 
         printf("Enter valid answer! \n"); 
     } 
     }while(!(*nat=='Y' || *nat=='N')); 
     do{ 
     printf("Medical Fit(Y/N): "); 
     scanf("%c%c",fit,fit); 
     if(!(*fit=='Y' || *fit=='N')){ 
         printf("Enter valid answer! \n"); 
     } 
     }while(!(*fit=='Y' || *fit=='N')); 
     printf("\n"); 
}
