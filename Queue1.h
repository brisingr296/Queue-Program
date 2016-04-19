#ifndef QUEUE1_H_INCLUDED
#define QUEUE1_H_INCLUDED
#include "MyVector.h"
#include <iostream>

using namespace std;

template <class T>
class Queue1 : public MyVector<T>
{
public:
    void enqueue(T);
    void dequeue(T&);
};

template <class T>
void Queue1<T>::enqueue(T ch)
{
    if(MyVector<T>::size > MyVector<T>::capacity)
    {
        cout << "Error." << endl;
    }
    else
    {
        this->pushBack(ch);
    }
}

template <class T>
void Queue1<T>::dequeue(T &ch)
{
    if(MyVector<T>::isEmpty())
    {
        throw BADINDEX();
    }
    else
    {
        this->popFront(ch);
    }
}


#endif // QUEUE1_H_INCLUDED
