#ifndef ITALIANCHEF_H
#define ITALIANCHEF_H

#include <iostream>
#include "chef.h"

using namespace std;

class ItalianChef : public Chef
{
private:
    string password;

    int makePizza(int jauho, int vesi); // Yksityinen jäsenfunktio

public:
    ItalianChef(const string& name);
    virtual ~ItalianChef() override;

    bool askSecret(const string& inputPassword, int jauho, int vesi);
};

#endif // ITALIANCHEF_H
