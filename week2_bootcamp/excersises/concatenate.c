#include <stdio.h>

int main() {
    int numbers[3] = {1,3,5};
    int numbers2[3]= {3,9,4};
    int result[6];
    int i;
    

    for(i=0;i<6;i++){
        if(i>2){
            result[i]=numbers2[i-3];
        }else{
            result[i]=numbers[i];
        }
    }

    for(i=0;i<6;i++){
        printf("%d\n",result[i]);
    }

    return 0;
}