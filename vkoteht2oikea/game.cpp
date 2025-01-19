#include "game.h"
#include <iostream>

Game::Game(int maxNumber) : maxNumber(maxNumber), playerGuess(0), randomNumber(0), numOfGuesses(0) {

    srand (time(NULL)); //arvonta
    randomNumber = rand() % maxNumber;
    std::cout<<"[DEBUG]Konstruktori: Random luku arvottu: "<< randomNumber<<std::endl;
}

Game::~Game(){
    std::cout << "[DEBUG] Purkaja: Game-olio tuhotaan."<<std::endl;
}

void Game::play(){
    std::cout<<"[DEBUG]play(): Peli alkaa."<<std::endl;
    std::cout<<"Tervetuloa peliin. Arvaa luku väliltä 1-"<<maxNumber<<std::endl;

    while(playerGuess != randomNumber) {    //katotaa minkä kokone se on.
        numOfGuesses++;

        std::cout << "Anna luku?" << std::endl;
        std::cin >> playerGuess;

        if (playerGuess < randomNumber) {
            std::cout << "Liian pieni, kokeile uudestaan." << std::endl;
        }
        if (playerGuess > randomNumber) {
            std::cout << "Liian iso, kokeile uudestaan." << std::endl;
        }

    }

    std::cout << "Onneksi olkoon! Arvasit oikein." << std::endl;
}

void Game::printGameResult(){
    std::cout<<"[DEBUG]printGameResult(): Pelin tulokset tulostetaan."<<std::endl;
    std::cout<<"Arvasit oikein luku oli: "<<randomNumber<<std::endl;
    std::cout<<"Arvasit "<<numOfGuesses<<" Kertaa"<<std::endl;
}
