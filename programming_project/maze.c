#include <stdio.h>
#include <string.h>
#include "utils.h"
#include <assert.h>
#include "errors.h"

typedef struct Player{
    char symbol;
    int move;
    int pos[1];
    
} Player;
// player struct that will be used to move the palyer piece in the board

int userInput(char *input){
    return 0;
}
// user input function used to return a variable based on user input (WASD)

char openFile(){
    return '';
}// function used to open the maze file and return a 2d array of characters of the maze

int checkMaze(){
    return 0;
}// function used to check that the maze is valid and will return 1 if valid 0 if not

void displayMaze(char *maze){

}//void function used to display maze

int checkWin(char *maze){
    return 0;
}//function used to check if the player has finished the maze

int updateMaze(char *maze,int unserInput){
    
    checkWin();
    //checks if the player has won and returns a value based on that
    return 0;
}//function will update the maze depending on user input



int main(int argc,char *argv[]){
    int Win = 0;
    int termination=0;


    assert(argv[1] != NULL);
    char filename = argv[1];
    //filename retrieved from command line

    openFile();

    checkMaze();

    displayMaze();
   
    while(Win!=1){
        //while loop that runs while player hasn't finsished the maze

        userInput();    
        Win=updateMaze();
        //updates maze based on user input and returns value to the Win variable

    }

    //outputs a message indicating the player that he/she has won

    
    return termination;
}
