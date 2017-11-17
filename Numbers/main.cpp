#include <iostream>

#include "Complex.hpp"

int main() {
	basic_complex<racional> c1(3, 2);
	basic_complex<racional> c2(10, 6);

	std::cout << "(" << c1 << ")+(" << c2 << ")=(" << (c1 + c2) << ")" << std::endl;
	std::cout << "(" << c1 << ")-(" << c2 << ")=(" << (c1 - c2) << ")" << std::endl;
	std::cout << "(" << c1 << ")*(" << c2 << ")=(" << (c1 * c2) << ")" << std::endl;
	std::cout << "(" << c1 << ")/(" << c2 << ")=(" << (c1 / c2) << ")" << std::endl;
	std::cout << "(" << c1 << ")*5=(" << (c1 * 5) << ")" << std::endl;

	racional r(2, 0);

	std::cout << r << std::endl;

	std::cin.ignore('\n');
}