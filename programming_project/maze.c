/**
 * @file maze.c
 * @author Javier Duarte Macias
 * @brief Code for the maze game for COMP1921 Assignment 2
 * NOTE - You can remove or edit this file however you like - this is just a provided skeleton code
 * which may be useful to anyone who did not complete assignment 1.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// defines for max and min permitted dimensions
#define MAX_DIM 100
#define MIN_DIM 5

// defines for the required autograder exit codes
#define EXIT_SUCCESS 0
#define EXIT_ARG_ERROR 1
#define EXIT_FILE_ERROR 2
#define EXIT_MAZE_ERROR 3

typedef struct __Coord
{
    int x;
    int y;
} coord;

typedef struct __Maze
{
    char **map;
    int height;
    int width;
} maze;

/**
 * @brief Initialise a maze object - allocate memory and set attributes
 *
 * @param this pointer to the maze to be initialised
 * @param height height to allocate
 * @param width width to allocate
 * @return int 0 on success, 1 on fail
 */
int create_maze(maze *this, int height, int width)
{   
    //allocate memory for a 2D array height first, then width
    this->map = (char **)malloc(MAX_DIM * sizeof(char *));
    if (this->map == NULL){
        printf("malloc failed \n");
        return 1;
    }

    for (int i =0; i<MAX_DIM; i++){
        this->map[i] = (char *)malloc(MAX_DIM * sizeof(char));
        if (this->map[i] == NULL){
        printf("malloc failed \n");
        return 1;
    }

    }
    

}

/**
 * @brief Free the memory allocated to the maze struct
 *
 * @param this the pointer to the struct to free
 */
void free_maze(maze *this)
{
    if (this == NULL){
        return;
    }
    if (this-> map != NULL){
        for (int i=0; i<this->height;i++){
            free(this->map[i]);

            this->map[i]=NULL;
        }

        free(this->map);
        this->map=NULL;
    }
    free(this);
}

/**
 * @brief Validate and return the width of the mazefile
 *
 * @param file the file pointer to check
 * @return int 0 for error, or a valid width (5-100)
 */
int get_width(FILE *file)
{
    int width =0;
    int expected_rows =0;
    int first_line=0;
    int height=0;
    char line[MAX_DIM+2];
    while (fgets(line, sizeof(line), file) != NULL) {
        int width = 0;

        
        for (int i = 0; line[i] != '\n' && line[i] != '\0'; i++) {
            width++;
        }

        
        if (first_line==0) {
            expected_rows = width;
            first_line = 1;
        }

        
        if (width != expected_rows && !(width == 0 && line[0] == '\n')) {
            printf("Error: Inconsistent width detected on line %d\n", height + 1);
            return 0;
        }
        height++;
    }
    if (expected_rows>MAX_DIM || expected_rows<5){
        return 0;
    }
    return expected_rows;

}

/**
 * @brief Validate and return the height of the mazefile
 *
 * @param file the file pointer to check
 * @return int 0 for error, or a valid height (5-100)
 */
int get_height(FILE *file)
{
    int height =0;
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            height++;
            
        } 

    }
    if (height > MAX_DIM || height < 5) {
            return 0;
        }
    
    return height;

}

/**
 * @brief read in a maze file into a struct
 *
 * @param this Maze struct to be used
 * @param file Maze file pointer
 * @return int 0 on success, 1 on fail
 */
int read_maze(maze *this, FILE *file)
{   
    int row =0;
    int col =0;
    char ch;
    while (fscanf(file,"%c",&ch) != EOF){
        if (ch != '\n' && ch != ' ' && ch != '#' && ch != 'S' && ch != 'E' && ch != '\0'){
            printf("Bad maze \n");
            return 1;
        }
        if (ch == '\n'){
            col=0;
            row++;
            continue;
        }else if (ch == '\0'){
            break;
        }
        this->map[row][col]=ch;
        col++;
    }
    return 0;

}

/**
 * @brief Prints the maze out - code provided to ensure correct formatting
 *
 * @param this pointer to maze to print
 * @param player the current player location
 */
void print_maze(maze *this, coord *player)
{
    // make sure we have a leading newline..
    printf("\n");
    for (int i = 0; i < this->height; i++)
    {
        for (int j = 0; j < this->width; j++)
        {
            // decide whether player is on this spot or not
            if (player->x == j && player->y == i)
            {
                printf("X");
            }
            else
            {
                printf("%c", this->map[i][j]);
            }
        }
        // end each row with a newline.
        printf("\n");
    }
}

