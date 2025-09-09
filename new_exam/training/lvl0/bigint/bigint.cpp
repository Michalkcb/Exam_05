#include "bigint.hpp"

	Bigint::Bigint() : _string("0") {};
	Bigint::Bigint(const Bigint& orginal) : _string(orginal._string) {};
	Bigint::Bigint(unsigned int n) {
		std::ostringstream oss;
		oss << n;
		_string = oss.str();
	};
	Bigint::~Bigint() {};

	std::string Bigint::getValue() const {
		return _string;
	}

	bool Bigint::operator==(const Bigint& other) const {
		return this->_string == other._string;
	};
	bool Bigint::operator!=(const Bigint& other) const {
		return this->_string != other._string;
	};