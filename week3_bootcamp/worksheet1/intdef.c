#include <stdio.h>

int main(){
    int number;
    printf("enter the number: ");
    scanf("%d",&number);
    if(number>0){
        printf("number is a positive number\n");
    }else if(number<0){
        printf("number is a negative number\n");
    }else{
        printf("number is zero\n");
    }

    return 0;
}