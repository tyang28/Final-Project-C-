#include <iostream>
#include "DrawPile.h"
#include "Pile.h"

// for live game play - must not change!               
void DrawPile::display() const {
  std::cout << "[XX]/" << size();
}

void DrawPile::shuffle() {
    std::random_shuffle(this->pile.begin(), this->pile.end());
}