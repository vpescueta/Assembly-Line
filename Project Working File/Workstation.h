
// Name: Vincent Paul Escueta
// Seneca Student ID: 159627223
// Seneca email: vpescueta@mysenecca.ca
// Date of completion: 29 March 2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SENECA_WORKSTATION_H
#define SENECA_WORKSTATION_H

#include <iostream>
#include <deque>
#include <string>
#include "CustomerOrder.h"
#include "Station.h"


namespace seneca{
extern std::deque<CustomerOrder> g_pending;
extern std::deque<CustomerOrder> g_completed;
extern std::deque<CustomerOrder> g_incomplete;

class Workstation : public Station{
    std::deque<CustomerOrder> m_orders{};
    Workstation* m_pNextStation{};
public:
   
    Workstation(const std::string s);
    ~Workstation();
    Workstation(const Workstation& w) = delete;
    Workstation& operator=(const Workstation& w) = delete;
    Workstation(const Workstation&& w) = delete;
    Workstation& operator=(Workstation&& w) = delete;
    void fill(std::ostream& os);
    bool attemptToMoveOrder();
    void setNextStation(Workstation* station = nullptr);
    Workstation* getNextStation() const;
    void display(std::ostream& os) const;
    Workstation& operator+=(CustomerOrder&& newOrder);
    
}; // end of class
} // end of namespace

#endif /* SENECA_WORKSTATION_H */
