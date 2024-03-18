#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_
#include "../ChainNode/ChainNode.h"
class LinkedList
{
protected:
    bool isFull();
    bool isEmpty();
    ChainNode *firstNode;
    int curSize;
    int maxSize;

public:
    LinkedList(int maxSize);
    ~LinkedList();
    int get_maxSize();
    int size();             // done
    int indexOf(int e);     // done
    int get(int i);         // done
    void set(int i, int e); // done
    void add(int i, int e); // done
    int remove(int i);
    void display(); // done
    void clear();   // done
    int min();      // done
    int max();      // done

    int oddCount();  // done
    int EvenCount(); // done
    float sum();     // done
    float mean();    // done
    void sort();
    void sort2();
    void AutoInert(int maxSize);
    int sumEven();
    int sumOOD();
};
#endif