#ifndef _DRAW_PILE_H
#define _DRAW_PILE_H

#include <vector>
#include <iostream>
#include "Pile.h"
#include "Card.h"
#include <algorithm>

class DrawPile : public Pile {
 public:
  DrawPile() {};
  virtual void display() const;
  void shuffle();
  bool getRand() const;
  bool rand;
};


#endif