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
#include "BuildPile.h"
#include "DrawPile.h"
#include "PlayPile.h"


class SkipBoGame {
private:
    std::vector<Player> peep;

    int nump;

    int curp;

    BuildPile build[4];
    
    void addPlayer(Player*);

    bool gameOver();

    void getHand(int);

    //void createDisplay();

    void addInDrawPile(int);

public:
    DrawPile draw;

    DrawPile bufferPile;

    SkipBoGame(int numPlayer);

    void clearBuild();

    bool drawEmpty();

    void fillDraw();

    //SkipBoGame(std::ifstream &inFile);

    ~SkipBoGame();

    void setPlayers(int numPlayer);

    void dealCard(int stockSize);

    bool validMove(char place1, char place2);

    int promptPlayerMove(int turn);
    
    void play();

    void display() const;

    std::string toString() const;

    void fillHand(int curp);

    void clearBuild(int index);
};



#endif