#ifndef __TICKET_FOOTER_1_HPP
#define __TICKET_FOOTER_1_HPP

#include "decoratorComponent.hpp"
#include <stdio.h>

class CSalesFooter1: public CDecoratorComponent{

public:

    CSalesFooter1(Component* comps):CDecoratorComponent(comps){

    }
    
    virtual void printTicket(){
        
        CDecoratorComponent::printTicket();
        printf("footer 1 \n");
    }
};

#endif