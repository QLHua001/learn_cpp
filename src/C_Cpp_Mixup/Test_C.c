#include <stdio.h>
#include "Circle_C.h"

void Test_C(){
    void* circle = Circle_C_New(3);
    float area = Circle_C_GetArea(circle);
    printf("Circle Area: %f\n", area);
    Circle_C_Delete(circle);
}