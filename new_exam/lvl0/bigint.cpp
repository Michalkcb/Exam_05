#include "bigint.hpp"
#include <algorithm>
#include <stdexcept>

// Konstruktor domyślny
Bigint::Bigint() : value("0") {}

// Konstruktor z wartością liczbową
Bigint::Bigint(unsigned long long num) {
    std::ostringstream oss;
    oss << num;
    value = oss.str();
}

// Konstruktor kopiujący
Bigint::Bigint(const Bigint& other) : value(other.value) {}

// Konstruktor z ciągiem znaków
Bigint::Bigint(const std::string& str) : value(str) {
    // Usuwamy wiodące zera, jeśli istnieją
    value.erase(0, value.find_first_not_of('0'));
    if (value.empty()) {
        value = "0"; // Jeśli wszystkie cyfry to zera, ustawiamy wartość na "0"
    }
}

// Operator przypisania
Bigint& Bigint::operator=(const Bigint& other) {
    if (this != &other) {
        value = other.value;
    }
    return *this;
}

// Dodawanie
Bigint Bigint::operator+(const Bigint& other) const {
    std::string result;
    std::string a = value, b = other.value;
    int carry = 0;

    // Upewniamy się, że `a` jest dłuższe
    if (a.size() < b.size()) std::swap(a, b);

    // Dodawanie od końca
    int diff = a.size() - b.size();
    for (int i = b.size() - 1; i >= 0; --i) {
        int sum = (a[i + diff] - '0') + (b[i] - '0') + carry;
        carry = sum / 10;
        result.push_back((sum % 10) + '0');
    }

    // Dodajemy pozostałe cyfry z `a`
    for (int i = diff - 1; i >= 0; --i) {
        int sum = (a[i] - '0') + carry;
        carry = sum / 10;
        result.push_back((sum % 10) + '0');
    }

    // Jeśli pozostał przeniesienie
    if (carry) result.push_back(carry + '0');

    std::reverse(result.begin(), result.end());
    return Bigint(result); // Konstruktor Bigint(const std::string&) jest używany tutaj
}

Bigint& Bigint::operator+=(const Bigint& other) {
    *this = *this + other;
    return *this;
}

// Przesunięcie cyfr w lewo
Bigint Bigint::operator<<(int shift) const {
    if (shift < 0) {
        throw std::invalid_argument("Shift count must be non-negative");
    }
    Bigint result = *this;
    for (int i = 0; i < shift; ++i) {
        result.value.push_back('0');
    }
    return result;
}

Bigint& Bigint::operator<<=(int shift) {
    if (shift < 0) {
        throw std::invalid_argument("Shift count must be non-negative");
    }
    for (int i = 0; i < shift; ++i) {
        value.push_back('0');
    }
    return *this;
}

// Przesunięcie cyfr w prawo
Bigint Bigint::operator>>(int shift) const {
    if (shift < 0) {
        throw std::invalid_argument("Shift count must be non-negative");
    }
    Bigint result = *this;
    if (shift >= result.value.size()) {
        result.value = "0";
    } else {
        result.value = result.value.substr(0, result.value.size() - shift);
    }
    return result;
}

Bigint& Bigint::operator>>=(int shift) {
    if (shift < 0) {
        throw std::invalid_argument("Shift count must be non-negative");
    }
    if (shift >= value.size()) {
        value = "0";
    } else {
        value = value.substr(0, value.size() - shift);
    }
    return *this;
}

// Operatory porównania
bool Bigint::operator<(const Bigint& other) const {
    if (value.size() != other.value.size()) {
        return value.size() < other.value.size();
    }
    return value < other.value;
}

bool Bigint::operator>(const Bigint& other) const {
    return other < *this;
}

bool Bigint::operator<=(const Bigint& other) const {
    return !(other < *this);
}

bool Bigint::operator>=(const Bigint& other) const {
    return !(*this < other);
}

bool Bigint::operator==(const Bigint& other) const {
    return value == other.value;
}

bool Bigint::operator!=(const Bigint& other) const {
    return !(*this == other);
}

// Operator wypisywania
std::ostream& operator<<(std::ostream& os, const Bigint& bigint) {
    os << bigint.value;
    return os;
}