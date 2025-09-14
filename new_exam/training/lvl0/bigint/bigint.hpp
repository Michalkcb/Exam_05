/*
1. Zacznij od prostych operatorów:
Konstruktory
operator==, operator!=
getValue()
Operator wypisywania
2. Potem porównania:
operator<, operator>
operator<=, operator>=
3. Następnie shift (kluczowe dla zadania):
operator<<(unsigned int)
operator>>(unsigned int)
Wersje z przypisaniem (<<=, >>=)
4. Na końcu dodawanie:
operator+
operator+=
operator++
*/

#pragma once
#include <string>
#include <iostream>
#include <sstream>

class Bigint {
	private:
		std::string _string;
	public:
		Bigint();
		Bigint(unsigned int n);
		Bigint(const Bigint& orginal);
		~Bigint();
		Bigint(const std::string str) : _string(str) {};

		std::string getValue() const;

		friend std::ostream& operator<<(std::ostream& os, const Bigint& bigint);

		bool operator==(const Bigint& other) const;
		bool operator!=(const Bigint& other) const;
		bool operator<(const Bigint& other) const;
		bool operator>(const Bigint& other) const;
		bool operator<=(const Bigint& other) const;
		bool operator>=(const Bigint& other) const;

		Bigint operator<<(unsigned int value) const;
		Bigint operator>>(unsigned int value) const;
		Bigint& operator>>=(unsigned int value);
		Bigint& operator<<=(unsigned int value);

		Bigint operator<<(const Bigint& other) const;
		Bigint operator>>(const Bigint& other) const;
		Bigint& operator<<=(const Bigint& other);
		Bigint& operator>>=(const Bigint& other);

		//operatory +
};