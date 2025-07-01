#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <string>
#include <iostream>
#include <vector>

class Bigint {
private:
    std::string value; // Przechowuje liczbę jako string
public:
    Bigint(); // Konstruktor domyślny
    Bigint(unsigned long long num); // Konstruktor z wartością liczbową
    Bigint(const Bigint& other); // Konstruktor kopiujący
    Bigint(const std::string& str); // Konstruktor z ciągiem znaków
    Bigint(int num); // Konstruktor z wartością typu int
    Bigint(const char* str); // Konstruktor z ciągiem znaków typu const char*

    // Operator przypisania
    Bigint& operator=(const Bigint& other);

    // Operatory arytmetyczne
    Bigint operator+(const Bigint& other) const;
    Bigint& operator+=(const Bigint& other);

    // Operatory przesunięcia cyfr
    Bigint operator<<(int shift) const;
    Bigint& operator<<=(int shift);
    Bigint operator>>(int shift) const;
    Bigint& operator>>=(int shift);

    // Operatory porównania
    bool operator<(const Bigint& other) const;
    bool operator>(const Bigint& other) const;
    bool operator<=(const Bigint& other) const;
    bool operator>=(const Bigint& other) const;
    bool operator==(const Bigint& other) const;
    bool operator!=(const Bigint& other) const;

    // Operator wypisywania
    friend std::ostream& operator<<(std::ostream& os, const Bigint& bigint);
};

#endif