#include "bigint.hpp"

Bigint::Bigint() : _string("0") {};
Bigint::Bigint(unsigned int n) {

};
Bigint::Bigint(const Bigint& orginal) : _string(orginal._string) {};
Bigint::~Bigint() {};

std::string Bigint::getValue() {return _string;};
std::ostream& operator<<(std::ostream os, const Bigint& bigint) {

};

bool Bigint::operator==(const Bigint& other) const;
bool Bigint::operator!=(const Bigint& other) const;
bool Bigint::operator<(const Bigint& other) const;
bool Bigint::operator>(const Bigint& other) const;
bool Bigint::operator<=(const Bigint& other) const;
bool Bigint::operator>=(const Bigint& other) const;

Bigint Bigint::operator<<(unsigned int value) const;
Bigint Bigint::operator>>(unsigned int value) const;
Bigint Bigint::operator>>=(unsigned int value);
Bigint Bigint::operator<<=(unsigned int value);

Bigint& Bigint::operator<<(const Bigint& other) const;
Bigint& Bigint::operator>>(const Bigint& other) const;
Bigint& Bigint::operator<<=(const Bigint& other);
Bigint& Bigint::operator>>=(const Bigint& other);
