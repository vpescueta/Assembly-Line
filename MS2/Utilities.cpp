// Name: Vincent Paul Escueta
// Seneca Student ID: 159627223
// Seneca email: vpescueta@mysenecca.ca
// Date of completion: 25 February 2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <string>

#include "Utilities.h"

namespace seneca{

char Utilities::m_delimiter = '\0';

Utilities& Utilities::setFieldWidth(size_t newWidth){
    m_widthField = newWidth;
    return *this;
}

size_t Utilities::getFieldWidth() const{
    return m_widthField;
}

std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more){
    static std::string tempRetStr;
    std::string returnStr;
    
    size_t delimiterCount{};
    while(str.find(m_delimiter, 0 + delimiterCount) != std::string::npos){
        delimiterCount++;
    }

    if(str.empty() || (str.substr(next_pos,1)[0] == m_delimiter)){
        more = false;
        throw "ERROR: No token.";
    }else{
        if(delimiterCount){
            
            if(m_delimiter == (str.substr(next_pos,1))[0]){
                more = false;
            }else{
                tempRetStr = str.substr(next_pos, str.find(m_delimiter, next_pos) - next_pos);
                next_pos = next_pos + tempRetStr.length() + 1;
                returnStr = allTrim(tempRetStr);
                more = ((next_pos - 1) <= str.rfind(m_delimiter));
            }
        }else{
            tempRetStr = str;
            returnStr = allTrim(tempRetStr);
            more = false;
        }

        
        if(m_widthField < returnStr.length()){
            m_widthField = returnStr.length();
        }
        return returnStr;
    }
}

// removes leading and trailing spaces
std::string& Utilities::allTrim(std::string& str){
    str.erase(0, str.find_first_not_of(" \t\n\r\f\v"));
    str.erase(str.find_last_not_of(" \t\n\r\f\v") + 1);
    return str;
}

char Utilities::getDelimiter(){
    return m_delimiter;
}

void Utilities::setDelimiter(char newDelimiter){
    m_delimiter = newDelimiter;
}

} // end of namespace



