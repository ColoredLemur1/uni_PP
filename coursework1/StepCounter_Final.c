#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array


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
    int buffer_size = 100;
    char line[buffer_size];
    char buffer[buffer_size];
    char filename[buffer_size];
    int counter;
    char choice;
    char date[11], time[6], cteps[7];
    int steps;
    int smallest = 2000;
    int smalli;
    int i;
    int biggest;
    int biggi;
    int total;
    int mean;
    int starti;
    int endi;
    int interval;
    int period;
    int oldinterval;
    FITNESS_DATA data[100];


    while (1){
        printf("A: Specify the filename to be imported\n");
        printf("B: Display the total number of records in the file\n");
        printf("C: Find the date and time of the timeslot with the fewest steps\n");
        printf("D: Find the data and time of the timeslot with the largest number of steps\n");
        printf("E: Find the mean step count of all the records in the file\n");
        printf("F: Find the longest continuous period where the step count is above 500 steps\n");
        printf("Q: Exit\n");

        choice = getchar();
        
        while (getchar() != '\n');

        switch(choice){

            case 'A':
            case 'a':
                counter =0;
                printf("enter the name of the data file: ");

                fgets(line,buffer_size, stdin);
                sscanf(line, "%s ", filename);

                FILE *input = fopen(filename, "r");
                if (!input){
                    printf("Error: could not open file\n");
                    return 1;
                }
                while(fgets(line,buffer_size,input) != NULL){
                    tokeniseRecord(line,",",date,time,cteps);
                    strcpy(data[counter].date,date);
                    strcpy(data[counter].time,time);
                    data[counter].steps=atoi(cteps);
                    counter++;
                }
                break;
            case 'B':
            case 'b':
                printf("Total Records: %d\n",counter);
                break;
            
            case 'C':
            case 'c':
                for(i=0;i<counter;i++){
                    if(data[i].steps<smallest){
                        smallest=data[i].steps;
                        smalli = i;
                    }
                }

                printf("Fewest steps: %s %s\n",data[smalli].date,data[smalli].time);
                break;
            
            case 'D':
            case 'd':
                for(i=0;i<counter;i++){
                    if(data[i].steps > biggest){
                        biggest = data[i].steps;
                        biggi=i;
                    }
                }

                printf("Largest steps: %s %s\n",data[biggi].date,data[biggi].time);
                break;
            
            case 'E':
            case 'e':
                total =0;
                for(i=0;i<counter;i++){
                    total+=data[i].steps;
                }
                mean = total/counter;
                printf("Mean step count: %d\n",mean);
                break;
            
            case 'F':
            case 'f':
                interval=0;
                for(i=0;i<counter;i++){
                    if(data[i].steps > 500){
                        if(interval >= oldinterval){
                            period=1;
                            endi = i;
                        }else{
                            period=0;
                        }
                        if(interval==0){
                            starti=i;
                        }
                        interval+=1;
                    }else{
                        if(period=1){
                            oldinterval=interval;
                        }
                        interval=0;
                        period=0;
                        
                    }

                }
                starti=starti+1;

                printf("Longest period start: %s %s\n",data[starti].date,data[starti].time);
                printf("Longest period end: %s %s\n",data[endi].date,data[endi].time);
                break;
            
            case 'Q':
            case 'q':
                return 0;
                break;

        }
    }
   
}