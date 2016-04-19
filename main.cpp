#include <iostream>
#include <fstream>
#include <string>
#include "Queue1.h"
#include "Queue2.h"
#include "Queue3.h"

using namespace std;

int main()
{
    cout << "TESTING QUEUE1: " << endl << endl;

    Queue1 <int> a;
    int yol = 0;

    fstream file1("queue1.bin", ios::binary | ios::out);

    if(!file1)
    {
        cout << "Error. File Does Not Exist." << endl;
    }
    else
    {
        cout << "Loading up enqueue to Object a..." << endl;
        for(int i=0; i<10; i++)
        {
            a.enqueue(i);
        }
        cout << "Displaying Object a: " << endl;
        for(int i=0; i<a.getSize(); i++)
        {
            cout << a.operator[](i) << " ";
        }
        cout << endl << endl;

        cout << "Testing dequeue: " << endl;
        try
        {
            a.dequeue(yol);
        }
        catch(BADINDEX)
        {
            cout << "ERROR." << endl;
        }

        cout << "Displaying Object a after using dequeue: " << endl;
        for(int i=0; i<a.getSize(); i++)
        {
            cout << a.operator[](i) << " ";
        }
        cout << endl << endl;

        a.writeObject(file1);
        file1.close();

        fstream file1("queue1.bin", ios::binary | ios::in);
        a.readObject(file1);
        cout << "Reading from file queue1.bin: " << endl;
        for(int i=0; i<a.getSize(); i++)
        {
            cout << a.operator[](i) << " ";
        }
        cout << endl << endl;
    }


    cout << "TESTING QUEUE2: " << endl << endl;

    Queue2 <int> b;
    int yak = 0;

    fstream file2("queue2.bin", ios::binary | ios::out);

    if(!file2)
    {
        cout << "Error. File Does Not Exist." << endl;
    }
    else
    {
        cout << "Loading enqueue to Object b..." << endl;
        for(int i=0; i<10; i++)
        {
            b.enqueue(i);
        }
        cout << "Displaying Object b: " << endl;
        for(int i=0; i<b.getSize(); i++)
        {
            cout << b.operator[](i) << " ";
        }
        cout << endl << endl;

        cout << "Testing dequeue: " << endl;
        try
        {
            b.dequeue(yak);
        }
        catch(BADINDEX)
        {
            cout << "ERROR." << endl;
        }

        cout << "Displaying Object b after dequeue: " << endl;
        for(int i=0; i<b.getSize(); i++)
        {
            cout << b.operator[](i) << " ";
        }
        cout << endl << endl;

        b.writeObject(file2);
        file2.close();

        fstream file2("queue2.bin", ios::binary | ios::in);
        b.readObject(file2);
        cout << "Reading file from queue2.bin: " << endl;
        for(int i=0; i<b.getSize(); i++)
        {
            cout << b.operator[](i) << " ";
        }
        cout << endl << endl;
    }


    cout << "TESTING QUEUE3: " << endl << endl;

    Queue3 <int> c;
    int yep = 0;

    fstream file3("queue3.bin", ios::binary | ios::out);

    if(!file3)
    {
        cout << "Error. File Does Not Exist." << endl;
    }
    else
    {
        cout << "Loading enqueue to Object c..." << endl;
        for(int i=0; i<10; i++)
        {
            c.enqueue(i);
        }
        cout << "Displaying Object c: " << endl;
        for(int i=0; i<c.getSize(); i++)
        {
            cout << c.operator[](i) << " ";
        }
        cout << endl << endl;

        cout << "Testing dequeue: " << endl;
        try
        {
            c.dequeue(yep);
        }
        catch(BADINDEX)
        {
            cout << "ERROR." << endl;
        }

        cout << "Displaying Object c after dequeue: " << endl;
        for(int i=0; i<c.getSize(); i++)
        {
            cout << c.operator[](i) << " ";
        }
        cout << endl << endl;

        c.writeObject(file3);
        file3.close();

        fstream file3("queue3.bin", ios::binary | ios::in);
        c.readObject(file3);
        cout << "Reading file from queue3.bin: " << endl;
        for(int i=0; i<c.getSize(); i++)
        {
            cout << c.operator[](i) << " ";
        }
        cout << endl << endl;
    }



    return 0;
}
