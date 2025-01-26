#include "Chef.h"
#include "ItalianChef.h"
#include <iostream>

using namespace std;

int main() {
    // Luodaan Chef ja ItalianChef
    Chef* chef = new Chef("Gordon");
    ItalianChef* italianChef = new ItalianChef("Mario");

    // Käytetään metodeja
    chef->makeSalad(10);
    chef->makeSoup(9);

    italianChef->askSecret("pizza", 15, 20); // Oikea salasana
    //italianChef->askSecret("wrongpassword", 15, 20); // Väärä salasana

    // Poistetaan oliot
    delete chef;
    delete italianChef;

    return 0;
}
