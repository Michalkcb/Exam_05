/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:16:59 by mbany             #+#    #+#             */
/*   Updated: 2025/09/20 15:41:39 by mbany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.hpp"

Bigint::Bigint() : _string("0") {};
Bigint::Bigint(unsigned int n) {
	std::ostringstream oss;
	oss << n;
	_string = oss.str();
};
Bigint::Bigint(const Bigint& orginal) : _string(orginal._string) {};
Bigint::~Bigint() {};

std::string Bigint::getValue() const {return _string;};
std::ostream& operator<<(std::ostream& os, const Bigint& bigint) {
	std::string value = bigint.getValue();
	size_t first_non_zero = value.find_first_not_of('0');
	if (first_non_zero == std::string::npos)
		os << "0";
	else 
		os << value.substr(first_non_zero);
	return os;
};

bool Bigint::operator==(const Bigint& other) const {
	return this->_string == other._string;
};
bool Bigint::operator!=(const Bigint& other) const {
	return this->_string != other._string;
};
bool Bigint::operator<(const Bigint& other) const {
	if (this->_string.length() != other._string.length())
		return this->_string.length() < other._string.length();
	return this->_string < other._string;
};
bool Bigint::operator>(const Bigint& other) const {
	return other < *this;
};
bool Bigint::operator>=(const Bigint& other) const {
	return !(*this < other);
};
bool Bigint::operator<=(const Bigint& other) const {
	return !(*this > other);
};

Bigint Bigint::operator<<(unsigned int value) const {
	Bigint result(*this);
	result._string.append(value, '0');
	return result;
};
Bigint Bigint::operator>>(unsigned int value) const {
	if (value >= this->_string.length())
		return Bigint(0);
	std::string result = _string.substr(0, _string.length() - value);
	return Bigint(result);
};
Bigint& Bigint::operator<<=(unsigned int value) {
	*this = *this << value;
	return *this;
};
Bigint& Bigint::operator>>=(unsigned int value) {
	*this = *this >> value;
	return *this;
};


Bigint Bigint::operator<<(const Bigint& other) const {
	unsigned int shift = std::stoi(other.getValue());
	return *this << shift;
};
Bigint Bigint::operator>>(const Bigint& other) const {
	unsigned int shift = std::stoi(other.getValue());
	return *this >> shift;
};
Bigint& Bigint::operator<<=(const Bigint& other) {
	unsigned int shift = std::stoi(other.getValue());
	return *this <<= shift;
};
Bigint& Bigint::operator>>=(const Bigint& other) {
	unsigned int shift = std::stoi(other.getValue());
	return *this >>= shift;
};

Bigint Bigint::operator+(const Bigint& other) const {
	std::string a = this->_string;
	std::string b = other._string;

	std::string result = "";
	int carry = 0;

	int i = a.length() - 1;
	int j = b.length() - 1;

	while ( i >= 0 || j >= 0 || carry > 0) {
		int sum = carry;

		if (i >= 0)
			sum += a[i--] -'0';
		if (j >= 0)
			sum += b[j--] -'0';
		result.push_back((sum % 10) + '0');
		carry = sum / 10;
	}
	std::reverse(result.begin(), result.end());
	return Bigint(result);
};
Bigint& Bigint::operator+=(const Bigint& other) {
	*this = *this + other;
	return *this;
};
Bigint Bigint::operator++(int) {
	Bigint temp = *this;
	++(*this);
	return temp;
};
Bigint& Bigint::operator++() {
	*this = *this + Bigint(1);
	return *this;
};