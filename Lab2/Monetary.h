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
//#include <iostream>
//#include <string>

namespace monetary{

class Money
{
	std::string currency;
    int unit;
    int cunit;

public:
	void print();
	void setcurrency(string s);
	void setunit(int x, int y);
};

}
 #endif
