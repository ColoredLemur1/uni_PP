#include <stdio.h>

float sum(float num1,float num2){
    return num1+num2;
}

float sub(float num1, float num2){
    return num1-num2;
}

float div(float num1,float num2){
    return num1/num2;
}

float multiply(float num1, float num2){
    return num1*num2;
}

int main(){
    float num1;
    float num2;
    int operator;
    printf("enter number 1: ");
    scanf("%f",&num1);
    printf("enter number 2: ");
    scanf("%f",&num2);
    printf("now enter what arithmetic operator you want to use (+,-,*,/) (0,1,2,3): ");
    scanf("%d",&operator);

    switch(operator){
        case 0:
            printf("the addition of both numbers is: %f\n",sum(num1,num2));
            break;
        case 1:
            printf("the substraction of number 1 - number 2 is: %f\n",sub(num1,num2));
            break;
        case 2:
            printf("the multiplication of both numbers is: %f\n",multiply(num1,num2));
            break;
        case 3:
            printf("the division of number 1 by number 2 is: %f\n",div(num1,num2));
            break;
    }

}