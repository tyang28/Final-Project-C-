#include <vector>
#include "Pile.h"

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

//Function to remove cards from a pile from the back
Card  Pile::remove() {
  Card c = pile.back();
  pile.pop_back();
  return c;
}

//Function to return card at top of pile
Card * Pile::top() {
  Card *c = new Card();
  c = &pile.back();
  return c;
}

//Function that is the opposite of toString to read in a save state for Pile
void Pile::readIn(std::istream & is) {
  int num;
  std::string temp;
  is >> temp;
  int size;
  is >> size;
  if(size > 0) {
    for(int i = 0; i < size; i++) {
      is >> num;
      Card newCard(num);
      addCard(newCard);
    }
  }
}
