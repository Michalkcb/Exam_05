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

Bigint Bigint::operator<<(unsigned int value) const {
    Bigint result(*this);
    result._string.append(value, '0');
    return result;
}

Bigint& Bigint::operator<<=(unsigned int value) {
    this->_string.append(value, '0');
    return *this;
}

Bigint& Bigint::operator>>=(unsigned int value) {
    if (value >= this->_string.length()) {
        this->_string = "0";
    } else {
        this->_string.erase(this->_string.length() - value);
    }
    return *this;
}

Bigint Bigint::operator+(const Bigint& other) const {
    std::string a = this->_string;
    std::string b = other._string;

    if ( a.length() < b.length() ) {
        std::swap(a, b);
    }
    b.insert(0, a.length() - b.length(), '0'); // Pad with leading zeros
    std::string result ="";
    int carry = 0;
    for (int i = a.length() - 1; i >= 0; --i) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        result.insert(result.begin(), (sum % 10) + '0');
        carry = sum / 10;
    }
    if (carry > 0) {
        result.insert(result.begin(), carry + '0');
    }
    return Bigint(result);
}

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
