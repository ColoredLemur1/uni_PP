#include <stdio.h>

int main(){
    int temp;
    printf("enter temperature: ");
    scanf("%d",&temp);
    if(temp<10){
        printf("Put on the jacket\n");
    }else{
        printf("put on the jumper\n");
    }
    return 0;
}