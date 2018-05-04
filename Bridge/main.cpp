#include "rectangle.hpp"
#include "v1drawing.hpp"


int main(){

    V1Drawing * drawing = new V1Drawing();
    Rectangle* rect = new Rectangle(drawing,1,2,3,4);

    rect->draw();

    return 1;

}