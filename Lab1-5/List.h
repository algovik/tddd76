// .h definera funktionerna
#ifndef LIST_H
#define  LIST_H

#include <string>
#include <ostream>

namespace list{

    struct List_Node;

    using List = List_Node*;

    void append(List& list, const string& name, int age);
    void insert(List& list, const string& name, int age);
    bool empty(List& list);
    void print(List& list, ostream& out);
    void print_reversed(List& list, ostream& out);
    void clear(List& list);
    List copy(List list);
}

#endif
