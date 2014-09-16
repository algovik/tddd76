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
	if(empty(current)){
		out << "The list is empty.\n";
		return;
	}

	do{
		out << current->name << " (" << current->age << ")\n";
		current = current->next;
	}while(current != nullptr);
}

void print_reversed(const List& list, ostream& out){

	auto current = list;
	if(empty(current)){
		out << "The list is empty.\n";
		return;
	}

	if(current->next != nullptr){
		print_reversed(current->next, out);
	}
	out << current->name << " (" << current->age << ")\n";
}

void clear(List& list){

	auto current = list;
	list = nullptr;
	List next;

	do{
		next = current->next;
		delete(current);
		current = next;
	}while(current != nullptr);
}

List copy(List list){

	List copy{nullptr};
	auto current = list;

	do{
		append(copy, current->name,current->age);
		current = current->next;
	}while(current != nullptr);

	return copy;
}

void reverse(List& list){

	auto current = list;
	List next;
	List previous{nullptr};

	while(current != nullptr){
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	list = previous;
}

void swap(List& list1, List& list2){
	auto temp = list1;
	list1 = list2;
	list2 = temp;
}
