
#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include "Node.h"
#include "ContainerIfc.h"
#include <iostream>

using namespace std;

template <class T>
class List : public ContainerIfc<T>
{
private:
    Node<T> *head;
    void destroyList(Node<T> *);
public:
    List();
    ~List();
    List(const List&);
    List<T>& operator = (List&);
    List<T>& pushFront(T);
    List<T>& pushBack(T);
    List<T>& popFront(T&);
    List<T>& popBack(T&);
    int getSize();
    bool isEmpty();
    T front();
    T back();
    T& operator[](int);
    void readObject(istream &);
    void writeObject(ostream &);
};

template <class T>
List<T>::List()
{
    head = NULL;
}

template <class T>
List<T>::~List()
{
    Node<T> *del = head;
    while(head!=NULL)
    {
        head = head->next;
        del->next = NULL;
        delete del;
        del = head;
    }
}

template <class T>
List<T>::List(const List& that)
{
    if(that.head == NULL)
    {
        head = NULL;
    }
    else
    {
        Node<T> *thatPtr = that.head;
        head = new Node<T>;
        head->data = thatPtr->data;
        head->next = NULL;
        thatPtr = thatPtr->next;

        Node<T> *thisPtr = head;
        while(thatPtr != NULL)
        {
            thisPtr->next = new Node<T>;
            thisPtr=thisPtr->next;
            thisPtr->data=thatPtr->data;
            thisPtr->next=NULL;
            thatPtr=thatPtr->next;
        }
    }
}

template <class T>
List<T>& List<T>::operator = (List& n)
{
    Node<T> *ptr;
    Node<T> *ptr2;
    Node<T> *prev;

    if(this != &n)
    {
        if(n.head!=NULL)
        {
            ptr =n.head;
            while(ptr != 0)
            {
                ptr2=new Node<T>(*ptr);
                ptr2->next = NULL;
                if(head==NULL)
                {
                    head=ptr2;
                }
                else
                {
                    prev->next=ptr2;
                }
                ptr=ptr->next;
                prev=ptr2;
            }
        }
    }
    return *this;
}


template <class T>
List<T>& List<T>::pushFront(T n)
{
    Node<T> *ptr = new Node<T>(n);
    if(head==NULL)
    {
        head=ptr;
    }
    else
    {
        ptr->next=head;
        head=ptr;
    }
    return *this;
}

template <class T>
List<T>& List<T>::pushBack(T n)
{
    if(head==NULL)
    {
        head = new Node<T>(n);
    }
    else
    {
        Node<T> *nodePtr=head;
        while(nodePtr->next != NULL)
        {
            nodePtr=nodePtr->next;
        }
        nodePtr->next = new Node<T>(n);
    }
    return *this;
}

template <class T>
List<T>& List<T>::popFront(T& n)
{
    Node<T> *ptr;

    if(head != NULL)
    {
        n = head->data;
        ptr=head;
        head=head->next;
        delete ptr;
    }
    else
    {
        throw BADINDEX();
    }
    return *this;
}

template <class T>
List<T>& List<T>::popBack(T& n)
{
    if(isEmpty())
    {
        throw BADINDEX();
    }
    else if(head->next==NULL)
    {
        delete head;
        head=NULL;
    }
    else
    {
        Node<T> *prev=head;
        Node<T> *cur = head->next;
        while(cur->next != NULL)
        {
            prev=cur;
            cur=cur->next;
        }
        n = cur->data;
        delete cur;
        prev->next = NULL;
    }
    return *this;
}

template <class T>
int List<T>::getSize()
{
    int count=0;
    Node<T> *ptr = head;
    while(ptr != NULL)
    {
        count++;
        ptr=ptr->next;
    }
    return count;
}

template <class T>
bool List<T>::isEmpty()
{
    if(head==NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
T List<T>::front()
{
    if(head==NULL)
    {
        throw BADINDEX();
    }
    else
    {
        return head->data;
    }
}

template <class T>
T List<T>::back()
{
    if(head==NULL)
    {
        throw BADINDEX();
    }
    else
    {
        Node<T> *ptr = head;
        while(ptr->next != NULL)
        {
            ptr=ptr->next;
        }
        return ptr->data;
    }
}

template <class T>
T& List<T>::operator [](int n)
{

    if(n<0 || n>=getSize())
    {
        throw BADINDEX();
    }
    else
    {
        Node<T> *cur = this->head;
        for(int i=0; i<n; i++)
        {
            cur=cur->next;
        }

        return cur->data;
    }
}

template <class T>
void List<T>::readObject(istream & in)
{
    int b;
    Node<T> *temp;
    in.read(reinterpret_cast<char *>(b), sizeof(int));
    in.read(reinterpret_cast<char *>(&temp->data),
            b*sizeof(T));
}

template <class T>
void List<T>::writeObject(ostream & out)
{
    int a = getSize();
    out.write(reinterpret_cast<char *>(&a), sizeof(int));
    out.write(reinterpret_cast<char *>(&head->data),
              a*sizeof(T));
}

template <class T>
void List<T>::destroyList(Node<T> * ch)
{
    if(ch==NULL)
    {

    }
    else
    {
        destroyList(ch->next);
        delete ch;
    }
}

#endif // LIST_H_INCLUDED

