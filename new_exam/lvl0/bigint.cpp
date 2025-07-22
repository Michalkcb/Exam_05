#include "bigint.hpp"
#include <algorithm>
#include <stdexcept>
#include <sstream>

// Konstruktor domyślny
Bigint::Bigint() : _string("0") {}

// Konstruktor z wartością liczbową
Bigint::Bigint(unsigned int n) {
    std::ostringstream oss;
    oss << n;
    _string = oss.str();
}


Bigint::Bigint(const Bigint& original) : _string(original._string) {}
