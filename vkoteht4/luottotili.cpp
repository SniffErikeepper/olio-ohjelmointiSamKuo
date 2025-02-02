#include "luottotili.h"
#include <iostream>

using namespace std;

bool Luottotili::deposit(double amount)
{
    if (amount <= 0) {
        cout << "Luottotilin talletus epaonnistui: Summa on oltava positiivinen." << endl;
        return false;
    }
    if (saldo + amount > 0) {
        cout << "Luottotilin talletus epaonnistui: Liian suuri summa." << endl;
        return false;
    }
    saldo += amount;
    cout << "Luottotilille talletettu: " << amount << "E. Uusi saldo: " << saldo << "E." << endl;
    return true;
}

bool Luottotili::withdraw(double amount)
{
    if (amount <= 0 || saldo - amount < -luottoRaja) {
        cout << "Luottotilin nosto epaonnistui: Liian suuri summa." << endl;
        return false;
    }
    saldo -= amount;
    cout << "Luottotililta nostettu: " << amount << "E. Uusi saldo: " << saldo << "E." << endl;
    return true;
}
