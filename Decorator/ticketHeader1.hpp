#ifndef __SALES_TICKET_HEADER_1__HPP
#define __SALES_TICKET_HEADER_1__HPP

#include "decoratorComponent.hpp"
#include <stdio.h>

class CTicketHeader1:public CDecoratorComponent{

public:
    CTicketHeader1(Component* comps):CDecoratorComponent(comps){

    }

    virtual void printTicket(){
        printf("header 1 \n");
        CDecoratorComponent::printTicket();
    }
};

#endif