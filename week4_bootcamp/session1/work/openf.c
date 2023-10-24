#include <stdio.h>

int main(){
    char filename[]="myfile.txt";
    FILE *file = fopen(filename, "w");
    fprintf(file,"yappy yappy yappy yap");
    if (file==NULL){
        perror("FILE I/O");
        return 1;
    }
    fclose(file);

    return 0;
}