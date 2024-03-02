// Name: Vincent Paul Escueta
// Seneca Student ID: 159627223
// Seneca email: vpescueta@mysenecca.ca
// Date of completion: 25 February 2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SENECA_STATION_H
#define SENECA_STATION_H

#include <iostream>
#include <string>

namespace seneca{
class Station{
    size_t m_id;
    std::string m_itemName;
    std::string m_desc;
    size_t m_SerNo;
    size_t m_currStockQty;
    static size_t m_widthField;
    static size_t m_idGenerator;
public:
    Station(const std::string str);
    const std::string& getItemName() const;
    size_t getNextSerialNumber();
    size_t getQuantity() const;
    void updateQuantity();
    void display(std::ostream& ostr, bool full) const;
}; // end of class
std::ostream& operator<<(std::ostream& ostr, const Station& s);

} // end of namespace

#endif /* SENECA_STATION_H */
