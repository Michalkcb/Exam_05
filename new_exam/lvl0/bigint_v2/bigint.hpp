/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:17:26 by fatkeski          #+#    #+#             */
/*   Updated: 2025/09/30 14:35:53 by mbany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include <ostream>
#include <sstream>
#include <algorithm>

class bigint {
	private:
		std::string _string;
	public:
		bigint() : _string("0") {};
		bigint(unsigned int n) {
			std::ostringstream oss;
			oss << n;
			_string = oss.str();
		};
		bigint(const bigint& orginal) : _string(orginal._string) {};
		~bigint() {};
		bigint(std::string std) : _string(std) {};

		std::string getValue() const {return _string;};
		friend std::ostream& operator<<(std::ostream& os, const bigint& bigint) {
			std::string value = bigint.getValue();
			size_t first_non_zero = value.find_first_not_of('0');
			if (first_non_zero == std::string::npos)
				os << "0";
			else
				os << value.substr(first_non_zero);
			return os;
		};

		bool operator==(const bigint& other) const {
			return this->_string == other._string;
		};
		bool operator!=(const bigint& other) const {
			return this->_string != other._string;
		};
		bool operator<(const bigint& other) const {
			if (this->_string.length() != other._string.length())
				return (this->_string.length() < other._string.length());
			return (this->_string < other._string);
		};
		bool operator>(const bigint& other) const {
			return other < *this;
		};
		bool operator>=(const bigint& other) const {
			return !(*this < other);
		};
		bool operator<=(const bigint& other) const {
			return !(*this > other);
		};
		bigint operator<<(unsigned int value) const {
			bigint result(*this);
			result._string.append(value, '0');
			return result;
		};
		bigint operator>>(unsigned int value) const {
			if (value >= this->_string.length())
				return bigint(0);
			std::string result = _string.substr(0, _string.length() - value);
			return bigint(result);
		};
		bigint& operator<<=(unsigned int value) {
			*this = *this << value;
			return *this;
		};
		bigint& operator>>=(unsigned int value) {
			*this = *this >> value;
			return *this;
		};
		bigint operator<<(const bigint& other) const {
			unsigned int shift = std::stoi(other.getValue());
			return *this << shift;
		};
		bigint operator>>(const bigint& other) const {
			unsigned int shift = std::stoi(other.getValue());
			return *this >> shift;
		};
		bigint& operator<<=(const bigint& other) {
			unsigned int shift = std::stoi(other.getValue());
			return *this <<= shift;
		};
		bigint& operator>>=(const bigint& other) {
			unsigned int shift = std::stoi(other.getValue());
			return *this >>= shift;
		};


		bigint operator+(const bigint& other) const {
			std::string a = this->_string;
			std::string b= other._string;

			std::string result = "";
			int carry = 0;
			
			int i = a.length() -1;
			int j = b.length() -1;

			while (i >= 0 || j >= 0 || carry > 0) {
				int sum = carry;
				if (i >= 0)
					sum += a[i--] -'0';
				if (j >= 0)
					sum += b[j--] -'0';
				result.push_back((sum % 10) + '0');
				carry = sum / 10;
			}
			std::reverse(result.begin(), result.end());
			return bigint(result);
		};
		bigint& operator+=(const bigint& other) {
			*this = *this + other;
			return *this;
		};
		bigint operator++(int) {
			bigint tmp = *this;
			++(*this);
			return tmp;
		};
		bigint& operator++() {
			*this = *this + bigint(1);
			return *this;
		};
};