#include <iostream>
#include <vector>
#include "DrawPile.h"
#include "Pile.h"

// for live game play - must not change!               
void DrawPile::display() const {
  std::cout << "[XX]/" << size();
}

void DrawPile::shuffle() {
    std::random_shuffle(this->pile.begin(), this->pile.end());
}

std::string DrawPile::getRand() const{
  if (rand == 0) {
    return "false";
  }
  return "true";
}

Card DrawPile::removeFront() {
  Card c = pile.front();
  pile.erase(pile.begin());
  return c;
}

void DrawPile::addVector(std::vector<Card> c) {
  for (int i = 0; i < int(c.size()); i++) {
    pile.push_back(c[i]);
  }
}
