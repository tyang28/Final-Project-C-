#ifdef _GAMEOPERATE_H
#define _GAMEOPERATE_H

#include <iostream>
#include <cstdlib>
#include "SkikBoGame.h"

class GameOperate{
    public:
        GameOperate(){}
        GameOperate(int numPlayer, int stockSize) : numPlayer(numPlayer), stockSize(stockSize);
        void newgame();
        bool loadgame();
    private:
        SkipBoGame *SBgame;
        int numPlayer;
        int stockSize;
};


#endif