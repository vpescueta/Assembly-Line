

#ifndef SENECA_CUSTOMERORDER_H
#define SENECA_CUSTOMERORDER_H

#include <iostream>
#include <string>

namespace seneca{

class CustomerOrder{
    struct Item
    {
        std::string m_itemName{};
        size_t m_serialNumber{0};
        bool m_isFilled{false};
        Item(const std::string& src) : m_itemName(src) {};
    };
    
    std::string m_name{};
    std::string m_product{};
    size_t m_cntItem{};
    Item** m_lstItem{};
    static size_t m_widthField;
    
public:
    CustomerOrder() = default;
    CustomerOrder(const std::string str);
    CustomerOrder(const CustomerOrder& clCO) = delete;
    CustomerOrder& operator=(const CustomerOrder& clCO) = delete;
    CustomerOrder(CustomerOrder&& clCO)noexcept;
    CustomerOrder& operator=(CustomerOrder&& clCO)noexcept;
    ~CustomerOrder();
    bool isOrderFilled() const;
    bool isItemFilled(const std::string& itemName) const;
    void fillItem(Station& station, std::ostream& os);
    void display(std::ostream& os) const;
};  // end of class
}   // end of namespace
#endif /* SENECA_CUSTOMERORDER_H */
