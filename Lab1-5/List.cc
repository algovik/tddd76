// .cc fil här skrivs funktionerna

#include List.h

struct List_Node{
	string name;
	int age;
	List_Node* next;
};

void append(List& list, const string& name, int age){
	
	auto p = new List_Node{name, age,
nullptr
}; //
typ
List_Node*
if
(list ==
nullptr
)//
tom lista
{
list = p;
return
;
}
//
Det finns minst en nod i listan, sök upp den sista noden och länka in den nya noden efter den sista
auto
last = list; //
typ
List_Node*
while
(last->next !=
nullptr
)
{
last = last->next;
}
last->next = p