#ifndef __V2DRAWING__HPP
#define __V2DRAWING__HPP
#include <stdio.h>

#include "drawing.hpp"
class V2Drawing: public Drawing{

public:
    virtual void drawLine(double x1, double y1, double x2, double y2){
        printf("printf v2 drawLine %f %f %f %f\n", x1, y1,x2, y2 );
    }

    virtual void drawCircle(double x, double y, double r){
        printf("printf v2 drawCircle %f %f %f \n", x, y, r);
    }
};

#endif