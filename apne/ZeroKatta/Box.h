#ifndef BOX_H
#define BOX_H

#include "headers.h"

class Box
{
    ZeroKatta khane[3][3];
    bool checkPossible(const Coords &);
    void checkAndUpdateWon(players , Won &);
public:
    Box();
    bool isBoardFull();
    void printBoard();
    void placeMove(const int &,Coords &, Won &);
};

#endif