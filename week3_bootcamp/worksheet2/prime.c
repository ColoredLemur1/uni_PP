#include <stdio.h>

int isprime(int number){
    int i;
    int var=1;
    for(i=2;i<number;i++){
        if(number%i==0){
            var = 0;
            break;
        }
    }
    return var;
}

int main(){
    int number=7;
    printf("the number %d, is categorised as: %d\n",number,isprime(number));
    return 0;
}