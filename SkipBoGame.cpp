#include <iostream>
#include <sstream>
//#include <ifstream>
#include <fstream>
#include "SkipBoGame.h"

using std::cin;
using std::cout;
using std::endl;
using std::string; 
using std::vector; 


SkipBoGame::SkipBoGame(int numPlayer){
  this->draw = DrawPile();
  this->bufferPile = DrawPile();
  for (int i = 0; i < 4; i++){
    build[i] = BuildPile();
  }
  this->curp = 0;
  this->nump = numPlayer;
}

// SkipBoGame(std::ifstream &inFile){
  
// }

SkipBoGame::~SkipBoGame(){

}

void SkipBoGame::setPlayers(int numPlayer){
    for (int i = 0; i < numPlayer; i++){
      string playerName = "Player" + std::to_string(i);
      Player tempPlayer = Player(playerName);
      this->peep.push_back(tempPlayer);
    }
    return;
}

//initialize the game with palyers' stock 
void SkipBoGame::dealCard(int stockSize){
  for (int i = 0; i < stockSize; i ++){
    // //add cards to the players' hands
    // for (int j = 0; j < 5; j ++){
    //   peep[i].hand.addCard(draw.remove());
    // }
    //add cards to the stock
    for (int k = 0; k < nump; k++){
      peep[k].stock.addCard(draw.remove());
    }
  }
}



void SkipBoGame::fillHand(int curp){
  while(peep[curp%nump].hand.size() < 5){
    peep[curp%nump].hand.addCard(draw.remove());
    fillDraw();
  }
}

void SkipBoGame::clearBuild(int index){
  if(build[index].size() == 12){
    for (int i =0; i < 12; i ++){
      bufferPile.addCard(build[index].remove());
    }
  }
}

bool SkipBoGame::drawEmpty(){
  if(draw.size() == 0){
    return true;
  }else{
    return false;
  }
}

void SkipBoGame::fillDraw(){
  if(drawEmpty()){
    while(bufferPile.size() != 0){
      draw.addCard(bufferPile.remove());
    }
    draw.shuffle();
  }
}

int SkipBoGame::promptPlayerMove(int curp){
  string mode;
  string place1;
  string place2;
  char way;
  char from;
  char to;
  cout << "(m)ove [start] [end] or (d)raw ?";
  cin >> mode;

  
  if (mode.size() == 1){
    way = mode.at(0);
  }else{
    cout << "illegal command, try again" << endl;
    return 1;
  }
    // not m or d
  if (way == 'd'){//draw a new card 
    cout << "I am here" << endl;
    cout << "curp: " << this->curp << endl;
    cout << "index: " << this->curp % this->nump << endl;
    cout << "size is" << peep[curp % nump].hand.size() << endl;
    if(peep[curp % nump].hand.size() != 0){
      cout << "illegal command, try again" << endl;
      return 1;
    }else{
      while(peep[curp % nump].hand.size() != 5){
        peep[curp % nump].hand.addCard(draw.remove());
      }
      return 0;
  }





  }else if (way == 'm'){//move from hand 
    cin >> place1;
    cin >> place2;  
    if(place1.size() == 1){
      from = place1.at(0);
    }else{
      cout << "illegal command, try again" << endl;
      return 1;
    }

    if(place2.size() == 1){
      to = place2.at(0);
    }else{
      cout << "illegal command, try again" << endl;
      return 1;
    }
  
    if(validMove(from,to)){
      if(from == '0'){
        //add from stock to build
        if(to >= 'a' && to <= 'd'){
          int index = to -'a';
          build[index].addCard(peep[curp % peep.size()].stock.remove());
          clearBuild(index);
          return 0;
        }else{
          return 1;
        }
      }else if(from >= '1' && from <= '4'){//add from discard to build
        if(to >= 'a' && to <= 'd'){
          int index1 = from - '1';
          int index2 = to - 'a';
          build[index2].addCard(peep[curp % peep.size()].discard[index1].remove());
          clearBuild(index2);
          return 0;
        }else{
          return 1;
        }
      }else if (from >= '5' && from <= '9'){
        if(to >= 'a' && to <= 'd'){//add from hand to build
          int index1 = from -'5';
          int index2 = to - 'a';
          build[index2].addCard(peep[curp % peep.size()].hand.removeHand(index1));
          clearBuild(index2);
          return 0;
        }else if (to >= '1' && to <= '4'){//add from hand to discard
          int index1 = from - '5';
          int index2 = to - '1';
          peep[curp % peep.size()].discard[index2].addCard(peep[curp % peep.size()].hand.removeHand(index1));
          return 2;
        }else{
          return 1;
        }
      }else{
        return 1;
      }
    }else{
      cout << "illegal command, try again" << endl;
      return 1;
    }
  }else{
    cout << "illegal command, try again" << endl;
    return 1;
  }
  return 1;
}

