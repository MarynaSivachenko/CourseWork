#ifndef PLAYERS_H
#define PLAYERS_H
#include <string>
struct PLAYER_Element
{
    std::string name;
    int value;
    int TotalScore;

};

void Init2(PLAYER_Element *el,int players);
void printNames(PLAYER_Element *el,int players);

#endif
