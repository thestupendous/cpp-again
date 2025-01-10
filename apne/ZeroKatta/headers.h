#ifndef DEFINITIONS_H
#define DEFINITIONS_H
#include<iostream>
using std::cin;
using std::cout;

enum options
{
    khali,
    zero,
    katta,
};
enum players
{
    pehla,
    dusra,
};

class ZeroKatta
{
public:
    options zeroKatta;
    ZeroKatta() : zeroKatta(khali) {}
};  //sari definitions yahi hn

class Won
{
public:
    players vijeta;
    bool jeeta;
    Won() : jeeta(false) {}
};  //sari definitions yahi hn

class Coords
{
public:
    int x, y;
    Coords() : x(-1), y(-1) {}
    Coords(int a, int b) : x(a), y(b) {}
    void setNewCoords(int);
};
class Box
{
    ZeroKatta khane[3][3];
    bool checkPossible(const Coords &);
    void checkAndUpdateWon(players , Won &);
public:
    Box();
    bool isBoardFull();
    void printBoard();
    void placeMove(const int &, const Coords &, Won &);
};
class Score
{
    int score[2];
public:
    Score();
    void update(players);
    void print();
};

bool wantToContinue();
void flipTurn(int&);
void readInputInt(int&);
void printYeWalaGameStartingText();
void printYeWalaGameEndingText(players);
void printDrawGameText();

#endif