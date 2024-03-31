
// Name: Vincent Paul Escueta
// Seneca Student ID: 159627223
// Seneca email: vpescueta@mysenecca.ca
// Date of completion: 29 March 2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
#include "LineManager.h"
#include "Utilities.h"

namespace seneca{

// for completion 20240330
LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations){
    Utilities ut;
    Utilities::setDelimiter('|');
    bool keepLooking{};
    if (!file[0]) {
        throw std::string("ERROR: No filename provided.");
    }
    std::ifstream fin(file);
    if (!fin)
        throw std::string("Unable to open [") + file + "] file.";
    
    std::string record;
    
    while (!fin.eof())
    {
        std::getline(fin, record);
//        stations.emplace_back(ut.)
//        theCollection.push_back(new T(record));
    }

    fin.close();
    
//    ut.extractToken(<#const std::string &str#>, <#size_t &next_pos#>, <#bool &more#>)
    

}

// for completion 20240330
void LineManager::reorderStations(){
    
}

// for completion 20240330
bool LineManager::run(std::ostream& os){
    size_t counter{};
    bool result{};

    return result;
}

// for completion 20240330
void LineManager::display(std::ostream& os) const{
    std::for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* ws){
        ws->display(os);
    });
}


} // end of namespace
