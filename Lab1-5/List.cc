// .cc fil här skrivs funktionerna

#include "List.h"

using namespace std;

struct List_Node{
	string name;
	int age;
	List_Node* next;
};

using List = List_Node*;

List head{nullptr};

void append(List& list, const string& name, int age){

	auto p = new List_Node{name, age, nullptr};

	if(list == nullptr){
		list = p;
		return;
	}

	auto last = list;

	while(last->next != nullptr){
		last = last->next;
	}

	last->next = p;
}

void insert(List& list, const string& name, int age){

	auto p = new List_Node{name, age, list};
	list = p;
}

bool empty(List& list){

	if(list == nullptr){
		return true;
	}else{
		return false;
	}
}

void print(List& list, ostream& out){

	auto last = list;

	while(last->next != nullptr){
		out << last->name << " (" << last->age << ")\n"; //Speciell utström?
		last = last->next;
	}
}

void print_reversed(List& list, ostream& out){

	auto last = list;

	if(last->next != nullptr){
		print_reversed(last->next, out);
	}
	out << list->name << " (" << list->age << ")\n";
}

void clear(List& list){

	auto current = list;
	List next;

	while(current != nullptr){
		next = current->next;
		free(current);
		current = next;
	}
}

// List copy(List list){
//
// 	auto current = list;
// 	auto copy = new List_Node*;
//
// 	while(current != nullptr){
// 		copy->name = current->name;
// 		copy->age = current->age;
// 		copy = copy->next = new List_Node;
//
// 		current = current->next;
// 	}
//
// 	return copy;
// }