/**
 * @brief Validates and performs a movement in a given direction
 *
 * @param this Maze struct
 * @param player The player's current position
 * @param direction The desired direction to move in
 */
void move(maze *this, coord *player, char direction)
{   
    int player_x=player->x;
    int player_y=player->y;

    switch (direction)
    {
    case 'W':
        if (player_y-1 < 0){
            printf("Out of bounds \n");
        }else if (this->map[player_y-1][player_x] == '#')
        {
            printf("Can't move into wall \n");
        }else{
            player_y-=1;
            player->y=player_y;
        }
        break;
    case 'A':
        if (player_x-1 < 0){
            printf("Out of bounds \n");
        }else if (this->map[player_y][player_x-1] == '#')
        {
            printf("Can't move into wall \n");
        }else{
            player_x-=1;
            player->x=player_x;
        }
        break;
    case 'S':
        if (this->height <player_y+1){
            printf("Out of bounds \n");
        }else if (this->map[player_y+1][player_x] == '#')
        {
            printf("Can't move into wall \n");
        }else{
            player_y+=1;
            player->y=player_y;
        }
        break;
    case 'D':
        if (this->width <player_x+1){
            printf("Out of bounds \n");
        }else if (this->map[player_y][player_x+1] == '#')
        {
            printf("Can't move into wall \n");
        }else{
            player_x+=1;
            player->x=player_x;
        }
        break;
    }
}

/**
 * @brief Check whether the player has won and return a pseudo-boolean
 *
 * @param this current maze
 * @param player player position
 * @return int 0 for false, 1 for true
 */
int has_won(maze *this, coord *player)
{
    for (int i =0; i<this->height;i++){
        for(int j=0; j<this->width; j++){
            if(this->map[i][j]=='E'){
                if(player->x ==j && player->y==i){
                    return 1;
                }
            }
        }
    }
    return 0;
}
//int argc, char *argv[]
int main()
{
    // check args
    //if (argc != 2) {
        //printf("Usage: %s <argument>\n", argv[0]);
        //return 1; // Return error code
    //}

    // set up some useful variables (you can rename or remove these if you want)
    coord *player;
    maze *this_maze = malloc(sizeof(maze));
    int height;
    int width;
    char line[MAX_DIM];
    char option;
    player =malloc(sizeof(coord));
    // open and validate mazefile
    FILE *input = fopen("15x9.txt","r");
    if (input == NULL){
        perror("File opening error");
        return 2;
    }
    // read in mazefile to struct
    height=get_height(input);
    if (height==0){
        perror("Invalid Height");
        return 3;
    }
    this_maze->height=height;
    fclose(input);
    input = fopen("15x9.txt","r");
    if (input == NULL){
        perror("File opening error");
        return 2;
    }
    width=get_width(input);
    if (width == 0){
        printf("Invalid Width");
        return 3;
    }
    this_maze->width=width;
    fclose(input);
    input = fopen("15x9.txt","r");
    if (input == NULL){
        perror("File opening error");
        return 2;
    }
    printf("height %d, width %d\n",height, width);
    int check = create_maze(this_maze,height,width);
    if (check == 1){
        perror("Allocation error");
        return 1;
    }
    int check2 = read_maze(this_maze,input);
    if (check2 ==1){
        perror("Invalid Maze");
        return 3;
    }
    fclose(input);
    //initiate player coordinates on the S slot
    for (int i =0; i<this_maze->height;i++){
        for(int j=0; j<this_maze->width; j++){
            if(this_maze->map[i][j]=='S'){
                player->x=j;
                player->y=i;
            }
        }
    }
    // maze game loop
    while(has_won(this_maze,player)!=1){
        printf("Options: \n");
        printf("W: up \n");
        printf("A: left \n");
        printf("S: down \n");
        printf("D: right \n");
        printf("M: Display Maze\n");
        printf(": ");
        scanf("%c",&option);

        switch(toupper(option)){

            case 'W':
                move(this_maze,player,'W');
                break;
            case 'A':
                move(this_maze,player,'A');
                break;
            case 'S':
                move(this_maze,player,'S');
                break;
            case 'D':
                move(this_maze,player,'D');
                break;
            case 'M':
                print_maze(this_maze,player);
                break;
            default:
            printf("invalid input please try this again \n");

        }


    }
    // win
    print_maze(this_maze,player);
    printf("Congratulations you have won! \n");
    free_maze(this_maze);
    free(this_maze);
    free(player);
    // return, free, exit
    return 0;
}