bool SkipBoGame::validMove(char place1, char place2){
  //initialize all the piles 
  Player current = peep [curp % peep.size()];
  Hand currentHand = current.hand;
  PlayPile currentStock = current.stock;
  PlayPile currentDiscard [4];
  BuildPile currentBuild [4];

  //initialize discard and build pile 
  for (int i = 0; i < 4; i ++){
    currentDiscard[i] = current.discard[i];
    currentBuild[i] = this->build[i];
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
        return true;
        // int index3 = place2 - '1';
        // if(currentHand.getCard(index1).getValue() == 0){
        //   return true;
        // }else if(currentHand.getCard(index1).getValue() == currentDiscard[index3].size() + 1){
        //   return true;
        // }else{
        //   return false;
        // }
      }
    }
  }
  return false;
}

bool SkipBoGame::gameOver(){
  if(peep[curp % peep.size()].stock.size() == 0){
    return true;
  }else{
    return false;
  }
}

void SkipBoGame::play(){

  //wile i can scan in 3 strings                                                                                     
                                                                                                                      
  Player current = peep [curp % nump];
  string input; 
  char mode;
  cout << endl;
  cout << " >> " << current.name << " turn next" << endl; 
  cout << "(p)lay, (s)ave, or (q)uit ?";
  cin >> input;

  if(input.size() == 1){
    mode = input.at(0);
  }else{
    cout << "illegal command, try again" << endl;
  }

  while (!gameOver()){
    // if(mode == 's'){

    // }else 
    if (mode == 'q'){
      cout << "thanks for playing" << endl;
      return;
    }else if (mode == 'p'){
      fillHand(curp);
      display();
      while (promptPlayerMove(curp) != 2){
        cout << endl;
        //promptPlayerMove(curp);
        //cout << peep[curp % peep.size()].stock.size() << endl;
        display();
        //cout << gameOver() << endl;
        if(gameOver()){
          cout << endl;
          cout << "GAME OVER - " << current.name << " wins!";
          return;
        }
      }
      display();
      curp ++;
      //display();
    }else{
      cout << "illegal command, try again" << endl;
    }
    //display();
    current = peep[curp % nump];
    cout << endl;
    cout << " >> " << current.name << " turn next" << endl;
    cout << "(p)lay, (s)ave, or (q)uit ?";
    cin >> input;
    if(input.size() == 1){
        mode = input.at(0);
    }
  }


  // while (!gameOver() && mode != 's' && mode != 'q') {

  //   if(mode != 'q' && mode != 's') {
  //     while(!gameOver()) {
  //       display();
  //       if (promptPlayerMove(curp) == 2){
  //         curp ++;
  //       }else{
  //         promptPlayerMove(curp);
  //       }
  //     }
  //   }
  // }
    // else if(input == 's'){
    //   string filename;
    //   cout << "save filename:";
    //   cin >> filename;
    //   saveGame(filename);
    //   return;
    // }
  

  // if(mode == 's'){
  //   return;
  // }
  // if(gameOver()) {
  //   cout << "GAME OVER - " << current.name << " wins!" << endl;
  //   return;
  // }


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
  peep[curp % nump].display();
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

