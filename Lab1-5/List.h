// .h definera funktionerna
#ifndef LIST_H
#define  LIST_H
#include <iostream>
#include <string>

struct List_Node;

using List = List_Node*;

void append(List& list, const std::string& name, int age);
void insert(List& list, const std::string& name, int age);
bool empty(const List& list);
void print(const List& list, std::ostream& out);
void print_reversed(const List& list, std::ostream& out);
void clear(List& list);
// List copy(List list);


#endif
