#ifndef QUEUE2_H_INCLUDED
#define QUEUE2_H_INCLUDED
#include "MyVector.h"
#include <iostream>

using namespace std;

template <class T>
class Queue2 : public MyVector<T>
{
private:
    int front, rear;
public:
    Queue2();
    void enqueue(T);
    void dequeue(T&);
    void writeObject(ostream &);
    void readObject(istream &);
};

template <class T>
Queue2<T>::Queue2()
{
    front = -1;
    rear = -1;
}

template <class T>
void Queue2<T>::enqueue(T ch)
{
    if(MyVector<T>::size > MyVector<T>::capacity)
    {
        cout << "Error. Queue is full." << endl;
    }
    else
    {
        rear = (rear+1) % MyVector<T>::capacity;
        MyVector<T>::data[rear] = ch;
        MyVector<T>::size++;
    }
}

template <class T>
void Queue2<T>::dequeue(T &ch)
{
    if(front == -1 && rear == -1)
    {
        throw BADINDEX();
    }
    else
    {
        front = (front+1) % MyVector<T>::capacity;
        ch = MyVector<T>::data[front];
        //MyVector<T>::shiftLeft();
        MyVector<T>::size--;
    }
}

template <class T>
void Queue2<T>::writeObject(ostream &out)
{
    out.write(reinterpret_cast<char *>(&this->MyVector<T>::size), sizeof(int));
    out.write(reinterpret_cast<char *>(&this->MyVector<T>::capacity),
              sizeof(int));
    out.write(reinterpret_cast<char *>(&front), sizeof(int));
    out.write(reinterpret_cast<char *>(&rear), sizeof(int));
    out.write(reinterpret_cast<char *>(MyVector<T>::data),
              MyVector<T>::size*sizeof(T));
}

template <class T>
void Queue2<T>::readObject(istream &in)
{
    in.read(reinterpret_cast<char *>(&this->MyVector<T>::size), sizeof(int));
    in.read(reinterpret_cast<char *>(&this->MyVector<T>::capacity),
            sizeof(int));
    in.read(reinterpret_cast<char *>(&front), sizeof(int));
    in.read(reinterpret_cast<char *>(&rear), sizeof(int));
    MyVector<T>::data = new T[MyVector<T>::capacity];
    in.read(reinterpret_cast<char *>(MyVector<T>::data),
            MyVector<T>::size*sizeof(T));
}


#endif // QUEUE2_H_INCLUDED
