

#include <iostream>
#include <utility>
#include <string>
#include <iomanip>
#include "CustomerOrder.h"

namespace seneca{

// move constructor
CustomerOrder::CustomerOrder(CustomerOrder&& clCO)noexcept{
    *this = std::move(clCO);
}

// move assignment operator
CustomerOrder& CustomerOrder::operator=(CustomerOrder&& clCO)noexcept{
    if(this!=&clCO){
        for(size_t i = 0; i < m_cntItem; i++){
            delete m_lstItem[i];
        }
        delete m_lstItem;
        
        m_lstItem = clCO.m_lstItem;
        m_product = clCO.m_product;
        m_name = clCO.m_name;
        m_cntItem = clCO.m_cntItem;
        
        clCO.m_lstItem = nullptr;
        clCO.m_product = "";
        clCO.m_name = "";
        clCO.m_cntItem = 0;
}

// destructor
~CustomerOrder::CustomerOrder(){
    delete[] m_lstItem;
}
} // end of namespace
