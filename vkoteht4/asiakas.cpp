#include "asiakas.h"
#include <string>

string Asiakas::getNimi()
{
    return nimi;
}

void Asiakas::showSaldo()
{
    cout<<"--Asiakas: " << getNimi() << "--"<< endl;
    cout << "Pankkitilin saldo: " << kayttotili.getBalance() << "E" << endl;
    cout << "Luottotilin saldo: " << luottotili.getBalance() << "E" << endl;
    cout << endl;
}

bool Asiakas::talletus(double amount) {
    return kayttotili.deposit(amount);
}

bool Asiakas::nosto(double amount) {
    return kayttotili.withdraw(amount);
}

bool Asiakas::luotonMaksu(double amount) {
    if (kayttotili.withdraw(amount)) {
        return luottotili.deposit(amount);
    }
    return false;
}

bool Asiakas::luotonNosto(double amount) {
    return luottotili.withdraw(amount);
}

bool Asiakas::tiliSiirto(double amount, Asiakas &vastaanottaja) {
    if (amount <= 0) {
        cout << "Tilisiirto epaonnistui: Summan pitaa olla poitiivinen." << endl;
        return false;
    }

    if (kayttotili.withdraw(amount)) {
        if (vastaanottaja.talletus(amount)) {
            cout << "Tilisiirto onnistui: " << amount << " siirrettiin " << vastaanottaja.getNimi() << ":lle" << endl;
            return true;
        } else {
            kayttotili.deposit(amount);
            std::cout << "Tilisiirto epaonnistui: Rahojen palautus tehty." << endl;
        }
    } else {
        cout << "Tilisiirto epäonnistui: Ei tarpeeksi varoja tilillä." << endl;
    }

    return false;
}
