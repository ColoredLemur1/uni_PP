#include <stdio.h>

int main() {
    int numbers[6] = {1,3,5,8,3,1};
    int i;
    int x;
    int duplicates[3];
    int duplicate;
    int temp=0;

    for(i=0;i<6;i++){
        duplicate=numbers[i];
        for(x=0;x<6;x++){
            if(duplicate=numbers[x]){
                temp+=1;
            }
        }
        if(temp>1){
            duplicates[i]=numbers[i];
        }
        temp=0;
    }
    
    for(i=0;i<3;i++){
        printf("%d \n",duplicates[i]);
    }

    return 0;
}