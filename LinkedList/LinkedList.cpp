#include "../ChainNode/ChainNode.h"
#include "LinkedList.h"
#include <iostream>
using namespace std;
LinkedList::LinkedList(int maxSize)
{
    // create dummy node
    /*ChainNode *p = NULL;
    p = new ChainNode ; //ChainNode *p = new ChainNode ;
    set fisrt node pointing to p (dummy)
    firstNode = p;
    fisrtMode point to new dummy node*/
    firstNode = new ChainNode;
    this->maxSize = maxSize;

    // set current size to 0
    curSize = 0;
}

LinkedList::~LinkedList()
{
    // destroy every thing (memory)
    // set p point to dummy
    ChainNode *p = firstNode;
    while (p != NULL)
    {
        // set n point to next of p
        ChainNode *n = p->next;
        // delete node p is pointing to
        delete p;
        // set p point to node as n pointing to
        p = n;
    }
    /* no need
    firstNode = NULL;
    curSize = o;*/
}

int LinkedList::get_maxSize()
{
    return maxSize;
}

int LinkedList::size()
{

    return curSize;
}

int LinkedList::indexOf(int e)
{
    ChainNode *current = firstNode->next;
    int index = 0;

    while (current != nullptr)
    {
        if (current->element == e)
        {
            return index;
        }
        current = current->next;
        index++;
    }

    return -1;
}

int LinkedList::get(int i)
{
    if (i < 0 || i >= curSize)
    {
        cerr << "Error: Index out of bounds" << endl;
        return -1;
    }

    ChainNode *current = firstNode->next;
    int index = 0;

    while (index < i)
    {
        current = current->next;
        index++;
    }

    return current->element;
}

void LinkedList::set(int i, int e)
{
    if (i < 0 || i >= curSize)
    {
        cerr << "Error: Index out of bounds" << endl;
        return;
    }

    ChainNode *current = firstNode->next;
    int index = 0;

    while (index < i)
    {
        current = current->next;
        index++;
    }

    current->element = e;
}

void LinkedList::add(int i, int e)
{
    // check memory
    if (isFull())
    {
        cerr << "Error : Memory is full " << endl;
        return;
    }
    if (curSize == maxSize)
    {
        cerr << "Error :List is full " << endl;
        return;
    }
    // q poin to new ChainNode
    /*ChainNode *q = new ChainNode(e);//[e,NULL]
    if ( q == NULL)//not enough memory fll
    {
        cerr << "Error : memory is full"<<endl;
        return ;
    }*/
    // check index
    if (i < 0)
    {
        cerr << "Warning : lower bound index" << endl;
        cout << "Message : " << i << "Change to 0 " << endl;
        i = 0;
    }
    else if (i > curSize)
    {
        cerr << "Warning : lower bound index" << endl;
        cout << "Message : " << i << "Change to  " << curSize << endl;
        i = curSize;
    }
    // p pointo dummy
    ChainNode *p = firstNode;
    // move p forward i times
    for (int j = 0; j < i; j++)
        p = p->next;
    ChainNode *q = new ChainNode(e, p->next);

    // q poin to new ChainNode
    // q->next = p->next ;
    // adjust links
    p->next = q;
    // increment cursize
    curSize++;
}

int LinkedList::remove(int i)
{
    if (isEmpty())
    {
        cerr << "Error : List is empty " << endl;
        return -1;
    }
    if (i < 0)
    {
        cerr << "Error : " << i << "is under lower bound " << endl;
        return -1;
    }
    else if (i >= curSize)
    {
        cerr << "Error : " << i << "is over upper bound " << endl;
        return -1;
    }
    ChainNode *p = firstNode;
    for (int j = 0; j < i; j++)
        p = p->next;
    ChainNode *q = p->next;
    ChainNode *r = q->next;
    int temp = q->element;
    delete q;
    p->next = r;
    curSize--;

    return temp;
}

void LinkedList::display()
{
    cout << "L : [ ";
    ChainNode *p = firstNode->next;
    for (int i = 0; i < curSize; i++)
    {
        cout << p->element;
        if (i < curSize - 1)
            cout << ",";
        p = p->next;
    }
    cout << " ] n : " << curSize<< endl;
}
void LinkedList::clear()
{
    ChainNode *p = firstNode->next;
    while (p != NULL)
    {
        ChainNode *n = p->next;

        delete p;
        p = n;
    }
    firstNode->next = NULL;
    curSize = 0;
}

