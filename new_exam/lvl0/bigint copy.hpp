/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint copy.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:16:50 by mbany             #+#    #+#             */
/*   Updated: 2025/07/27 14:42:34 by mbany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <sstream>
#include <math.h>

class Bigint {
private:
    std::string _string;

public:
    Bigint(); // Domyślny konstruktor
    Bigint(unsigned int n); // Konstruktor z unsigned int
    Bigint(const Bigint& original); // Konstruktor kopiujący
    ~Bigint(); // Destruktor
    Bigint(const std::string& str) : _string(str) {} // Konstruktor z stringa

    std::string getValue() const; // Metoda zwracająca wartość jako string

    // Operatory porównania
    Bigint operator+(const Bigint& other) const; // Operator dodawania
    Bigint operator++(int); // Operator inkrementacji (postfix)
    Bigint operator<<(unsigned int value) const; // Operator przesunięcia w lewo
   
    Bigint& operator+=(const Bigint& other); // Operator dodawania z przypisaniem
    Bigint& operator++(); // Operator inkrementacji (prefix)
    Bigint& operator<<=(unsigned int value); // Operator przesunięcia w lewo z przypisaniem
    Bigint& operator>>=(unsigned int value); // Operator przesunięcia w prawo z przypisaniem

    bool operator==(const Bigint& other) const;
    bool operator!=(const Bigint& other) const;
    bool operator<(const Bigint& other) const;
    bool operator>(const Bigint& other) const;
    bool operator<=(const Bigint& other) const;
    bool operator>=(const Bigint& other) const;

    // Operator wypisywania
    friend std::ostream& operator<<(std::ostream& os, const Bigint& bigint);
};

#endif