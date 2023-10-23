#include <stdio.h>


int length(char* string){
    int len=0;
    while(*string != '\0'){
        len++;
        string++;
    }
    return len;
}


int main(){
    char string[]="fifa";
    printf("the length of the string %s,is %d\n",string,length(string));
    return 0;
}