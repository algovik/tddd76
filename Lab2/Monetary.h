/**
 * Filename: Monetary.h
 * Lab: Lab2 - Klass, operatoröverlagring, undantag
 * Authors: Andreas Algovik     890718-0031 I5
 *          Elisabeth Hanning   900419-2325 I5
 * Date:
 * Description:
 */

#ifndef MONETARY_H
#define  MONETARY_H
#include <iostream>
#include <string>

namespace monetary{

	class Money{

		std::string curr;
	    int unit;
	    int cunit;

		public:
			Money();
			Money(std::string);
			Money(int x, int y);
			Money(std::string s, int x, int y);
			std::string currency();
			void print(std::ostream& out);
			void setcurrency(std::string s);
			void setunit(int x, int y);
			friend std::ostream& operator<< (std::ostream& o, Money const& money);
			int operator+(const Money& lhs, const Money& rhs);
		};

}
 #endif
