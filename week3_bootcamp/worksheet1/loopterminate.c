#include <stdio.h>

int main(){
    int number;
    while(number!=-1){
        printf("enter the number: ");
        scanf("%d",&number);
        if(number!=-1){
            if(number<=100 && number>=0){
                printf("number is %d\n",number); 
            }else{
                printf("number %d is outside range of 0 to 100\n",number);  
            }
        }
    }
    printf("loop terminated number is %d\n",number);
    return 0;
}