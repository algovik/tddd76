/**
 * Filename: Expression-test.cc
 * Lab: Lab3 - Kalkylator för aritmetiska uttryck 
 * Authors: Andreas Algovik     890718-0031 I5
 *          Elisabeth Hanning   900419-2325 I5
 * Date: 161014
 * A test program for the Expression class
 */
#include "Expression.h"
#include "Expression_Tree.h"
#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
    Expression e1;  // defaultkonstruktor

    if(e1.empty()){
        cout << "Tomt uttryck!\n";
    }else{
        cout << "e1.evaluate() = " << e1.evaluate() << '\n';
    }
    cout << "e1.get_postfix() = " << e1.get_postfix() << '\n';
    cout << boolalpha << "e1.empty() = " << e1.empty() << "\n\n";

    Expression e2{e1};  // kopieringskonstruktor

    try{
        cout << "e2.evaluate() = " << e2.evaluate() << '\n';
    }catch (const exception& e){
        cout << "undantag fångat: " << e.what() << '\n';
    }
    cout << "e2.get_postfix() = " << e2.get_postfix() << '\n';
    cout << "e2.empty() = " << e2.empty() << "\n\n";

    e2.swap(e1);  // swap


    // Resten kräver implementering av Expression_Tree-klasserna.
    Expression_Tree* t{new Plus{new Integer{7}, new Real{3.14}}};
    Expression e3{t};  // konstruktor som tar ett länkat uttrycksträd

    cout << "e3.evaluate() = " << e3.evaluate() << '\n';
    cout << "e3.get_postfix() = " << e3.get_postfix() << '\n';
    cout << "e3.empty() = " << e3.empty() << "\n\n";

    e2.swap(e3);  // swap

    cout << "e2.evaluate() = " << e2.evaluate() << '\n';
    cout << "e2.get_postfix() = " << e2.get_postfix() << '\n';
    cout << "e2.empty() = " << e2.empty() << "\n\n";
    try{
        cout << "e3.evaluate() = " << e3.evaluate() << '\n';
    }catch (const exception& e){
        cout << "undantag fångat: " << e.what() << '\n';
    }
    cout << "e3.get_postfix() = " << e3.get_postfix() << '\n';
    cout << "e3.empty() = " << e3.empty() << "\n\n";

    Expression e4{e2};  // kopieringskonstruktor

    try{
        cout << "e4.evaluate() = " << e4.evaluate() << '\n';
    }catch (const exception& e){
        cout << "Undantag fångat: " << e.what() << '\n';
    }
    cout << "e4.get_postfix() = " << e4.get_postfix() << '\n';
    cout << "e4.empty() = " << e4.empty() << "\n\n";

    Expression e5{std::move(e2)};  // move-konstruktor

    cout << "e5.evaluate() = " << e5.evaluate() << '\n';
    cout << "e5.get_postfix() = " << e5.get_postfix() << '\n';
    cout << "e5.empty() = " << e5.empty() << '\n';
    cout << "e2.empty() = " << e2.empty() << "\n\n";

    e2 = std::move(e5);  // move-tilldelning

    cout << "e2.evaluate() = " << e2.evaluate() << '\n';
    cout << "e2.get_postfix() = " << e2.get_postfix() << '\n';
    cout << "e2.empty() = " << e2.empty() << '\n';
    cout << "e5.empty() = " << e5.empty() << "\n\n";
    e2.print_tree(cout);

    return 0;
}
