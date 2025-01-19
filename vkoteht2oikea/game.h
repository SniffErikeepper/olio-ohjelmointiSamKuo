#ifndef GAME_H
#define GAME_H

class Game
{
public:
    Game(int maxNumber); //Konstruktori
    ~Game();    //purkaja

    void play();    //pelin logiikka

    void printGameResult(); //tulostaa lopputuloksen

private:

    //void printGameResult(); //tulostaa lopputuloksen

    int maxNumber;  //maksimi numero
    int playerGuess;    //pelaajan arvaus
    int randomNumber;   //Satunnainen numero
    int numOfGuesses;   //arvausten määrä

};

#endif // GAME_H
