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
    if (this->_string == other._string)
        return true;
    return false;
}

bool Bigint::operator!=(const Bigint& other) const {
    if (this->_string != other._string)
        return true;
    return false;
}