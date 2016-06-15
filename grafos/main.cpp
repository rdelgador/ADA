#include <iostream>
#include "lista.h"

using namespace std;

//////////Representacion de Grafos (Cormen, pag. 590)////////

int main()
{
    lista<int> lista1;
    lista1.add_node(2,0);
    lista1.add_node(5,0);

    lista1.add_node(1,1);
    lista1.add_node(5,1);
    lista1.add_node(3,1);
    lista1.add_node(4,1);

    lista1.add_node(2,2);
    lista1.add_node(4,2);

    lista1.add_node(2,3);
    lista1.add_node(5,3);
    lista1.add_node(3,3);

    lista1.add_node(4,4);
    lista1.add_node(1,4);
    lista1.add_node(2,4);

    lista1.print();

}
