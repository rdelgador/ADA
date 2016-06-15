#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

template <class T>

class node
{
    public:
        T data;
        node *next;
        node();

        node(T data_)
        {
            data = data_;
            next = NULL;
        };

        void print()
        {
            cout<< data <<" -> ";
        }

    protected:

    private:
};

#endif // NODE_H
