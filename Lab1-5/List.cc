/*
 Filename: List.cc
 Author: Andreas Algovik, Elisabeth Hanning
 Description: The implementation file with the sourcecode for
 all struct and function needed to complete lab1-5.
 */

#include "List.h"
#include <iostream>

using namespace std;

struct List_Node{
	string name;
	int age;
	List_Node* next;
};

using List = List_Node*;

void append(List& list, const string& name, int age){

	auto p = new List_Node{name, age, nullptr};

	if(list == nullptr){
		list = p;
		return;
	}

	auto current = list;

	while(current->next != nullptr){
		current = current->next;
	}


	current->next = p;

}

void insert(List& list, const string& name, int age){

	auto p = new List_Node{name, age, list};
	list = p;
}

bool empty(const List& list){
	return list==nullptr;
}

void print(const List& list, ostream& out){

	auto current = list;

	while(current->next != nullptr){
		out << current->name << " (" << current->age << ")\n"; //Speciell utström?
		current = current->next;
	}
}

void print_reversed(const List& list, ostream& out){

	auto current = list;

	if(current->next != nullptr){
		print_reversed(current->next, out);
	}
	out << current->name << " (" << current->age << ")\n";
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
//	auto copy_head = copy;
//
// 	while(current != nullptr){
// 		copy->name = current->name;
// 		copy->age = current->age;
// 		copy = copy->next = new List_Node;
//
// 		current = current->next;
// 	}
//
// 	return copy_head;
// }
