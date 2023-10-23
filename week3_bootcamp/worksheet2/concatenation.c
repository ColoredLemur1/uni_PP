#include <stdio.h>
#include <string.h>


char conc(const char* string1,const char* string2){
    int len1=strlen(string1);
    int len2=strlen(string2);
    int len= len1+len2+1;
    int i;
    char conca[len];
    printf("%s\n",string1);
    /*for(i=0;i<len;i++){
        if(i<=len1){
            conca[i]=string1[i];
        }else{
            conca[i]=string2[i-len1];
        }
    }*/
    return string1;
}

int main(){
    char uno[5]="ramon";
    char dos[4]="fifa";
    printf("the concatenated form of the strings is %s",conc(uno,dos));
    return 0;
}