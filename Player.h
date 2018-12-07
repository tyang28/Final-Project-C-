#ifndef _PLAYER_H
#define _PLAYER_H

#include <iostream>
#include "Hand.h"
#include "PlayPile.h"

class Player {

  public:
    Hand hand;
    PlayPile discard[4];
    PlayPile stock;
    std::string name;
    Player(std::string n){name = n;};
    void display() const;
    std::string toString() const;
    void readIn(std::istream & is);
};

#endif
