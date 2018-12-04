#include <iostream>
#include <sstream>
#include "SkipBoGame.h"

using std::cin;
using std::cout;
using std::endl;
using std::string; 
using std::vector; 

SkipBoGame(){

  this->drawPile = DrawPile();
  for (int i = 0; i < 4; i ++){
    this->build[i] = buildPiles();
  }
  turn = 0;
}

SkipBoGame(std::ifstream &inFile){
  
}

~SkipBoGame(){

}

bool SkipBoGame::setPlayers(int numPlayer){
  if(numPlayer < 2 || numPlayer > 6){
    cout << "invalid program usage: num players must be 2-6" << endl;
    return false; 
  }else{
    for (int i = 0; i < numPlayer; i++){
      string playerName = "Player " + to_string(i);
      Player tempPlayer = Player(playerName);
      this->players.push_back(tempPlayer);
    }
    return true;
  }
}

//initialize the game 
void SkipBoGame::dealCard(int stockSize){
  int numPlayer = players.size();
  for (int i = 0; i < numPlayer; i ++){
    //add cards to the players' hands
    for (int j = 0; j < 5; j ++){
      player[i].hand.addCard(drawPile.remove());
    }
    //add cards to the stock
    for (int k = 0; k < stockSize; k++){
      player[k].stock.addCard(drawPile.remove());
    }
  }
}



void SkipBoGame::promptPlayerMove(int turn){
  char mode;
  char place1;
  char place2;
  cout << "(m)ove [start] [end] or (d)raw ?";
  cin >> mode;
  cin >> place1;
  cin >> place2; 

  // not m or d
  if (mode == 'd'){
    if(players[i].hand.size() == 5){
      cout << "illegal command, try again" << endl;
      return;
    }else{
      players[i].hand.addCard(drawPile.remove());
      return;
    }
  }else if (mode == 'm'){

  }else{
    cout << "illegal command, try again" << endl;
    return;
  }
}

bool validMove(char place1, char place2){
  //initialize all the piles 
  Player current = players [turn % players.size()];
  Hand currentHand = current.hand();
  PlayPile currentStock = current.stock();
  PlayPile currentDiscard [4];
  BuildPile currentBuild [4];

  //initialize discard and build pile 
  for (int i = 0; i < 4; i ++){
    currentDiscard[i] = current.discard[i];
    currentBuild[i] = this->buildPiles[i];
  }

  
  // if(currentStock.size() == 0){
  //   cout << "This player win the game" << endl;
  // }


  //Move card from Stock Pile 
  if(place1 == '0'){
    //destination is Build Pile
    if (place2 >= 'a' && place2 <= 'd'){
      int index = place2 - 'a';
      //if the top card of a stock pile is Skipbo
      if(currentStock.top()->getValue() == 0){
        return true;
      }//if the top of stock file is equal to 1 + the top of the build pile 
      else if(currentStock.top()->getValue() == currentBuild[index].size() + 1 ){
        return true;
      }//everything else is false
      else{
        return false;
      }
    }else{
      cout << "illegal command, try again" << endl;
      return false;
    }
  }
  //Move card from Discard Pile
  else if (place1 >= '1' && place1 <= '4'){
    int index1 = place1 - '1';
    if(currentDiscard[index1].size() == 0){
      cout << "Current Discard Pile is Empty" << endl;
      return false;
    }
    if(place2 >= 'a' && place2 <= 'd'){
      int index2 = place2 - 'a';
      if(currentDiscard[index1].top()->getValue() == 0){
        return true;
      }else if (currentDiscard[index1].top()->getValue() == currentBuild[index2].size() + 1){
        return true;
      }else{
        return false;
      }
      
    }else{
      cout << "illegal command, try again" << endl;
      return false;
    }
  }
  //Move card from Hand
  else if (place1 >= '5' && place1 <= '9'){
    int index1 = place1 -'5';
    //check if there is no card in the cooresponding position
    if(index1 > (currentHand.size()-1)){
      cout << "No card in this place" << endl;
      return false;
    }else{
      //move to Build Pile
      if(place2 >= 'a' && place2 <= 'd'){
        //if the card is SkipBo
        int index2 = place2 - 'a';
        if(currentHand.getCard(index1).getValue() == 0){
          return true;
        }else if (currentHand.getCard(index1).getValue() == currentBuild[index2].size() + 1 ){
          return true;
        }else{
          return false;
        }
      }else if (place2 >= '1' && place2 <= '4'){//move to discard Pile
        int index3 = place2 - '1';
        if(currentHand.getCard(index1).getValue() == 0){
          return true;
        }else if(currentHand.getCard(index1).getValue() == currentDiscard[index3].size() + 1){
          return true;
        }else{
          return false;
        }
      }
    }
  }else{
    return false;
  }

}


void SkipBoGame::play(){

}



/* for live game play - must not change format!

drawPile  build_a  build_b  build_c  build_d
playerName  stock_0  
discards: discard_1 discard_2 discard_3 discard_4
hand: card_5 card_6 card_7 card_8 card_9
 */
void SkipBoGame::display() const {
  std::cout << "Draw: ";
  draw.display();
  std::cout << "  Build Piles: ";
  for (int j = 0; j < 4; j++) {
    build[j].display();
    std::cout << " ";
  }
  std::cout << std::endl;
  peep[curp].display();
}

/* for saving state - must not change format!

shuffle numplayers currplayer
PlayerCurp [display]
PlayerCurp+1 [display]
[etc for all players]
Draw [display]
Build_a [display]
Build_b [display]
Build_c [display]
Build_d [display]
*/
std::string SkipBoGame::toString() const {
  std::stringstream result;
  int idx;
  result << draw.getRand() << " " << nump << " " << curp << "\n";
  for (int i = 0; i < nump; ++i) {
    idx = (curp+i) % nump;
    result << peep[idx].toString();
  }
  result << "Draw " << draw.toString(); 
  for (int j = 0; j < 4; j++) {
    result << "Build_" << char('a'+j) << " ";
    result << build[j].toString();  
  }
  return result.str();
}
