#include <vector>
#include "Pile.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cstring>

using std::vector;
using std::string;
using std::cout;
using std::endl;

// for saving game state - must not change!
std::string Pile::toString() const {
  std::string result;
  result.append(std::to_string(size()));
  result.append("\n");
  // add all the pile elements to the string, at most 20 per line
  for (int i=0; i < size(); ++i) {
    if (i % 20 == 0 && i != 0)
      result.append("\n");
    else if (i != 0)
      result.append(" ");
    result.append(pile[i].toString());
  }
  result.append("\n");
  return result;
}


void Pile::readIn(std::istream & is) {
  string playername;
  int num;
  
  while(is >> num) {
    Card newCard(num);
    addCard(newCard);
  }
  
  for(vector<Card>::iterator it = pile.begin(); it != pile.end(); ++it) {
    cout << it->getValue() << " " << endl;
  }
  cout << endl;
  /*
  ---------------
  char buffer[5000];
  while(is.read(buffer, sizeof(buffer))) {
      state.append(buffer, sizeof(buffer));
  }
  state.append(buffer, is.gcount());
  int end = state.length();
  for(int i = end; i > 0; i--) {
    reverse(state.begin(), state.end());
  }
  */
  
}

Card Pile::remove() {
   Card c = pile.back();
   pile.pop_back();
   return c;
}

