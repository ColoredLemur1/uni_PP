#include <stdio.h>
float power(float x,int n)
{
    if(n==0){ return(1.);}
    else
    {
        return(power(x,n-1)*x);
    }
}
float area(float radius){
    float pi = 3.14159;
    float area = (4/3)*pi*(power(radius,3));
    return area;
}

int main(){
    float radius;
    printf("enter the radius of the sphere:");
    scanf("%f",&radius);
    printf("the area of the circle with radius %f, is: %f\n",radius,area(radius));
    return 0;
}