#include "player_list.h"
#include <iostream>
#include <stdlib.h>
#include <ctime>

void Init2(PLAYER_Element *el,int players)
{

    //std::string names[]={"Jon Smith","Agent 007","Alkash Pavel","Jack Sparrow"};
    for (int i=0;i<players;++i)
    {
        std:: cout << "\nVvedite imya "<< i << " igroka:\n";
        std:: cin >> el[i].name ;
           // el[i].name=names[i];
            el[i].TotalScore=0;
            el[i].value=0;
    }
}

void printNames(PLAYER_Element *el,int players)
{
    for(int i=0;i<players;++i)
    {
        std::cout<<"\n-----------------------------------------------------------\n|";
        std::cout<<el[i].name<<"\t|Value:"<<el[i].value<<"\t|Total Score:"<<el[i].TotalScore;
        std::cout<<"|\n----------------------------------------------------------\n";
    }

}

