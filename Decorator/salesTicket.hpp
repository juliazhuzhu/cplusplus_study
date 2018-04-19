#ifndef __SALES_TICKET__HPP
#define __SALES_TICKET__HPP

#include "component.hpp"
#include <stdio.h>

class CSalesTicket: public Component{

public:

    virtual void printTicket(){
        printf("the red sparrow is now on sale. \n");
    }

};

#endif