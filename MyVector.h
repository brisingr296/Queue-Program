
#ifndef MYVECTOR_H_INCLUDED
#define MYVECTOR_H_INCLUDED
#include "ContainerIfc.h"
#include <string>
#include <iostream>

using namespace std;

template <class T>
class MyVector: public ContainerIfc<T>
{
protected:
    int size;
    int capacity;
    T *data;

    void grow();
    void shiftRight();
    void shiftLeft();
public:
    MyVector();
    ~MyVector();
    MyVector(const MyVector &);
    MyVector<T>& operator = (const MyVector&);
    void writeObject(ostream &);
    void readObject(istream &);
    MyVector<T>& pushFront(T);
    MyVector<T>& pushBack(T);
    MyVector<T>& popFront(T&);
    MyVector<T>& popBack(T&);
    T front();
    T back();
    T& operator [] (int);
    int getSize();
    bool isEmpty();
    void erase();
};

template <class T>
MyVector<T>::MyVector()
{
    size=0;
    capacity=10;
    data = new T[capacity];
}

template <class T>
MyVector<T>::~MyVector()
{
    size=0;
    capacity=0;
    delete [] data;
}

template <class T>
MyVector<T>::MyVector(const MyVector & v)
{
    this = v.size;
    this = v.capacity;
    data = new T[capacity];
    for(int i=0; i<size; i++)
    {
        data[i] = v.data[i];
    }
}

template <class T>
MyVector<T>& MyVector<T>::pushFront(T e)
{
    if(size == capacity)
    {
        T *temp = data;
        capacity*=2;
        data = new T[capacity];
        for(int i=0; i<size; i++)
        {
            data[i] = temp[i];
        }
        delete [] temp;
    }
    shiftRight();
    data[0] = e;
    size++;
    return *this;
}

template <class T>
MyVector<T>& MyVector<T>::pushBack(T e)
{
    if(size == capacity)
    {
        T *temp = data;
        capacity*=2;
        data = new T[capacity];
        for(int i=0; i<size; i++)
        {
            data[i] = temp[i];
        }
        delete [] temp;
    }
    data[size] = e;
    size++;
    return *this;
}

template <class T>
MyVector<T>& MyVector<T>::popFront(T& e)
{
    if(size==0)
    {
        throw BADINDEX();
    }
    else
    {
        e = data[0];
        for(int i=0; i<size-1; i++)
        {
            data[i] = data[i+1];
        }
        size--;
        data[size] = '\0';
    }
    return *this;
}

template <class T>
MyVector<T>& MyVector<T>::popBack(T& e)
{
    if(size==0)
    {
        throw BADINDEX();
    }
    else
    {
        e = data[size-1];
        data[size] = '\0';
        size--;
    }
    return *this;
}

template <class T>
int MyVector<T>::getSize()
{
    return size;
}

template <class T>
bool MyVector<T>::isEmpty()
{
    if(size==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
void MyVector<T>::erase()
{
    size=0;
    capacity=0;
}

template <class T>
T MyVector<T>::front()
{
    if(size==0)
    {
        throw BADINDEX();
    }
    else
    {
        return data[0];
    }
}

template <class T>
T MyVector<T>::back()
{
    if(size==0)
    {
        throw BADINDEX();
    }
    else
    {
        return data[size-1];
    }
}

template <class T>
T& MyVector<T>::operator[](int n)
{
    if(n>=capacity || n<0)
    {
        throw BADINDEX();
    }
    else
    {
        return data[n];
    }
}

template <class T>
MyVector<T>& MyVector<T>::operator = (const MyVector& v)
{
    if(this != &v)
    {
        delete [] data;
        size = v.size;
        capacity = v.capacity;
        data = new T[capacity];
        for(int i=0; i<size; i++)
        {
            data[i] = v.data[i];
        }
    }
    return *this;
}

template <class T>
void MyVector<T>::writeObject(ostream &out)
{
    out.write(reinterpret_cast<char *>(&size), sizeof(int));
    out.write(reinterpret_cast<char *>(&capacity), sizeof(int));
    out.write(reinterpret_cast<char *>(data), size*sizeof(T));
}

template <class T>
void MyVector<T>::readObject(istream &in)
{
    in.read(reinterpret_cast<char *>(&size), sizeof(int));
    in.read(reinterpret_cast<char *>(&capacity), sizeof(int));
    data = new T[capacity];
    in.read(reinterpret_cast<char *>(data), size*sizeof(T));
}

//Private Functions:
template <class T>
void MyVector<T>::shiftRight()
{
    T temp;
    for(int i=0; i<(size-1); i++)
    {
        temp=data[size-1];
        data[size-1] = data[i];
        data[i] = temp;
    }
}

template <class T>
void MyVector<T>::shiftLeft()
{
    for(int i=0; i<size; i++)
    {
        data[i] = data[i+1];
    }
}

template <class T>
void MyVector<T>::grow()
{
    T *temp = data;
    capacity*=2;
    data = new T[capacity];
    for(int i=0; i<size; i++)
    {
        data[i] = temp[i];
    }
    delete [] temp;
    return *this;
}

#endif // MYVECTOR_H_INCLUDED

