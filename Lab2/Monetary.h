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

	class monetaryerror : public std::logic_error {
	public:
		explicit monetaryerror(const std::string& whatarg) noexcept
			: logic_error{whatarg} {}

		explicit monetaryerror(const char* whatarg) noexcept
			: logic_error{whatarg} {}
	};


	class Money{

		std::string curr{""};
	    int unit{0};
	    int cunit{0};


	public:
		// Money();
		// Money() = default;
		// Money(std::string);
		// Money(int x, int y);
		Money(const std::string s, const int x=0, const int y=0);
		Money(const int x=0, const int y=0);
		~Money();
		std::string currency();
		void print(std::ostream& out);
		void setcurrency(std::string s);
		void setunit(int x, int y);
		friend std::ostream& operator<< (std::ostream& o, Money const& money);
		const Money operator+(const Money& rhs);
		const Money operator-(const Money& rhs);
		Money&  operator=(const Money& rhs);
		friend bool operator==(const Money& lhs, const Money& rhs);
		friend bool operator<(const Money& lhs, const Money& rhs);
		friend bool operator<=(const Money& lhs, const Money& rhs);
		friend bool operator>(const Money& lhs, const Money& rhs);
		friend bool operator>=(const Money& lhs, const Money& rhs);
		friend bool operator!=(const Money& lhs, const Money& rhs);
		Money& operator++();
		Money operator++(int);
		Money& operator--();
		Money operator--(int);

	};



}
 #endif
