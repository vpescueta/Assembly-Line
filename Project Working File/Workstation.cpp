
// Name: Vincent Paul Escueta
// Seneca Student ID: 159627223
// Seneca email: vpescueta@mysenecca.ca
// Date of completion: 29 March 2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

//#include <iostream>
//#include <deque>
//#include <string>
#include "Workstation.h"
//#include "CustomerOrder.h"


namespace seneca{
std::deque<CustomerOrder> g_pending;
std::deque<CustomerOrder> g_completed;
std::deque<CustomerOrder> g_incomplete;

Workstation::Workstation(const std::string s) : Station(s){
    setNextStation();
}

Workstation::~Workstation(){
    delete m_pNextStation;
}

void Workstation::fill(std::ostream& os){
    if(!m_orders.empty()){
        m_orders.front().fillItem(*this, os);
    }
}

bool Workstation::attemptToMoveOrder(){
    bool orderWasMoved{};
    if(m_orders.front().isOrderFilled() || m_orders.front().isItemFilled(getItemName())){
        orderWasMoved = true;
        if(m_pNextStation){
            m_pNextStation->m_orders.push_back(std::move(m_orders.front()));
        }else{
            m_orders.front().isOrderFilled() ? g_completed.push_back(std::move(m_orders.front())) : g_incomplete.push_back(std::move(m_orders.front()));
        }
        m_orders.pop_front();
    }
    return orderWasMoved;
}

void Workstation::setNextStation(Workstation* station){
    m_pNextStation = station;
}

Workstation* Workstation::getNextStation() const{
    return m_pNextStation;
}

void Workstation::display(std::ostream& os) const{
    os << getItemName() << " --> " << (m_pNextStation ? m_pNextStation->getItemName() : "End of Line");
    os << std::endl;
}

Workstation& Workstation::operator+=(CustomerOrder&& newOrder){
    m_orders.push_back(std::move(newOrder));
    return *this;
}

} // end of namespace
