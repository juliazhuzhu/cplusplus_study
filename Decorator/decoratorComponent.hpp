#ifndef __DECORATOR_COMPONENT__HPP
#define __DECORATOR_COMPONENT__HPP

#include "component.hpp"
class CDecoratorComponent :public Component{

public:
    CDecoratorComponent(Component* comp){
        printf("CDecoratorComponent %p\n",comp);
        _myComp = comp;
    }

    virtual void printTicket () { 
        printf("%p \n",_myComp);
        if (_myComp != NULL)
            _myComp->printTicket(); 
    }

protected:
    Component* _myComp;
};

#endif 