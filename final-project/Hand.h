#ifndef _HAND_H
#define _HAND_H

#include <vector>
#include <iostream>
#include "Pile.h"
#include "Card.h"

class Hand : public Pile {
 public:
  Hand() {};

  ~Hand() {};
  
  virtual void display() const;
};


#endif
