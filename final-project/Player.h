#ifndef _PLAYER_H
#define _PLAYER_H

#include <iostream>
#include "Hand.h"
#include "PlayPile.h"
#include "StockPile.h"

class Player: {
   public:
    Hand hand;
    PlayPile discard[4];
    StockPile stock;
    std::string name;
    Player(std::string n){name = n;};
    void display() const;
    std::string toString() const;
  
};

#endif
