#include <stdio.h>

int main() {
    int numbers[] = {1,3,5,8,3};
    int i;
    int size = *(&numbers+1) - numbers;
    int max=0;

    for(i=0;i<size;i++){
        if(numbers[i]>max){
            max=numbers[i];
        }
    }
    printf("the biggest number in the array is %d\n",max);

    return 0;
}