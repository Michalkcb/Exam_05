 #pragma once
 #include <string>
 #include <ostream>
 #include <sstream>
 #include <iostream>
 #include <algorithm>

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

		Bigint operator<<(const Bigint& other) const;
		Bigint operator>>(const Bigint& other) const;
		Bigint& operator<<=(const Bigint& other);
		Bigint& operator>>=(const Bigint& other);

		Bigint operator<<(unsigned int value) const;
		Bigint operator>>(unsigned int value) const;
		Bigint& operator<<=(unsigned int value);
		Bigint& operator>>=(unsigned int value);

		Bigint operator+(const Bigint& other) const;
		Bigint& operator+=(const Bigint& other);
		Bigint operator++(int);
		Bigint& operator++();
 };