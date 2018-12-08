#include <iostream>
#include <vector>
#include "DrawPile.h"
#include "Pile.h"

// for live game play - must not change!               
void DrawPile::display() const {
  std::cout << "[XX]/" << size();
}

//Take entire pile and shuffle
void DrawPile::shuffle() {
    std::random_shuffle(this->pile.begin(), this->pile.end());
}

//Get boolean on shuffle parameter
std::string DrawPile::getRand() const{
  if (rand == 0) {
    return "false";
  }
  return "true";
}

//Remove front of pile and return card
Card DrawPile::removeFront() {
  Card c = pile.front();
  pile.erase(pile.begin());
  return c;
}

//Taking a vector of cards and push contents into pile
void DrawPile::addVector(std::vector<Card> c) {
  for (int i = 0; i < int(c.size()); i++) {
    pile.push_back(c[i]);
  }
}
