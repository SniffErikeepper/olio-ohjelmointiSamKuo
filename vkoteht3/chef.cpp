#include "chef.h"
#include <iostream>

using namespace std;

Chef::Chef(const string& name) : chefName(name)
{
    cout << "[DEBUG] Chef " << chefName << " on luotu." << endl;     //Luodaan kokin nimi
}

Chef::~Chef()
{
    cout << "[DEBUG] Chef " << chefName << " on tuhottu." << endl;   //Tuhotaan kokin nimi
}

string Chef::getName() const
{
    return chefName;
}

int Chef::makeSalad(int ainekset)
{
    int annokset = ainekset / 5;
    cout << "[DEBUG] Chef " << chefName << " teki " << annokset << " salaatti annosta kayttaen " << ainekset << " ainesta." << endl;
    return annokset;
}

int Chef::makeSoup(int ainekset)
{
    int annokset = ainekset / 3;
    cout << "[DEBUG] Chef " << chefName << " teki " << annokset << " keitto annosta kayttaen " << ainekset << " ainesta." << endl;
    return annokset;
}
