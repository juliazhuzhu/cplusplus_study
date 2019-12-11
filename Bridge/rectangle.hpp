#ifndef __RECTANGLE__HPP
#define __RECTANGLE__HPP

#include "shape.hpp"

class Rectangle:public Shape{

public:
    Rectangle(Drawing* drawing, double x1, double y1, double x2, double y2):Shape(drawing){
        _x1 = x1;
        _x2 = x2;
        _y1 = y1;
        _y2 = y2;
    }

    virtual void draw(){
        Shape::drawLine(_x1,_x2,_y1,_y2);
        Shape::drawLine(_x2,_x1,_y1,_y2);
        Shape::drawLine(_x1,_x2,_y2,_y1);
        Shape::drawLine(_x2,_x1,_y2,_y1);
    }

private:
    double _x1;
    double _x2;
    double _y1;
    double _y2;
};

#endif