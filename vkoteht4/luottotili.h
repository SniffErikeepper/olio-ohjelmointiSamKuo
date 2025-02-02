#ifndef LUOTTOTILI_H
#define LUOTTOTILI_H

#include <string>
#include "pankkitili.h"

using namespace std;

class Luottotili : public Pankkitili
{
public:
    Luottotili(string owner, double creditLimit)
        : Pankkitili(owner), luottoRaja(creditLimit) {}

    bool deposit(double amount) override;
    bool withdraw(double amount) override;

protected:
    double luottoRaja;
};

#endif // LUOTTOTILI_H
