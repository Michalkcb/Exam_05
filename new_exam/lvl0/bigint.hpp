#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <math.h>
#include <stdexcept>

class Bigint {
	private:
		std::string _string;
	public:
		Bigint();
		~Bigint();
		Bigint(const Bigint& orginal);
		
		Bigint(unsigned int n);
		Bigint(const std::string& std) : _string(std) {};

		std::string getValue();

		bool operator==(const Bigint& other);
		bool operator!=(const Bigint& other);
		bool operator<=(const Bigint& other);
		bool operator>=(const Bigint& other);
		bool operator<(const Bigint& other);
		bool operator>(const Bigint& other);

		Bigint operator+(const Bigint& other) const;
		Bigint operator++(int);
		Bigint operator<<(unsigned int value) const;





};