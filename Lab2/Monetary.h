/**
 * Filename: Monetary.h
 * Lab: Lab2 - Classes, operator overloading, exceptions
 * Authors: Andreas Algovik     890718-0031 I5
 *          Elisabeth Hanning   900419-2325 I5
 * Date: 031014
 * The interface declaration file listing all the function
 * that exist in Monetary.cc.
 */

#ifndef MONETARY_H
#define  MONETARY_H
#include <iostream>
#include <string>

namespace monetary{

	/**
 	* A exception class for errors in regards to the Money class.
 	*/
	class monetaryerror : public std::logic_error {
	public:
		explicit monetaryerror(const std::string& whatarg) noexcept
			: logic_error{whatarg} {}

		explicit monetaryerror(const char* whatarg) noexcept
			: logic_error{whatarg} {}
	};

	/**
 	* A class for the object Money
 	*/
	class Money{

	private:
		std::string curr{""};
		int unit{0};
		int cunit{0};

		void checkformat();

	public:
		Money(const std::string s, const int x=0, const int y=0);
		Money(const int x=0, const int y=0);
		~Money();
		std::string currency();
		void print(std::ostream& out);
		friend std::ostream& operator<<(std::ostream& out, Money const& money);
		friend std::istream& operator>>(std::istream& in, Money& money);
		const Money operator+(const Money& rhs);
		const Money operator-(const Money& rhs);
		Money operator=(const Money& rhs);
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
		void operator+=(const Money& rhs);
		void operator-=(const Money& rhs);
	};
}
 #endif
