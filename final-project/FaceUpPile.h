#ifndef _FACE_UP_PILE_H
#define _FACE_UP_PILE_H

#include <vector>
#include <iostream>
#include "Pile.h"
#include "Card.h"

class FaceUpPile : public Pile {
 public:
  FaceUpPile() {};
  virtual void display() const;
};


#endif
