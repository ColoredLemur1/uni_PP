#include <stdio.h>

int main(){
    int x;
    int y;
    printf("enter the number of the width of rectangle: ");
    scanf("%d",&x);
    printf("enter the number of the height of rectangle: ");
    scanf("%d",&y);

    int area = y*x;
    
    printf("the area of the rectangle is: %d \n",area);
    return 0;

}