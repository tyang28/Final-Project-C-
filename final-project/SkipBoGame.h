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


class SkipBoGame {
 private:
  std::vector<Player*> players;
  DrawPile* drawPile;
  int turn;
  BuildPile* buildPiles[4];

  void addPlayer(Player*);

  bool gameOver();

  void getHand(int);

  //void createDisplay();

  void addInDrawPile(int);

 public:
  SkipBoGame(){}
  SkipBoGame(std::ifstream &inFile);

  ~SkipBoGame();

  int setPlayers();

  void dealCard(int);

  void promptPlayerMove();
  
  void play();

  void display() const;

  std::string toString() const;
};



#endif
