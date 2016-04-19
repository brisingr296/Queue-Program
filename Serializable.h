#ifndef SERIALIZABLE_H_INCLUDED
#define SERIALIZABLE_H_INCLUDED
#include <iostream>

using namespace std;

class SerializableIfc
{
public:
    virtual void writeObject(ostream &) = 0;
    virtual void readObject(istream &) = 0;
};


#endif // SERIALIZABLE_H_INCLUDED
