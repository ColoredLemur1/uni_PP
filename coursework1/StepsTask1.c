#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "utils.h"

// Define an appropriate struct
typedef struct FITNESS_DATA{
	char date[11];
	char time[6];
	char steps[4];
} FITNESS_DATA;

// Define any additional variables here



// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
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



// Complete the main function
int main() {
    char filename[]="FitnessData_2023.csv";
    FILE *file= fopen(filename,"r");
    FITNESS_DATA data[100];
    int buffer_size = 100;
    char buffer[buffer_size];
    int count=0;
    int i;
    while (fgets(buffer,buffer_size,file) != NULL){
        tokeniseRecord(buffer,",",data[count].date,data[count].time,data[count].steps);
        count+=1;
    }
    printf("Number of records in file: %d\n",count);
    
    for(i=0;i<3;i++){
        printf("data: %s/%s/%s\n",data[i].date,data[i].time,data[i].steps);
    }
    fclose(file);
    return 0;


}
