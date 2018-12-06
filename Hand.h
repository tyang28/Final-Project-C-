#ifndef _HAND_H
#define _HAND_H

#include <vector>
#include <iostream>
#include "Card.h"
#include "Pile.h"

class Hand: public Pile {
  public:
    Hand() {};

    ~Hand() {};

    virtual void display() const;

    Card getCard(int i) const;

    Card removeHand(int i);
};


#endif