#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"



class LinkedList
{
private:
    Node* first;
public:
    void Add(void* data);
    void* Delete();
    void Print();
    LinkedList();
    Node *getFirst() const;
    void setFirst(Node *value);
};

#endif // LINKEDLIST_H
