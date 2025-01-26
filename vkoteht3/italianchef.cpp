#include "italianchef.h"
#include <algorithm>

ItalianChef::ItalianChef(const string &name) : Chef(name), password("pizza")
{
    cout << "[DEBUG] ItalianChef " << chefName << " on luotu." << endl;
}

ItalianChef::~ItalianChef()
{
    cout << "[DEBUG] ItalianChef " << chefName << " on tuhottu." << endl;
}

int ItalianChef::makePizza(int jauho, int vesi)
{
    int pizzas = min(jauho / 5, vesi / 5);
    cout << "[DEBUG] ItalianChef " << chefName << " teki " << pizzas << " pizzaa kayttaen " << jauho << " jauhoa ja " << vesi << " vetta." << endl;
    return pizzas;
}

bool ItalianChef::askSecret(const string &inputPassword, int jauho, int vesi)
{
    if (inputPassword == password) {
        int pizzas = makePizza(jauho, vesi);
        cout << "[DEBUG] Oikea salasana! " << chefName << " teki " << pizzas << " pizzaa." << endl;
        return true;
    } else {
        cout << "[DEBUG] Vaarin paasy kielletty." << endl;
        return false;
    }
}
