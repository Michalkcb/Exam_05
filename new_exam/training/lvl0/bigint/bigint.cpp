#include "bigint.hpp"

Bigint::Bigint() {};
Bigint::Bigint(unsigned int n);
Bigint::Bigint(const Bigint& orginal);
Bigint::~Bigint() {};

std::string Bigint::getValue() const;
std::ostream& operator<<(std::ostream& os, const Bigint& bigint);

bool Bigint::operator==(const Bigint& other) const;
bool Bigint::operator!=(const Bigint& other) const;
bool Bigint::operator<(const Bigint& other) const;
bool Bigint::operator>(const Bigint& other) const;
bool Bigint::operator>=(const Bigint& other) const;
bool Bigint::operator<=(const Bigint& other) const;

Bigint Bigint::operator<<(unsigned int value) const;
Bigint Bigint::operator>>(unsigned int value) const;
Bigint& Bigint::operator<<=(unsigned int value) ;
Bigint& Bigint::operator>>=(unsigned int value) ;


Bigint Bigint::operator<<(const Bigint& other) const;
Bigint Bigint::operator>>(const Bigint& other) const;
Bigint& Bigint::operator<<=(const Bigint& other) ;
Bigint& Bigint::operator>>=(const Bigint& other) ;

Bigint Bigint::operator+(const Bigint& other) const;
Bigint& Bigint::operator++() {
    *this = *this + Bigint(1);
    return *this;
}

Bigint Bigint::operator++(int) {
    Bigint  temp = *this;
    ++(*this);
    return temp;
}

Bigint& Bigint::operator+=(const Bigint& other) {
    *this = *this + other;
    return *this;
}