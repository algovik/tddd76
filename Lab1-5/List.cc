// .cc fil här skrivs funktionerna

#include List.h

struct List_Node{
	string name;
	int age;
	List_Node* next;
};

void append(List& list, const string& name, int age){
	
	auto p = new List_Node{name, age, nullptr}; //

	if(list ==nullptr){
		list = p;
		return;
	}

	auto last = list; 
	
	while(last->next !=nullptr){
		last = last->next;
	}
	
	last->next = p
}

void insert(List& list, const string& name, int age){
	
	auto p = new List_Node{name, age, nullptr}; //

	if(list ==nullptr){
		list = p;
		return;
	}

	auto last = list; 
	
	while(last->next !=nullptr){
		last = last->next;
	}
	
	last->next = p
}