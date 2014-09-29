/**
 * Filename: List.cc
 * Lab: Lab 1 - Imperative programming
 * Authors: Andreas Algovik     890718-0031 I5
 *          Elisabeth Hanning   900419-2325 I5
 * Date: 160914
 * Description: The implementation file with the sourcecode for
 * the struct and all function needed to complete lab1-5.
 */

#include "List.h"
#include <iostream>

using namespace std;

/**
 * A struct that is representing a node in a linked list
 */
struct List_Node{
	string name;
	int age;
	List_Node* next;
};


/**
 * Adds a node at the end of a linked list
 * @param	list  The list the node should be added to
 * 			name  The name that should be stored in the added node
 * 			 age  The age that should be stored in the added node
 */
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

/**
 * Adds a node in the begining of a linked list
 * @param	list  The list the node should be added to
 * 		  	name  The name that should be stored in the added node
 * 		   	 age  The age that should be stored in the added node
 */
void insert(List& list, const string& name, int age){

	auto p = new List_Node{name, age, list};
	list = p;
}

/**
 * Check if a list is empty or not
 * @param list  The list that should be checked
 * @return true if the list is empty, otherwise false
 */
bool empty(const List& list){
	return list==nullptr;
}

/**
 * Prints a linked list
 * @param	list  The linked list that should be printed
 * 			 out  The outstream to be used
 */
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

/**
 * Prints a linked list in reversed order
 * @param	list  The linked list that should be printed
 * 			 out  The outstream to be used
 */
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

/**
 * Remove all the nodes in a linked list
 * @param list  The linked list that should be cleared
 */
void clear(List& list){

	auto current = list;
	list = nullptr;
	List next;

	do{
		next = current->next;
		delete current;
		current = next;
	}while(current != nullptr);

}

/**
 * Creates a copy of a linked list
 * @param list  The linked list that should be copied
 * @return an indentical linked list
 */
List copy(const List& list){

	List copy{nullptr};
	List copy_current{nullptr};
	auto current = list;

	do{
		auto p = new List_Node{current->name, current->age, nullptr};
		if(copy == nullptr){
			copy = p;
			copy_current = p;
		}else{
			copy_current->next = p;
			copy_current = copy_current->next;
		}
		current = current->next;
	}while(current != nullptr);

	return copy;
}

/**
 * Reverse the order of the nodes in a linked list
 * @param list  The linked list that should be reversed
 */
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

/**
 * Switches the content of two linked lists
 * @param	list1  One of the list that should be swapped
 * 			list2  The other list that should be swapped
 */
void swap(List& list1, List& list2){
	auto temp = list1;
	list1 = list2;
	list2 = temp;
}
