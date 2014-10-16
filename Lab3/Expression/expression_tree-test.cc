/*
 * expression_tree-test.cc
 */
#include "Expression_Tree.h"
#include <iostream>
#include <stdexcept>

using namespace std;

int main(){

   // Ska inte vara möjligt - Expression_Tree ska vara abstrakt:
   // Expression_Tree* t0{new Expression_Tree};


   // (5 + ((1 + 2) × 4) − 3 can be written down like this in RPN:
   // 5 1 2 + 4 × + 3 −
   Expression_Tree* s1{new Integer{1} };
   Expression_Tree* s2{new Integer{2} };
   Expression_Tree* s3{new Integer{3} };
   Expression_Tree* s4{new Integer{4} };
   Expression_Tree* s5{new Integer{5} };

   Expression_Tree* p1{new Plus{s1,s2}};
   Expression_Tree* p2{new Times{p1,s4}};
   Expression_Tree* p3{new Plus{s5,p2}};
   Expression_Tree* p4{new Minus{p3,s3}};
   cout << p4->get_postfix() << endl;

   Expression_Tree* p5{new Plus{p1,s2}}; //tillagd
   Expression_Tree* p6{new Plus{p5,s5}};
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

   cout << t0->str() << endl;
   cout << t1->str() << endl;

   Expression_Tree* t7{ new Plus{t4,t5}};

   cout << t7->get_postfix() << endl;

   cout << t1->get_postfix() << endl;

   cout << "--------------------------------" << endl;

   p6->print(cout, 20);

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
