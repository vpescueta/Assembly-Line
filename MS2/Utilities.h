// Name: Vincent Paul Escueta
// Seneca Student ID: 159627223
// Seneca email: vpescueta@mysenecca.ca
// Date of completion: 25 February 2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SENECA_UTILITIES_H
#define SENECA_UTILITIES_H

#include <iostream>
#include <string>

namespace seneca{
class Utilities{
    size_t m_widthField{1};
    static char m_delimiter;
public:
    Utilities() = default;
    Utilities& setFieldWidth(size_t newWidth);
    size_t getFieldWidth() const;
    std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
    static void setDelimiter(char newDelimiter);
    static char getDelimiter();
    std::string& allTrim(std::string& str);
}; // end of class

} // end of namespace

#endif /* SENECA_UTILITIES_H */
