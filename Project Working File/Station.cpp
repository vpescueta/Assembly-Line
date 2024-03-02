// Name: Vincent Paul Escueta
// Seneca Student ID: 159627223
// Seneca email: vpescueta@mysenecca.ca
// Date of completion: 25 February 2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "Station.h"
#include "Utilities.h"

namespace seneca{

size_t Station::m_idGenerator = 0;
size_t Station::m_widthField = 0;

Station::Station(const std::string str){
    Utilities ut;
    bool keepLooking{true};
    size_t nextPos{};
    std::vector<std::string> container;
    do{
        try{
            container.push_back(ut.extractToken(str, nextPos, keepLooking));
        }catch(const std::string& e){
            keepLooking = false;
            std::cout << e;
        }
    }while(keepLooking && str.length()!= std::string::npos);
    
    if(!container.empty() && container[0].front() != ut.getDelimiter()){
        m_itemName = container[0];
        if(m_itemName.length() > m_widthField){
            m_widthField = m_itemName.length();
        }
        m_SerNo = std::stoull(container[1]);
        m_currStockQty = std::stoull(container[2]);
        m_desc = container[3];
        m_id = ++m_idGenerator; 
    }

}

const std::string& Station::getItemName() const{
    return m_itemName;
}

size_t  Station::getNextSerialNumber(){
    return m_SerNo++;
}

size_t Station::getQuantity() const{
    return m_currStockQty;
}
void Station::updateQuantity(){
    if(m_currStockQty > 0){
        m_currStockQty--;
    }
}

void Station::display(std::ostream& ostr, bool full) const{
    ostr << std::right << std::setw(3) <<  std::setfill('0') << m_id << " | ";
    ostr << std::left <<  std::setfill(' ') << std::setw(static_cast<int>(Station::m_widthField)) << m_itemName << " | ";
    ostr << std::right << std::setw(6) <<  std::setfill('0') << m_SerNo << " | ";
    if(full){
        ostr << std::setfill(' ') << std::setw(4) << m_currStockQty << " | ";
        ostr << std::left << m_desc;
    }
    
    ostr << std::endl;
}

//std::ostream& operator<<(std::ostream& ostr, const Station& s){
//    return s.display(ostr, bool full)
//}
}
