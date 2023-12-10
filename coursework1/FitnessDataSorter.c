#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
    int index;
} FitnessData;

typedef struct{
    int steps;
    int index;
} Sorting;

// Function to tokenize a record
/*void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
}*/
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

                    }
void swap(Sorting *a,Sorting *b) {
    Sorting temp = *a;
    *a = *b;
    *b = temp;
}

void sortByVariable1(Sorting arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].steps > arr[j + 1].steps) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void printArray(Sorting arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("(%d, %d) ", arr[i].steps, arr[i].index);
    }
    printf("\n");
}

int main() {
    int buffer_size = 130;
    char line[buffer_size];
    char buffer[buffer_size];
    char filename[buffer_size];
    char date[11], time[6], csteps[7];
    FitnessData data[130];
    int counter=0;
    int n;
    int i;
    FitnessData ordereddata[100];


    printf("enter th ename of the data file: ");
    fgets(line,buffer_size,stdin);
    sscanf(line,"%s ",filename);

    FILE *input = fopen(filename, "r");
    if (!input){
        printf("]Error: could not open file\n");
        return 1;
    }

    while(fgets(line,buffer_size,input)!= NULL ){
        tokeniseRecord(line, ",",date,time,csteps);
        strcpy(data[counter].date,date);
        strcpy(data[counter].time,time);
        data[counter].steps=atoi(csteps);
        data[counter].index=counter;
        counter++;
    }
    Sorting steps[counter];
    for(i=0;i<counter;i++){
        steps[i].steps=data[i].steps;
        steps[i].index=data[i].index;
    }

    n= sizeof(steps)/sizeof(steps[0]);
    printArray(steps,n);
    sortByVariable1(steps,n);
    printf("\n");
    printArray(steps,n);



    for(i=0;i<counter;i++){
        
    }





    




    
    
}