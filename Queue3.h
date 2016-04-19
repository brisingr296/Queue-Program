#ifndef QUEUE3_H_INCLUDED
#define QUEUE3_H_INCLUDED
#include "List.h"

template <class T>
class Queue3 : public List<T>
{
public:
    void enqueue(T);
    void dequeue(T&);
};

template <class T>
void Queue3<T>::enqueue(T ch)
{
    this->List<T>::pushBack(ch);

    /*Node<T> *front;
    Node<T> *rear;

    if(List<T>::isEmpty())
    {

        front = new Node<T>(ch);
        rear = front;
    }
    else
    {
        rear->next = new Node<T>(ch);
        rear = rear->next;
    }*/
}

template <class T>
void Queue3<T>::dequeue(T &ch)
{
    this->List<T>::popFront(ch);

    /*Node<T> *temp;
    Node<T> *front;

    if(List<T>::isEmpty())
    {
        throw BADINDEX();
    }
    else
    {
        ch = front->data;
        temp = front;
        front = front->next;
        delete temp;
    }*/
}


#endif // QUEUE3_H_INCLUDED
