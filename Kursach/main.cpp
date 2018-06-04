#include <iostream>
#include <string>
#include <stdio.h>
#include "coloda.h"
#include "player_list.h"

using namespace std;

int convert(string data);

int main()
{

    LIST Temp;
    Init(&Temp);

    int Total_Players;
    GenCOLODA(&Temp);
    string card_name,com;
    cout<<"Enter num of players[2-4]::\n";
    cin>>Total_Players;
    if (Total_Players<2 || Total_Players>4)
        Total_Players=4;
    PLAYER_Element * players = new PLAYER_Element[Total_Players];
    Init2(players,Total_Players);
    printNames(players,Total_Players);
    int games = 1;
    cout <<"\n\nGame "<<games<<":\n";

    for (;games<=3; ++games)
    {
            for (int i=0;i<Total_Players;++i)
            {
                players[i].value=convert(pop(&Temp));
            }

        for (int i=0;i<Total_Players;++i)
        {
          cout<<"Hodit::"<<players[i].name<<endl<<"Enter Y dla vziatiya carty\n";
          cout<<"Tvoy ochky::"<<players[i].value<<endl;

          do
          {
              cin>>com;
              if(com.find("y")!=0)
                        break;
              card_name=pop(&Temp);
              cout<<"Ti dostal "<<card_name<<endl;
              players[i].value=players[i].value+convert(card_name);
              cout<<"Tvoy ochky::"<<players[i].value<<endl<<"Enter Y dla vziatiya carty\n";
          }while(players[i].value<21) ;
        }
        int CounterWinners = 0;
        int MaxValue = 21;

        do {
             for (int i=0;i<Total_Players;++i)
             {
                 if (players[i].value == MaxValue)
                 {
                    players[i].TotalScore ++;
                    CounterWinners++;
                 }
             }
             --MaxValue;
        }while (CounterWinners == 0 && MaxValue !=0);

        printNames(players,Total_Players);

        for (int i=0;i<Total_Players;++i)   {  players[i].value = 0;}
    }
}

int convert(string data)
{
    if (data.find("T ")!=-1)
        return 1;
    if (data.find("K ")!=-1)
        return 4;
    if (data.find("D ")!=-1)
        return 3;
    if (data.find("B ")!=-1)
        return 2;
    if (data.find("10")!=-1)
        return 10;
    if (data.find("9")!=-1)
        return 9;
    if (data.find("8")!=-1)
        return 8;
    if (data.find("7")!=-1)
        return 7;
    if (data.find("6")!=-1)
        return 6;
}
