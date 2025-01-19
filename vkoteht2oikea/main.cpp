#include "game.h"
#include <iostream>

int main()
{
    std::cout << "[DEBUG] main(): Pääohjelma alkaa."<<std::endl;

    // Luodaan Game-olio, jonka suurin etsittävä luku on 50
    Game game(50);
    std::cout << "[DEBUG] main(): Game-olio luotu."<<std::endl;

    // Käynnistetään peli
    game.play();

    // Tulostetaan pelin tulokset
    game.printGameResult();

    std::cout << "[DEBUG] main(): Pääohjelma päättyy."<<std::endl;
    return 0;
}
