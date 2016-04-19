#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

template <class T>
class Node
{
public:
    T data;
    Node *next;
    Node(T d)
    {
        data = d;
        next = NULL;
    }
};

#endif // NODE_H_INCLUDED
