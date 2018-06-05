#ifndef COLODA_H
#define COLODA_H
#include <string>
struct Element
{
    std::string data;
    Element *next;
};
struct LIST
{
    Element *pHead;
    Element *pPrev;
    int countElem;
};
void delALL(LIST *el);
void Init(LIST *el);
void addToList(LIST *el,std::string data );
void printList(LIST *el);
void GenCOLODA(LIST *el);
std::string pop(LIST *el);
#endif
