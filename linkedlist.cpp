#include "linkedlist.h"
#include <iostream>
using namespace std;

Node *LinkedList::getFirst() const
{
    return first;
}

void LinkedList::setFirst(Node *value)
{
    first = value;
}

void LinkedList::Add(void *data)
{
    Node* tmp=new Node(data);
    tmp->setNext(this->first);
    this->first=tmp;
}

void *LinkedList::Delete()
{
    Node* tmp=this->first;
    this->first=this->first->getNext();
    return tmp;
}

void LinkedList::Print()
{
    Node* tmp=this->first;
    while (tmp!=nullptr){
        cout<<tmp<<endl;
        tmp=tmp->getNext();
    }
}

LinkedList::LinkedList()
{

}
