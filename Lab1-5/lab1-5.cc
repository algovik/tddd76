/**
 * Filename: lab1-5.cc
 * Lab: Lab 1 - Imperative programming
 * Authors: Andreas Algovik     890718-0031 I5
 *          Elisabeth Hanning   900419-2325 I5
 * Date: 160914
 * Description: A program for lab1-5 that works with linked list.
 */

#include <iostream>
#include <fstream>
#include "List.h"

using namespace std;

// Deklarera en funktion build_lists(inström, list_1, list_2) som läser namn
// från inströmmen och använder insert() för att sätta in i list_1 och append()
// för att sätta in i list_2. build_lists() ska definieras efter main().

void build_lists(istream& in, List& list_1, List& list_2);

int main(int argc, char** argv){
    // Kontrollera att ett argument (filnamn) angivits på kommandoraden.
    // Om inte skriv ut ett felmeddelande och avsluta programmet.
    if(argc<=1){
        cout << "Du måste ange ett filnamn som argument. Programmet avslutas.\n";
        return 0;
    }
    // öppna en infilström för den fil vars namn givits på kommandoraden.
    // Kontrollera att öppningen lyckas, om inte ska ett felmeddelande
    // skrivas ut och programmet avslutas.
    ifstream input;
    input.open(argv[1]);
    if(!input.is_open()){
        cout << "Filen kunde ej öppnas. Programmet avslutas.\n";
        return 0;
    }
    // Deklarera två tomma listor, list_1 och list_2
    List list_1{nullptr};
    List list_2{nullptr};
    // Kontrollera med empty() att listorna är tomma och skriv ut det.
    if(empty(list_1)){
        cout << "list_1 is empty\n";
    }
    if(empty(list_2)){
        cout << "list_2 is empty\n";
    }
    // Anropa build_lists() för att läsa namn från indata och sätta in i namnen
    // i list_1 och list_2, enligt vad som sagts om build_lists() ovan.
    build_lists(input,list_1,list_2);

    if(empty(list_1)){
        cout << "list_1 is empty\n";
    }
    cout << "Lista 1 efter inläsning av namn:\n";
    print(list_1,cout); // Skriv ut list_1 med print()
    cout << "Lista 2 efter inläsning av namn:\n";
    print(list_2,cout); // Skriv ut list_2 med print()
    cout << "Lista 1 utskriven i omvänd ordning:\n";
    print_reversed(list_1,cout); // Skriv ut list_1 med print_reversed()
    cout << "Lista 1 vänds.\n";
    reverse(list_1); // Vänd innehållet i list_1 med reverse();
    cout << "Lista 1 efter vändning:\n";
    print(list_1,cout); // Skriv ut list_1 med print()

    cout << "Lista 2 raderas.\n";
    clear(list_2); // Radera list_2 med clear()
    if(empty(list_2)){
        cout << "Lista 2 är tom.\n";
    }else{
        cout << "Lista 2 är inte tom.\n";
    }
    cout << "Lista 2 tilldelas en kopia av lista 1.\n";
    list_2 = copy(list_1); // Använd copy() för att kopiera list_1
    cout << "Lista 2 innehåller:\n";
    print(list_2, cout); // Skriv ut list_2 med print()

    cout << "Lista 2 raderas.\n";
    clear(list_2); // Radera list_2 med clear()
    cout << "Lista 1 och 2 byter innehåller.\n";
    swap(list_1,list_2); // Använd swap()
    if(empty(list_1)){
        cout << "Lista 1 är tom.\n";
    }else{
        cout << "Lista 1 är inte tom.\n";
    }
    cout << "Lista 2 innehåller:\n";
    print(list_2,cout); // Skriv ut list_2 med print()

    cout << "Lista 2 raderas.\n";
    clear(list_2); // Radera list_2 med clear()

    if(empty(list_1) && empty(list_2)){ // Kontrollera med empty() att listorna är tomma och skriv ut det.
        cout << "Båda listorna är tomma.\n";
    }

    cout << "Programmet avslutas.\n";

    return 0;
}

/**
 * Calls the functions append and insert to insert the input streams value in to two lists
 * @param     in  The instream used
 *        list_1  The first list created in the program
 *        list_2  The secons list created in the program
 */
void build_lists(istream& in, List& list_1, List& list_2){

    string name;
    int age;

    while(in >> name >> age){
        append(list_1,name,age);
        insert(list_2,name,age);
    }
}
