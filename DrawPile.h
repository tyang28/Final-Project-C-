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
  std::string getRand() const;
  bool rand;
  void insertAt(const Card& c) {pile.insert(pile.begin(),c);}
  Card removeFront();
  void addVector(std::vector<Card> c);
};


#endif
