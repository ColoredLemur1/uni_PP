#ifndef UTILS_H
#define UTILS_H
#include <stdio.h>
#include <stdlib.h>

FILE *open_file(char filename[],char mode[]){
    FILE *file = fopen(filename,mode);
    if (file==NULL){
        perror("FILE I/O");
        return 1;
    }
    return file;
}
#endif