#ifndef _BUILD_PILE_H
#define _BUILD_PILE_H

#include <vector>
#include <iostream>
#include "FaceUpPile.h"
#include "Card.h"

class BuildPile : public FaceUpPile {
 public:
  BuildPile() {};

  void clear();
};


#endif
