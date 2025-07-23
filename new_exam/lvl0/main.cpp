
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

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "e = " << e << std::endl;
	// std::cout << "a + b = " << a + b << std::endl;
	// std::cout << "(c += a)= " << (c += a) << std::endl;
	std::cout << "b = " << b << std::endl;
	// std::cout << "++b " << ++b << std::endl;
	// std::cout << "b++ " << b++ << std::endl;
	// std::cout << "(b << 10) + 42 = " << (b << 10) + 42 << std::endl;
	std::cout << "(d <<=4 ) = " << (d <<= 4) << std::endl;
	// std::cout << "(d >>= 2) = " << (d >>= 2) << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "(d < a) = " << (d < a) << std::endl;
	std::cout << "(d > a) = " << (d > a) << std::endl;
	std::cout << "(d == a) = " << (d == a) << std::endl;
	std::cout << "(d != a) = " << (d != a) << std::endl;
	std::cout << "(d <= a) = " << (d <= a) << std::endl;
	std::cout << "(d >= a) = " << (d >= a) << std::endl;
	std::cout << "() = " << (d >= a) << std::endl;

	std::cout << "(b << 10)= " << (b << 5) << std::endl;

	}