#ifndef __CIRCLE__HPP
#define __CIRCLE__HPP

#include "shape.hpp"

class Circle:public Shape{
public:
    Circle(Drawing* drawing, double x, double y, double r):Shape(drawing){
        _x = x;
        _y = y;
        _r = r;
    }
    
    virtual void draw(){
        Shape::drawCircle(_x,_y,_r);
    }

private:
    double _x;
    double _y;
    double _r;
    
};

#endif