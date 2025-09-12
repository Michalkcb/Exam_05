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
		Bigint(const std::string str) : _string(str) {};
		~Bigint();

		bool operator==(const Bigint& other) const;
		bool operator!=(const Bigint& other) const;

		std::string getValue() const;
};