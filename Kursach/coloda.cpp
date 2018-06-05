#include "coloda.h"
#include <iostream>
#include <stdlib.h>
#include <ctime>

void Init(LIST *el)
{
    el->pHead = NULL;
    el->pPrev = NULL;
    el->countElem = 0;
}
void addToList(LIST *el,std::string data )
{
    Element *temp = new Element;
    if(el->pHead == NULL)
        {
            temp->next = NULL;
            el->pHead = temp;
        }
    else
        {
            el->pPrev->next = temp;
        }
    temp->data = data;
    temp->next = NULL;
    el->pPrev = temp;
    el->countElem++;
}
void printList(LIST *el)
{
    Element *pTemp = el->pHead;

    if (el->pHead == NULL)
        {
            std::cout << "Spisok pust\n";
        }
    else
        {
            std::cout << "Spisok ->: ";
            while(pTemp != NULL)
            {
                std::cout << pTemp->data + ' ';
                pTemp = pTemp->next;
            }
            std::cout << std::endl;
        }
}

void GenCOLODA(LIST *el)
{
    srand(time(NULL));
    std::string Mast[] = {"Chirva","Bubna","Pika","Trefa"};
    std::string Cards_Type[] = {"6","7","8","9","10","B","D","K","T"};
    std::string coloda[36];
    int CounterGeneratorCards = 0;
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 9; ++j)
            {
                coloda[CounterGeneratorCards] = Cards_Type[j]+" "+Mast[i];
                ++CounterGeneratorCards;

            }
    }
    bool testgenerate[36] = {};
    int CounterCardsInList = 0;
    while (CounterCardsInList != 36)
        {
            CounterGeneratorCards = rand()%36;
            if (testgenerate[CounterGeneratorCards] == 0)
                {
                    addToList(el,coloda[CounterGeneratorCards]);
                    testgenerate[CounterGeneratorCards] = 1;
                    ++CounterCardsInList;
                }
        }


}


void delALL(LIST * el)
{
    while (el->pHead!=NULL)
        {
            Element *t = el->pHead;
            el->pHead = el->pHead->next;
            delete t;
        }

}
std::string pop(LIST *el)
{
    if (el->pHead == NULL)  return "";
    Element *t = el->pHead;
    std::string data = t->data;
    el->pHead = el->pHead->next;
    delete t;
    return data;
}
