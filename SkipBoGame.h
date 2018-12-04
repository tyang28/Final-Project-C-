#ifndef _SKIPBO_GAME_H
#define _SKIPBO_GAME_H

#include <fstream>
#include <vector>
#include <sstream>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <exception>
#include <thread>
#include <chrono>

#include "Card.h"
#include "Player.h"



class SkipBoGame {
private:
    std::vector<Player> players;
    DrawPile draw;
    int turn;
    BuildPile build[4];
    DrawPile bufferPile;

    void addPlayer(Player*);

    bool gameOver();

    void getHand(int);

    //void createDisplay();

    void addInDrawPile(int);

public:
    SkipBoGame(){}

    SkipBoGame(std::ifstream &inFile);

    ~SkipBoGame();

    bool setPlayers(int numPlayer);

    void dealCard(int stockSize);

    bool validMove(char place1, char place2);

    void promptPlayerMove(int turn);
    
    void play();

    void display() const;

    std::string toString() const;
};



#endif