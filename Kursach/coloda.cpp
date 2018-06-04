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
        el->pPrev->next = temp;
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
    std::string Mast[]={"Chirva","Bubna","Pika","Trefa"};
    std::string Cards_Type[]={"6","7","8","9","10","B","D","K","T"};
    std::string coloda[36];
    int k=0;
    for(int i=0;i<4;++i)
    {
        for(int j=0;j<9;++j)
        {
            coloda[k]=Cards_Type[j]+" "+Mast[i];
            ++k;

        }
    }
    bool testgenerate[36]={};
    int p=0;
    while (p!=36)
    {
        k=rand()%36;
        if (testgenerate[k]==0)
        {
            addToList(el,coloda[k]);
            testgenerate[k]=1;
            ++p;
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
    if (el->pHead==NULL)
        return "";
    Element *t=el->pHead;
    std::string data=t->data;
    el->pHead=el->pHead->next;
    delete t;
    return data;
}
