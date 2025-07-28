#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stdexcept>
#include <math.h>

class Bigint {
	private:
		std::string _string;
	public:
		Bigint();
		~Bigint();
		Bigint(unsigned int n);
		Bigint(const std::string str) : _string(str) {}
		Bigint(const Bigint& orginal);

		std::string getValue() const;

		bool operator==(const Bigint& other) const;	
		bool operator!=(const Bigint& other) const;	

		bool operator>=(const Bigint& other) const;	
		bool operator<=(const Bigint& other) const;	
		bool operator>(const Bigint& other) const;	
		bool operator<(const Bigint& other) const;	

		Bigint operator+(const Bigint& other) const;	
		Bigint operator++(int) ;	
		Bigint operator<<(unsigned int value) const;	

		Bigint& operator+=(const Bigint& other);	
		Bigint& operator++();	
		Bigint& operator<<=(unsigned int value);	
		Bigint& operator>>=(unsigned int value);	

		friend std::ostream& operator<<(std::ostream& os, const Bigint& Bigint);
};