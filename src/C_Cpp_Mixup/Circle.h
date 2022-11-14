#ifndef CIRCLE_H_
#define CIRCLE_H_

#include <stdio.h>

class Circle{
public:
    Circle(float radius) : radius_(radius){printf("调用Circle构造函数\n");}
    float GetArea(){return 3.1415926 * this->radius_ * this->radius_;}
    ~Circle(){printf("调用Circle析构函数\n");}

private:
    float radius_;
};

#endif