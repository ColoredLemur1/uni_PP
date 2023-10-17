#include <stdio.h>

int main(){
    int number;
    printf("enter the number: ");
    scanf("%d",&number);
    if(number%4==0 && number%5==0){
        printf("number is divisible by 4 and 5\n");
    }else{
        printf("number is not divisible by 4 and 5\n");
    }

    return 0;
}