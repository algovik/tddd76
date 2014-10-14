/*
 * expression_tree-test.cc
 */
#include "Expression_Tree.h"
#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
   // Ska inte vara möjligt - Expression_Tree ska vara abstrakt:
   // Expression_Tree* t0{new Expression_Tree};
   Expression_Tree* t0{ new Integer{10} };
   Expression_Tree* t2{ new Real{10.24} };

   Expression_Tree* t3{ new Plus{t0,t2} };
   cout << t3->evaluate() << endl;

   Expression_Tree* t4{ new Minus{t0,t2} };
   cout << t4->evaluate() << endl;

   Expression_Tree* t5{ new Times{t0,t2} };
   cout << t5->evaluate() << endl;

   Expression_Tree* t6{ new Divide{t5,t0} };
   cout << t6->evaluate() << endl;

   Expression_Tree* t1{ new Plus{ new Integer{7}, new Integer{3} } };
   cout << t1->evaluate() << endl;

   // try
   // {
   //    cout << "t1->evaluate() = " << t1->evaluate() << '\n';
   // }
   // catch (const exception& e)
   // {
   //    cout << "Undantag fångat: " << e.what() << '\n';
   // }
   //
   // cout << "t1->get_postfix() = " << t1->get_postfix() << '\n';
   // cout << "t1->str() = " << t1->str() << "\n\n";
   //
   // Expression_Tree* t2{ ct1->clone() };
   //
   // try
   // {
   //    cout << "t2->evaluate() = " << t2->evaluate() << '\n';
   // }
   // catch (const exception& e)
   // {
   //    cout << "Undantag fångat: " << e.what() << '\n';
   // }
   // cout << "t2->get_postfix() = " << t2->get_postfix() << '\n';
   // cout << "t2->str() = " << t2->str() << "\n\n";

   return 0;
}
