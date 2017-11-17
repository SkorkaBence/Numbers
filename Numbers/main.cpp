#include <iostream>

#include "Complex.h"

int main() {
	basic_complex<racional> c1(3, 2);
	basic_complex<racional> c2(10, 6);

	std::cout << "(" << c1 << ")+(" << c2 << ")=(" << (c1 + c2) << ")" << std::endl;
	std::cout << "(" << c1 << ")-(" << c2 << ")=(" << (c1 - c2) << ")" << std::endl;
	std::cout << "(" << c1 << ")*(" << c2 << ")=(" << (c1 * c2) << ")" << std::endl;
	std::cout << "(" << c1 << ")/(" << c2 << ")=(" << (c1 / c2) << ")" << std::endl;

	std::cin.ignore('\n');
}