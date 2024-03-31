// Name: Vincent Paul Escueta
// Seneca Student ID: 159627223
// Seneca email: vpescueta@mysenecca.ca
// Date of completion: 15 March 2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SENECA_CUSTOMERORDER_H
#define SENECA_CUSTOMERORDER_H

#include <iostream>
#include <string>
#include "Station.h"

namespace seneca{

class CustomerOrder{
    struct Item
    {
        std::string m_itemName{};
        size_t m_serialNumber{0};
        bool m_isFilled{false};
        Item(const std::string& src) : m_itemName(src) {};
    };
    
    std::string m_name{};                                               // customer name
    std::string m_product{};                                            // name of product being assembled
    size_t m_cntItem{};                                                 // count of items in the customer's order
    Item** m_items{};
    static size_t m_widthField;                                         // maximum width of a field, used for display
    
public:
    CustomerOrder() = default;                                          // default constructor
    CustomerOrder(const std::string str);                               // one-arg constructor
    CustomerOrder(const CustomerOrder& clCO);                           // copy constructor
    CustomerOrder& operator=(const CustomerOrder& clCO) = delete;       // copy assignment constructor
    CustomerOrder(CustomerOrder&& clCO)noexcept;                        // move copy constructor
    CustomerOrder& operator=(CustomerOrder&& clCO)noexcept;             // move assignment constructor
    virtual ~CustomerOrder();                                           // destructor
    bool isOrderFilled() const;
    bool isItemFilled(const std::string& itemName) const;
    void fillItem(Station& station, std::ostream& os);
    void display(std::ostream& os) const;
    static bool matchItem(std::string searchFor, std::string searchIn);
};  // end of class
}   // end of namespace
#endif /* SENECA_CUSTOMERORDER_H */
