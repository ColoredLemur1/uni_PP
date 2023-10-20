#include <stdio.h>

float sum (float a, float b)
{
    float answer;
    answer = a + b;
    return answer;
}

int main () 
{
    float y = 3.5;
    float z = sum(5.0, y);

    printf ("The sum of 5 and %.2f is %.2f\n", y, z);
}

