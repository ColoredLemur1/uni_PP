#include <stdio.h>

int main() {
    int numbers[5] = {1,3,5,8,3};
    int i;
    int last=numbers[4];

    for(i=0;i<5;i++){
        if (i==4){
            numbers[0]=last;
            printf("whatt\n");
        } else{
            int temp = numbers[i];
            numbers[i+1]=temp;
            printf("hello %d\n",numbers[i]);
        }
        
    }
    
    for (i=0;i<5;i++){
        printf("%d\n",numbers[i]);
    }

    return 0;
}