#include <stdio.h>

float area(float radius){
    float pi = 3.1415;
    float area = pi *(radius*radius);
    return area;
}

int main(){
    float radius;
    printf("enter the radius of the circle:");
    scanf("%f",&radius);
    printf("the area of the circle with radius %f, is: %f\n",radius,area(radius));
    return 0;
}