#include <stdio.h>

int main(){
    int number;
    printf("enter the temperature in celcius: ");
    scanf("%d",&number);
    if(number>-10 && number<40){
        printf("temperature is within -10 and 40 celcius\n");
    }else{
        printf("temperature is not within -10 and 40 celcius\n");
    }

    return 0;
}