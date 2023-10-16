#include <stdio.h>

int main() {
    int numbers[5] = {1,3,5,8,3};
    int i;
    int last=numbers[4];

    for(i=4;i>=0;i--){
        if (i==0){
            numbers[i]=last;
        }else{
            numbers[i]=numbers[i-1];
        }
    }
    
    for (i=0;i<5;i++){
        printf("%d\n",numbers[i]);
    }

    return 0;
}