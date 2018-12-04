#include <iostream>
#include <fstream>
#include "Pile.h"
#include "Hand.h"
#include <string>
#include <vector>
#include "Card.h"
//#include "Player.h"
#include "DrawPile.h"

using std::cin;
using std::string;
using std::cout;
using std::endl;
using std::ifstream;
using std::stoi;

int main(int argc, char* argv[]) {
  switch(argc){
    //check bool and number
    case 3:

    case 5:{
      bool shuffle;
      int numPlayer;
      int stockSize;
      string fileName;

      if (string(argv[1]).compare("true") == 0){
        shuffle = true;
      }else if (string(argv[1]).compare("false") == 0){
        shuffle = false;
      }else{
        cout << "invalid program usage: invalid first argument" << endl; 
        return 1;
      }

      numPlayer = stoi(argv[2]);
      if(numPlayer < 2 || numPlayer > 6){
        cout << "invalid program usage: num players must be 2-6" << endl;
        return 1;
      }else{
        cout << "num players is " << numPlayer << endl;
      }

      stockSize = stoi(argv[3]);
      if(stockSize < 0 || (numPlayer == 6 && stockSize > 20)){
        cout << "invalid program usage: bad stock size" << endl;
        return 1;
      }else {
        cout << "stock size is " << stockSize << endl;
      }
      
      fileName = argv[4];
      ifstream file;
      file.open(fileName,ifstream::in);
      if(!file.is_open()){
        cout << "invalid program usage: can't open deck file" << endl;
        return 1;
      }
      DrawPile draw = DrawPile();
      int number;
      while(file >> number){
        Card c(number);
        draw.addCard(c);
      }
      if (shuffle) {
        draw.shuffle();
      }
      return 0;
    } 
    default:
      cout << "invalid program usage: invalid number of arguments" << endl;
      return 1;
  }
}

// int main() {
//   Player newp("abc");
//   Card card1(1);
//   Card card2(5);
//   Card card3(2);
//   Card card4(4);
//   Card card5(3);
//   Hand hand;
//   hand.addCard(card1);
//   hand.addCard(card2);
//   hand.addCard(card3);
//   hand.addCard(card4);
//   hand.addCard(card5);
//   hand.display();
//   return 0;
// }