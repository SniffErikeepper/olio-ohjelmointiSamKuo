#include <iostream>

#include "asiakas.h"
#include "luottotili.h"
#include "pankkitili.h"

using namespace std;

int main() {
    Asiakas asiakas1("Pasi Viheraho", 2000.0);
    Asiakas asiakas2("Vesa Keskinen", 1000000.0);

    cout << "!!Tilien saldot:!!" << endl;
    asiakas1.showSaldo();
    asiakas2.showSaldo();

    cout << "Pasi tallettaa 300e kayttotilille." << endl;
    asiakas1.talletus(300);

    cout << "Pasi nostaa 150e kayttotililta." << endl;
    asiakas1.nosto(150);

    cout << "Pasi nostaa 200e luottotililta." << endl;
    asiakas1.luotonNosto(200);

    cout << "Vesa nostaa 200 000e luottotililta." << endl;
    asiakas2.luotonNosto(200000);

    cout << "Vesa tallettaa 30 000e kayttotilille." << endl;
    asiakas2.talletus(30000);

    cout << "!!Tilien saldot:!!" << endl;
    asiakas1.showSaldo();
    asiakas2.showSaldo();

    cout << "Pasi maksaa 50e luottotilille." << endl;
    asiakas1.luotonMaksu(50);

    cout << "Vesa maksaa 25 000e luottotilille." << endl;
    asiakas2.luotonMaksu(25000);

    cout << "!!Luotonmaksun jalkeen:!!" << endl;
    asiakas1.showSaldo();
    asiakas2.showSaldo();

    cout << "!!Pasi siirtaa 100e Vesalle.!!" << endl;
    asiakas1.tiliSiirto(100, asiakas2);

    cout << "Tilien saldot tilisiirron jalkeen:" << endl;
    asiakas1.showSaldo();
    asiakas2.showSaldo();

    return 0;
}
