#include <stdio.h>

int main(){
    char filename[]="classwork1.txt";
    FILE *file = fopen(filename, "w");
    int numnum;
    int nums[50];
    int i;
    int sum=0;
    int mean;
    int num;
    printf("how many numbers do you wish to enter: ");
    scanf("%d",&numnum);
    for(i=0;i<numnum;i++){
        printf("enter a number: ");
        scanf("%d",&nums[i]);
    }
    for(i=0;i<numnum;i++){
        sum+=nums[i];
    }
   
    mean = sum / numnum;
    fprintf(file,"the mean is %d\n",mean);

    if (file==NULL){
        perror("FILE I/O");
        return 1;
    }
    //printf("file is %d\n",file);
    fclose(file);

    return 0;
}