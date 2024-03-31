// Name: Vincent Paul Escueta
// Seneca Student ID: 159627223
// Seneca email: vpescueta@mysenecca.ca
// Date of completion: 15 March 2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <utility>
#include <string>
#include <iomanip>
#include <vector>

#include "CustomerOrder.h"
#include "Utilities.h"
#include "Station.h"

namespace seneca{
size_t CustomerOrder::m_widthField = 0;
// one arg constructor
CustomerOrder::CustomerOrder(const std::string str){
    Utilities ut;
    bool keepLooking{true};
    size_t nextPos{};
    std::vector<std::string> custOrder;
    
    do{
        try{
            custOrder.push_back(ut.extractToken(str, nextPos, keepLooking));
        }catch(const std::string& e){
            keepLooking = false;
            std::cout << e;
        }
    }while(keepLooking && str.length()!= std::string::npos);
    
    if(!custOrder.empty() && custOrder[0].front() != ut.getDelimiter()){
        m_cntItem = custOrder.size() - 2;             // total size minus 2 fields (name and product fields)
        m_name = custOrder[0];
        m_product = custOrder[1];
        m_items = new Item*[m_cntItem];
        for(size_t i = 2; i < m_cntItem + 2; i++){
            m_items[i - 2] = new Item(custOrder[i]);
        }
    }
    //    m_name
    //    m_product
    if(CustomerOrder::m_widthField < ut.getFieldWidth()){
        m_widthField = ut.getFieldWidth();
    }
}

CustomerOrder::CustomerOrder(const CustomerOrder& clCO){
    throw false;
}

// move constructor
CustomerOrder::CustomerOrder(CustomerOrder&& clCO)noexcept{
    *this = std::move(clCO);
}

// move assignment operator
CustomerOrder& CustomerOrder::operator=(CustomerOrder&& clCO)noexcept{
    if(this!=&clCO){
        for(size_t i = 0; i < m_cntItem; i++){
            delete m_items[i];
        }
        delete [] m_items;
        
        m_items = clCO.m_items;
        m_product = clCO.m_product;
        m_name = clCO.m_name;
        m_cntItem = clCO.m_cntItem;
        
        clCO.m_items = nullptr;
        clCO.m_product = "";
        clCO.m_name = "";
        clCO.m_cntItem = 0;
    }
    return *this;
}

// destructor
CustomerOrder::~CustomerOrder(){
    for(size_t i = 0; i < m_cntItem; i++){
        delete m_items[i];
    }
    delete [] m_items;
}

bool CustomerOrder::isOrderFilled() const{
    bool result{true};
    for(size_t i = 0; i < m_cntItem && result; i++){
        m_items[i]->m_isFilled ? result = true : result = false;
    }
    return result;
}

bool CustomerOrder::isItemFilled(const std::string& itemName) const{
    bool result{true};
    for(size_t i = 0; i < m_cntItem && result; i++){
        bool match = matchItem(itemName, m_items[i]->m_itemName);
        if(match){
            if(!m_items[i]->m_isFilled){
                result = false;
            }
        }
    }
    
    return result;
}

void CustomerOrder::fillItem(Station& station, std::ostream& os){
    bool match{false};
    for(size_t i = 0; i < m_cntItem && !match; i++){
        std::clog.setstate(std::ios::failbit);
        std::clog << station.getItemName()<< std::endl;
        std::clog << m_items[i]->m_itemName<< std::endl;
        match = matchItem(station.getItemName(), m_items[i]->m_itemName);
        if(match){
            if(station.getQuantity()){
                station.updateQuantity();
                m_items[i]->m_isFilled = true;
                station.getNextSerialNumber();
                os << "    Filled ";
            }else{
                os << "    Unable to fill ";
            }
            os << m_name <<", " <<
            m_product << " [" <<
            m_items[i]->m_itemName << "]" << std::endl;
        }
    }
}



void CustomerOrder::display(std::ostream& os) const{
    //    CUSTOMER_NAME - PRODUCT
    //    [SERIAL] ITEM_NAME - STATUS
    os << m_name << " - " << m_product << std::endl;
    for(size_t i = 0; i < m_cntItem; i++){
        os << "[" << std::setw(6) << std::setfill('0') << m_items[i]->m_serialNumber << "] " << std::setfill(' ') <<
        std::left << std::setw(static_cast<int>(m_widthField)) << m_items[i]->m_itemName <<
        ((m_items[i]->m_isFilled) ? "FILLED" : " - TO BE FILLED") << std::endl;
    }
}

bool CustomerOrder::matchItem(std::string searchFor, std::string searchIn){
    return searchFor == searchIn;
}


} // end of namespace
