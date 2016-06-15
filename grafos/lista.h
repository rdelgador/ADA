#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include "node.h"

using namespace std;

const int tam = 5;
template <class T>

class lista
{
    public:
        node<T> *m_head;
        node<T> *list_nodes[tam];
        int num_nodes;

        lista()
        {
            num_nodes = 0;
            m_head = NULL;
            for(int i=0;i<tam;++i)
                list_nodes[i] = NULL;
        };

        void add_node(T data_,int pos)
        {
            node<T> *new_node = new node<T> (data_);
            node<T> *temp = list_nodes[pos];

            if(!list_nodes[pos])
                list_nodes[pos] = new_node;
            else
            {
                while(temp->next != NULL)
                    temp = temp->next;
                temp->next=new_node;
            }
            num_nodes++;
        }

        void print()
        {
            for(int i=0;i<tam;++i)
            {
                node<T> *temp = list_nodes[i];
                if(!list_nodes[i])
                {
                    cout<<"|"<<i+1<<"|"<<" -> ";
                    cout<<"Lista vacia"<<endl;
                }
                else
                {
                    cout<<"|"<<i+1<<"|"<<" -> ";
                    while(temp)
                    {
                        temp->print();
                        if(!temp->next)
                            cout<<"/"<<endl;
                        temp = temp -> next;
                    }
                }
                cout<<endl;
            }
        }

    protected:

    private:
};

#endif // LISTA_H
