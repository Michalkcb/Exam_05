#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <math.h>
// #include <stdexcept>

class Bigint {
	private:
		std::string _string;

	public:
		Bigint();
		Bigint(const Bigint& orginal);
		Bigint& operator=(const Bigint &orginal);
		~Bigint();

		Bigint(unsigned int n);
		Bigint(const std::string& str) : _string(str){}
		std::string getValue() const;

		bool operator==(const Bigint &other) const;
		bool operator!=(const Bigint &other) const;
		bool operator<=(const Bigint &other) const;
		bool operator>=(const Bigint &other) const;
		bool operator>(const Bigint &other) const;
		bool operator<(const Bigint &other) const;

		Bigint operator+(const Bigint &other) const;
		Bigint operator++(int) ;
		Bigint operator<<(unsigned int value) const;

		Bigint& operator<<=(unsigned int value);
		Bigint& operator>>=(unsigned int value);
		Bigint& operator+=(const Bigint &other);
		Bigint& operator++();

    friend std::ostream& operator<<(std::ostream& os, const Bigint& bigint);
};