int LinkedList::min()
{
    if (isEmpty())
    {
        cerr << "Error: LinkedList is empty" << endl;
        return -1;
    }
    else if (curSize == 1)
    {
        return firstNode->next->element;
    }
    else
    {
        int min = firstNode->next->element;
        ChainNode *p = firstNode->next->next;
        for (int i = 1; i < curSize; i++, p = p->next)
            if (min > p->element)
                min = p->element;
        return min;
    }
}

int LinkedList::max()
{
    if (isEmpty())
    {
        cerr << "Error: LinkedList is empty" << endl;
        return -1;
    }
    else if (curSize == 1)
    {
        return firstNode->next->element;
    }
    else
    {
        int max = firstNode->next->element;
        ChainNode *p = firstNode->next->next;
        for (int i = 1; i < curSize; i++, p = p->next)
        {
            if (max < p->element)
            {
                max = p->element;
            }
        }
        return max;
    }
}
int LinkedList::oddCount()
{
    ChainNode *p = firstNode->next;
    int oddCounter = 0;
    while (p != NULL)
    {
        if (p->element % 2 == 1)
            oddCounter++;
        p = p->next;
    }
    return oddCounter;
}
int LinkedList::EvenCount()
{
    return curSize - oddCount();
}
float LinkedList::sum()
{
    ChainNode *p = firstNode->next;

    float sum = 0.0f;
    while (p != NULL)
    {
        sum += p->element;
        p = p->next;
    }
    return sum;
    ;
}
float LinkedList::mean()
{
    return sum() / (float)curSize;
}
void LinkedList::sort()
{
    bool swapped;
    ChainNode *current;
    ChainNode *last = NULL;
    //cout << choice;
    do
    {
        swapped = false;
        current = firstNode->next;

        while (current->next != last)
        {
            //cout << choice;
            if (current->element > current->next->element)
                {
                    int temp = current->element;
                    current->element = current->next->element;
                    current->next->element = temp;
                    swapped = true;
                }
                current = current->next;
            }
            /*if (choice == 'n' || choice == 'N')
            {
                if (current->element > current->next->element)
                {
                    int temp = current->element;
                    current->element = current->next->element;
                    current->next->element = temp;
                    swapped = true;
                }
                current = current->next;
            }
            if (choice == 'y' || choice == 'y')
            {
                if (current->element < current->next->element)
                {
                    int temp = current->element;
                    current->element = current->next->element;
                    current->next->element = temp;
                    swapped = true;
                }
                current = current->next;
            }
        }*/
        last = current;
    } while (swapped);
}
void LinkedList::sort2()
{
     bool swapped;
    ChainNode *current;
    ChainNode *last = NULL;

    do
    {
        swapped = false;
        current = firstNode->next;

        while (current->next != last)
        {
        if (current->element < current->next->element)
                {
                    int temp = current->element;
                    current->element = current->next->element;
                    current->next->element = temp;
                    swapped = true;
                }
                current = current->next;
            }       last = current;
    } while (swapped);
}
void LinkedList::AutoInert(int maxSize)
{
    srand(time(0));
    //int random = rand()%10+1;
    for(int i=0;i<maxSize;i++)
    LinkedList::add(0, rand()%10+1);
}
bool LinkedList::isFull()
{
    ChainNode *p = new ChainNode;
    bool returnBool;
    if (p != NULL)
    {
        returnBool = false;
    }
    else
    {
        returnBool = true;
    }
    delete p;
    return returnBool;
}

bool LinkedList::isEmpty()
{
    return curSize == 0;
}
int LinkedList::sumEven()
{
    ChainNode *p = firstNode->next; 

    float sum = 0.0f;
    while (p != NULL) 
    {
        if (static_cast<int>(p->element) % 2 == 0) 
        {
            sum += p->element;
        }
        p = p->next; 
    }
    return sum;
}

int LinkedList::sumOOD()
{
   ChainNode *p = firstNode->next; 

    float sum = 0.0f;
    while (p != NULL) 
    {
        if (static_cast<int>(p->element) % 2 != 0) 
        {
            sum += p->element;
        }
        p = p->next; 
    }
    return sum;
}
