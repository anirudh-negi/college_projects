#include<stdio.h>
struct tax{
    float et;
};
void swap(int arr[50],int a,int b){
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;

}

int getMinIndex(int arr[50],int start, int end){
    int min=start;
    for(int i=start;i<=end;i++){
        if(arr[min]>arr[i]){
            min=i;
        }
    }
    return min;
}
void sort(int arr[50],int s){
    for(int i=0;i<s;i++){
        int last=s-i-1;
        int minIndex=getMinIndex(arr,0,last);
        swap(arr,minIndex,last);
    }
}
void menu(){
    printf("\n");
    printf("\tDIT TELEPHONE SERVICES\n");
    printf("\n");
    printf("\t   MENU\n");
    printf("\t  1.STD\n");
    printf("\t  2.LOCAL\n");
    printf("\t  3.ISD\n");
    printf("\t  4.VIEW TAXES\n");
    printf("\t  5.EXIT\n");
}
int main(){
    struct tax tx[4]={
        {},
        {0.02},
        {0.04},
        {0.1},
    };
    int choice,start,noc,list[50];
    float bill,time,time1;
    long long int phno;
    char name[50];
    int in=0;
    printf("ENTER YOUR NAME: ");
    scanf(" %s",name);
    printf("\n");
    printf("ENTER YOUR 10 DIGIT PHONE NUMBER: +91");
    scanf("%lli",&phno);
    do{
    do{
        menu();
        scanf("%d",&choice);
    }while(!(1<=choice && choice<=5));
    if(choice==1){
        time=0;
        printf("Enter total number of your STD calls: ");
        scanf("%d",&noc);
        for(int i=1;i<=noc;i++){
            printf("\nENTER DURATION OF YOUR CALL NUMBER %d IN SECONDS: ",i);
            scanf("%f",&time1);
            list[in]=(int)time1;
            in++;
            time+=time1;
        }
        if(time>600){
            bill=time*5.5;
        } else if(time>200 && time<600){
            bill=time*3.5;
        } else{
            bill=time*1.5;
        }
        bill+=bill*tx[1].et;

    } else if(choice==2){
        time=0;
        printf("Enter total number of your LOCAL calls: ");
        scanf("%d",&noc);
        for(int i=1;i<=noc;i++){
            printf("\nENTER DURATION OF YOUR CALL NUMBER %d IN SECONDS: ",i);
            scanf("%f",&time1);
            list[in]=(int)time1;
            in++;
            time+=time1;
        }
        if(time>600){
            bill=time*5.5;
        } else if(time>200 && time<600){
            bill=time*3.5;
        } else{
            bill=time*1.5;
        }
        bill+=bill*tx[2].et;
    } else if(choice==3){
        time=0;
        printf("Enter total number of your ISD calls: ");
        scanf("%d",&noc);
        for(int i=1;i<=noc;i++){
            printf("\nENTER DURATION OF YOUR CALL NUMBER %d IN SECONDS: ",i);
            scanf("%f",&time1);
            list[in]=(int)time1;
            in++;
            time+=time1;
        }
        if(time>600){
            bill+=time*5.5;
        } else if(time>200 && time<600){
            bill+=time*3.5;
        } else{
            bill+=time*1.5;
        }
        bill+=bill*tx[3].et;

    }else if(choice==4){
        printf("\n");
        printf("TYPE\tTAX\n");
        printf("\n");
        printf("STD\t2%\n");
        printf("LOCAL\t4%\n");
        printf("ISD\t10%");
        printf("\n");  
    }else{
        sort(list,in);
        if(bill>50){
        printf("Dear user %s your bill for phone number +91%lli is %.2f, and your longest call is of %d seconds\n",name,phno,bill,list[0]);
        printf("Here are your call durations(from highest):\n");
        for(int i=0;i<in;i++){
            printf("%d\n",list[i]);
        }
        }else{
            printf("SORRY THE MINIMUM BILL HAS TO BE OF INR 50\n");
        }
        bill=0;
    }
    }while(choice!=5);
    return 0;
}

