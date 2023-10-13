#include <stdio.h>
#include <string.h>

int main(){
    char word[10];
    printf("enter the word: ");
    scanf("%s",word);
    size_t i;

    int len = strlen(word) -1 ;
    int k = len;

    for(i = 0; i < len; i++){
        char temp = word[k];
        word[k]=word[i];
        word[i]=temp;
        k--;
    }

    printf("the reverse is: /o%s \n",word);
    return 0;

}