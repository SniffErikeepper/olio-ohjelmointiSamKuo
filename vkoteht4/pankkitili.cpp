#include "pankkitili.h"
#include <iostream>



double Pankkitili::getBalance()
{
    return saldo;
}

bool Pankkitili::deposit(double amount)
{
    if (amount <= 0) {
        cout<< "Talletus epaonnistui: Se ei voi olla negatiivinen." << endl;
        cout << endl;
        return false;
    }
    saldo += amount;
    cout<< "Talletus onnistui. Talletit: " << amount << "E. Uusi saldo: " << saldo << "E."<< endl;
    cout << endl;
    return true;
}

bool Pankkitili::withdraw(double amount)
{
    if (saldo >= amount) {
        saldo -= amount;
        cout << "Nostit: " << amount << "E. Uusi saldo: " << saldo << "E." << endl;
        return true;
    }
    cout << "Nosto epäonnistui: Ei tarpeeksi katetta." << endl;
    return false;
}
