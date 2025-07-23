#include "bigint.hpp"



Bigint::Bigint() : _string("0") {}
Bigint::Bigint(unsigned int n) {
    std::ostringstream oss;
    oss << n;
    _string = oss.str();
}

Bigint::Bigint(const Bigint& original) : _string(original._string) {}
Bigint::~Bigint() {}

std::string Bigint::getValue() const {return _string;}

bool Bigint::operator==(const Bigint& other) const {
    return this->_string == other._string;
}

bool Bigint::operator!=(const Bigint& other) const {
    return this->_string != other._string;
}

std::ostream& operator<<(std::ostream& os, const Bigint& bigint) {
    std::string value = bigint.getValue();
    size_t first_non_zero = value.find_first_not_of('0');
    if (first_non_zero == std::string::npos)
        os << "0";
    else
        os << value.substr(first_non_zero);
    return os;
}

bool Bigint::operator<(const Bigint& other) const {
    if (this->_string.length() != other._string.length())
        return this->_string.length() < other._string.length();
    return this->_string < other._string;
}

bool Bigint::operator>(const Bigint& other) const {
    if (this->_string.length() != other._string.length())
        return this->_string.length() > other._string.length();
    return this->_string > other._string;
}

bool Bigint::operator<=(const Bigint& other) const {
    return !(*this > other);
}

bool Bigint::operator>=(const Bigint& other) const {
    return !(*this < other);
}

Bigint& Bigint::operator++() {
    *this = *this + Bigint(1);
    return *this;
}
