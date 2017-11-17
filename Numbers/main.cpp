#include <iostream>

#include "Complex.hpp"
#include "Racional.hpp"

int main() {
	racional r(2, 4);

	std::cout << r << std::endl;

	basic_complex<racional> c1(3, 2);

	std::cout << c1 << std::endl;

	basic_complex<racional> c2(10, 6);

	std::cout << c1 << "+" << c2 << "=" << (c1 + c2) << std::endl;
	std::cout << c1 << "-" << c2 << "=" << (c1 - c2) << std::endl;

	std::cout << c1 << "+5=" << (c1 + 5) << std::endl;
	std::cout << c1 << "*5=" << (c1 * 5) << std::endl;

	std::cout << c1 << "*" << c2 << "=" << (c1 * c2) << std::endl;
	std::cout << c1 << "/" << c2 << "=" << (c1 / c2) << std::endl;

	std::cin.ignore('\n');
}