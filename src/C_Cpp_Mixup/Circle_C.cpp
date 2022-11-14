#include "Circle_C.h"
#include "Circle.h"

void* Circle_C_New(float radius){
    return new Circle(radius);
}

void Circle_C_Delete(void* circle){
    delete (Circle*)circle;
}

float Circle_C_GetArea(void* circle){
    return ((Circle*)circle)->GetArea();
}

