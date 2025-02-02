#ifndef PANKKITILI_H
#define PANKKITILI_H

#include <string>
using namespace std;

class Pankkitili
{
public:
    Pankkitili(string owner) : omistaja(owner), saldo(0.0) {}
    double getBalance();
    virtual bool deposit(double amount);
    virtual bool withdraw(double amount);
protected:
    string omistaja;
    double saldo = 0;
};

#endif // PANKKITILI_H
