#include <stdio.h>

int main() {
    int numbers[] = {1,3,5,8,3};
    int i;
    int sum = 0;

    int size = *(&numbers+1) - numbers;

    for(i=0;i<size;i++){
        printf("%d \n",i);
        sum+= numbers[i];
    }
    printf("the sum of the array is %d\n",sum);

    return 0;
}