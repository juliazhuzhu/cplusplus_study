#ifndef __SHAPE__HPP
#define __SHAPE__HPP
#include "drawing.hpp"

class Shape{

public:

    Shape(Drawing* drawing){
        _drawing = drawing;
    }

    virtual void draw() = 0;

protected:

    virtual void drawLine(double x1, double x2, double y1, double y2){
        _drawing->drawLine(x1, y1, x2, y2);
    }

    virtual void drawCircle(double x, double y, double r){
        _drawing->drawCircle(x, y ,r);
    }

private:

    Drawing* _drawing;

	
};

#endif