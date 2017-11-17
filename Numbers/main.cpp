#include <iostream>

#include "Complex.hpp"
#include "Rational.hpp"

int main() {
	rational r(2, 4);

	std::cout << r << std::endl;

	basic_complex<rational> c1(3, 2);

	std::cout << c1 << std::endl;

	basic_complex<rational> c2(10, 6);

	std::cout << c1 << "+" << c2 << "=" << (c1 + c2) << std::endl;
	std::cout << c1 << "-" << c2 << "=" << (c1 - c2) << std::endl;

	std::cout << c1 << "+5=" << (c1 + 5) << std::endl;
	std::cout << c1 << "*5=" << (c1 * 5) << std::endl;

	std::cout << c1 << "*" << c2 << "=" << (c1 * c2) << std::endl;
	std::cout << c1 << "/" << c2 << "=" << (c1 / c2) << std::endl;

	std::cin.ignore('\n');
}