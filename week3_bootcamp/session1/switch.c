#include <stdio.h>

int main(){
    int label=-1;
    while (label<0 || 4<label){
        printf("enter label between 0 and 4: ");
        scanf("%d",&label);
        if(label<0 || 4<label){
            printf("invalid option please enter number again\n");
        }
    }
    switch(label){
        case 0:
            printf("hello world\n");
            break;
        case 1:
            printf("goodbye world\n");
            break;
        case 2:
            printf("option number 3\n");
            break;
        case 3:
            printf("option number 4\n");
            break;
        case 4:
            printf("option number 5\n");
            break;
    }
    
    return 0;
}