/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:16:41 by mbany             #+#    #+#             */
/*   Updated: 2025/09/16 19:34:01 by mbany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assigment: bogint
Files: bigint.cpp, bigint.hpp

In computer science a bignum is an object presenting an abstrary precision number. This is usefulll when you wanted to store a number bigger than SIZE_MAX without any loss of precision. This is often achieved by storing the number as an arry or a string containing its differnt "parts".
Create a class called Bigint that will store an arbitrary precision unsigned integer.

Your class must support addition, comparision, and "digitshift" (similar to bitshift, but instead of shifting bits, you will shift the digits in base 10, e.g. (42<<3==42000) and (1337 >>2 == 13))

Your bigint must be priintable with the operator <<(in base 10), ant the output should not contain any leading zeros.
You will find a main in this directory that must work with your class.
*/

#include "bigint.hpp"

int main() {
	const Bigint a(42);
	Bigint b(21), c, d(1337), e(d);

	// // base test
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "e = " << e << std::endl;

	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "a + c = " << a + c << std::endl;
	std::cout << "(c += a) = " << (c += a) << std::endl;

	std::cout << "b = " << b << std::endl;
	std::cout << "++b = " << ++b << std::endl;
	std::cout << "b++ = " << b++ << std::endl;

	// b = 23, b << 10 -> 23000000000 + 42 = 23000000042
	std::cout << "(b << 10) + 42 = " << ((b << 10) + 42) << std::endl;
	std::cout << "(b << 3) = " << (b << 3) << std::endl;
	std::cout << "(b >> 10) = " << (b >> 1) << std::endl;
	std::cout << "(d <<= 4) = " << (d <<= 4) << ", d: " << d << std::endl;
	std::cout << "(d >>= 2) = " << (d >>= (const Bigint)2) << ", d: " << d << std::endl;

	std::cout << "a = " << a << std::endl; // a = 42
	std::cout << "d = " << d << std::endl; // d = 5348

	std::cout << "(d < a) = " << (d < a) << std::endl; // (d < a) = 0
	std::cout << "(d > a) = " << (d > a) << std::endl; // (d > a) = 1
	std::cout << "(d == d) = " << (d == d) << std::endl; // (d == d) = 1
	std::cout << "(b == d) = " << (b == d) << std::endl; // (d == d) = 1
	std::cout << "(d != a) = " << (d != a) << std::endl; // (d != a) = 1
	std::cout << "(d <= a) = " << (d <= a) << std::endl; // (d <= a) = 0
	std::cout << "(d >= a) = " << (d >= a) << std::endl; // (d >= a) = 1

	// // extra
	Bigint x(12345678); Bigint y(5);
	std::cout << "(x << y) = " << (x << y) << ", x: " << x << ", y: " << y << std::endl;
	std::cout << "(x >>= y) = " << (x >>= y) << ", x: " << x << ", y: " << y << std::endl;
	std::cout << "(x >= y) = " << (x >= y) << ", x: " << x << ", y: " << y << std::endl;

	std::cout << "x= " << (x <<= 5) << ", y= " << (y <<= 12) << std::endl;
	std::cout << "(x >= y) = " << (x >= y) << ", x: " << x << ", y: " << y << std::endl;

	return (0);
	}