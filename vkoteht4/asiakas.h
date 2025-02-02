#ifndef ASIAKAS_H
#define ASIAKAS_H

#include "pankkitili.h"
#include "luottotili.h"
#include <string>
#include <iostream>

using namespace std;

class Asiakas
{
public:
    Asiakas(string name, double creditLimit)
        : nimi(name),kayttotili(name), luottotili(name, creditLimit) {}
    string getNimi();
    void showSaldo();
    bool talletus(double amount);
    bool nosto(double amount);
    bool luotonMaksu(double amount);
    bool luotonNosto(double amount);
    bool tiliSiirto(double summa, Asiakas &vastaanottaja);
private:
    string nimi;
    Pankkitili kayttotili;
    Luottotili luottotili;
};

#endif // ASIAKAS_H
