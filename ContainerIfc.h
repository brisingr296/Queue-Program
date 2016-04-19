#ifndef CONTAINERIFC_H_INCLUDED
#define CONTAINERIFC_H_INCLUDED
#include "Serializable.h"

class BADINDEX{};

template <class T>
class ContainerIfc : public SerializableIfc
{
public:
    virtual ContainerIfc <T>& pushFront(T) = 0;
    virtual ContainerIfc <T>& pushBack(T) = 0;
    virtual ContainerIfc <T>& popFront(T&) = 0;
    virtual ContainerIfc <T>& popBack(T&) = 0;
    virtual int getSize() = 0;
    virtual bool isEmpty() = 0;
    virtual T front() = 0;
    virtual T back() = 0;
    virtual T& operator[](int) = 0;
};


#endif // CONTAINERIFC_H_INCLUDED
