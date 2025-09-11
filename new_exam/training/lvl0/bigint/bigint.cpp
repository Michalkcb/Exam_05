#include "bigint.hpp"

	Bigint::Bigint() : _string("0") {};
	Bigint::Bigint(unsigned int n) {
		std::ostringstream oss;
		oss << n;
		_string = oss.str();
	};
	Bigint::Bigint(const Bigint& orginal) : _string(orginal._string){};
	Bigint::~Bigint() {};

	bool Bigint::operator==(const Bigint& other) const {
		return this->_string == other._string;
	};
	bool Bigint::operator!=(const Bigint& other) const {
		return this->_string != other._string;
	};

	std::string Bigint::getValue() const {return _string;}


	std::ostream& operator<<(std::ostream& os, const Bigint& bigint) {
		std::string value = bigint.getValue();
		size_t first_non_zero = value.find_first_not_of("0");
		if (first_non_zero == std::string::npos)
			os << "0";
		else
			os << value.substr(first_non_zero);
		return os;
	};

