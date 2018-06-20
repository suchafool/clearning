#include <stdio.h>

#define PI 3.14159

int main()
{
    float area, circum, radius;

    printf("What is the radius of your pizza?");
    scanf("%f", &radius);

    area = PI* radius * radius;

    circum = PI * 2 * radius;

    printf("your basic pizza parameters are as follows:\n");
    printf("Circumstance: %f, area: %f \n", circum, area);

    return 0;
}

