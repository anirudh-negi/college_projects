#include<stdio.h>
void print_matrix(int arr[20][20],int r,int c){
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                printf("%d ",arr[i][j]);
            }
            printf("\n");
        }
    }
void input_matrix(int arr[20][20],int r,int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("Enter element of row no. %d and column no. %d: ",i+1,j+1);
            scanf("%d",&arr[i][j]);
        }
    }
}
void menu(){
    printf("Enter the operation you want to perform(1-6):\n");
    printf("1)Display Matrix\n");
    printf("2)Add matrix\n");
    printf("3)Matrix multiply\n");
    printf("4)Row sum and column sum of matrix\n");
    printf("5)Symmetric matrix\n");
    printf("6)Transpose matrix\n");
    printf("press 0 to exit.\n");
}
void display_matrix(){
    int r,c;
    int arr[20][20];
    printf("Enter the no of rows and columns in your matrix respectively:\n");
    scanf("%d %d",&r,&c);
    input_matrix(arr,r,c);
    printf("\n");
    printf("Your entered matrix is: \n");
    print_matrix(arr,r,c);
    printf("\n");
    printf("\n");
    printf("\n");
}
void add_matrix(){
    int arr1[20][20],arr2[20][20];
    int r,c;
    printf("Enter the no of rows and columns in your matrix respectively:\n");
    scanf("%d %d",&r,&c);
    printf("\n");
    printf("MATRIX 1\n");
    input_matrix(arr1,r,c);
    printf("\n");
    printf("MATRIX 2\n");
    input_matrix(arr2,r,c);
    printf("\n");
    printf("Matrix 1 is:\n");
    print_matrix(arr1,r,c);
    printf("\n");
    printf("Matrix 2 is:\n");
    print_matrix(arr2,r,c);
    printf("\n");
    printf("THE SUM OF THESE MATRIX IS:\n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%d ",arr1[i][j]+arr2[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
    printf("\n");

}
void matrix_multiply(){
    int arr1[20][20],arr2[20][20],res[20][20];
    int r,c,a,b;
    printf("Enter the no of rows and columns in your first matrix respectively:\n");
    scanf("%d %d",&r,&c);
    printf("MATRIX 1\n");
    input_matrix(arr1,r,c);
    printf("MATRIX 2\n");
    printf("Enter the no of rows and columns in your second matrix respectively:\n");
    scanf("%d %d",&a,&b);
    input_matrix(arr2,a,b);
    printf("Matrix 1:\n");
    print_matrix(arr1,r,c);
    printf("\n");
    printf("Matrix 2: \n");
    print_matrix(arr2,a,b);
    printf("\n");
    if(c!=a){
        printf("MULTIPLICATION NOT POSSIBLE.\n");
    } else{
    for (int i = 0; i < r; i++) {
            for (int j = 0; j < b; j++) {
                res[i][j] = 0;
                for (int k = 0; k < a; k++) {
                    res[i][j]+=arr1[i][k]*arr2[k][j];
                }
            }
        }
    printf("The product matrix of the two matrices is:-\n");
    print_matrix(res,r,b);
    }
    printf("\n");
    printf("\n");
    printf("\n");

}
void row_sum_column_sum(){
    int arr1[20][20];
    int r,c;
    printf("Enter the no of rows and columns in your matrix respectively:\n");
    scanf("%d %d",&r,&c);
    input_matrix(arr1,r,c);
    int n,n2;
    do{
        printf("Enter the number of row you want to find sum of: ");
        scanf("%d",&n);
        if(n>r){
            printf("Enter valid row number\n");
        }
    }while(n>r);
    do{
        printf("Enter the number of column you want to find sum of: ");
        scanf("%d",&n2);
        if(n2>c){
            printf("Enter valid column number\n");
        }
    }while(n2>c);
    int sum,sum2=0;
    for(int j=0;j<c;j++){
        sum+=arr1[n-1][j];
    }
    for(int j=0;j<r;j++){
        sum2+=arr1[j][n2-1];
    }
    printf("Your matrix is:\n");
    print_matrix(arr1,r,c);
    printf("The sum of row number %d is %d. \n",n,sum);
    printf("The sum of column number %d is %d. \n",n2,sum2);
    printf("\n");
    printf("\n");
    printf("\n");

}
void symmetric_matrix(){
    int arr1[20][20],arr2[20][20],r,c;
    printf("Enter the no of rows and columns in your matrix respectively:\n");
    scanf("%d %d",&r,&c);
    input_matrix(arr1,r,c);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            arr2[j][i]=arr1[i][j];
        }
    }
    printf("Your matrix is: \n");
    print_matrix(arr1,r,c);
    printf("\n");
    printf("Transpose of your matrix is:\n");
    print_matrix(arr2,c,r);
    printf("\n");
    int check=1;
    if(r!=c){
        check=0;
    } else{
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(arr1[i][j]==arr2[i][j]){
                    check=1;
                } else{
                    check=0;
                    break;
                }
            }
        }
    }
    
    if (check==1){
        printf("Symmetric matrix.\n");
    }
    else{
        printf("Not symmetric\n ");
    }
    printf("\n");
    printf("\n");
    printf("\n");

}

void transpose_matrix(){
    int arr1[20][20],arr2[20][20];
    int r,c;
    printf("Enter the no of rows and columns in your matrix respectively:\n");
    scanf("%d %d",&r,&c);
    input_matrix(arr1,r,c);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            arr2[j][i]=arr1[i][j];
        }
    }
    printf("Your matrix:\n");
    print_matrix(arr1,r,c);
    printf("The transpose of your matrix is: \n");
    print_matrix(arr2,c,r);
    printf("\n");
    printf("\n");
    printf("\n");
    
}

void main(){
    int play=1;
        int choice;
    while(play==1){
        menu();
        do{
        scanf("%d",&choice);
        if(!(choice>=0 && choice<=6)){
            printf("Enter valid choice\n");
        }
        }while(!(choice>=0 && choice<=6));
        printf("\n");
        if(choice==0){
            play=0;
        } else if(choice==1){
            display_matrix();

        }else if(choice==2){
            
            add_matrix();

        }else if(choice==3){

            matrix_multiply();

        }else if(choice==4){

            row_sum_column_sum();

        }else if(choice==5){

            symmetric_matrix();

        }else if(choice==6){

            transpose_matrix();

        }else{
            printf("Enter valid choice! ");
        }
        
    }
}
