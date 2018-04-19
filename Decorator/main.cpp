#include "salesTicket.hpp"
#include "ticketFooter1.hpp"
#include "ticketHeader1.hpp"

int main(){

    Component* pDecorator = new CTicketHeader1 (new CSalesFooter1(new CSalesTicket()));

    pDecorator->printTicket();

    return 1;
}