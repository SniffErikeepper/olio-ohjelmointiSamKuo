#ifndef CHEF_H
#define CHEF_H

#include <iostream>
#include <string>

class Chef {
protected:
    std::string chefName; // Suojattu kokin nimi

public:
    Chef(const std::string& name); // Konstruktorin julistus
    virtual ~Chef(); // Destruktori

    std::string getName() const;
    int makeSalad(int ainekset);
    int makeSoup(int ainekset);
};

#endif // CHEF_H
