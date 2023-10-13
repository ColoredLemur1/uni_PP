#include <stdio.h>

int main(){
    int a;
    int b =1;
    for (a=0; a<10; a++){
        if (b%2 != 0){
            printf("odd number %d is %d\n",a,b);
        }
        b++;
    }

    return 0;

}