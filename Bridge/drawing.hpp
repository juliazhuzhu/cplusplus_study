#ifndef __DRAWING__HPP
#define __DRAWING__HPP
class Drawing{
public:
    virtual void drawLine(double x1, double y1, double x2, double y2)=0;
    virtual void drawCircle(double x, double y, double r) = 0;
};

#endif