#include <iostream>

#include "Complex.hpp"
#include "Rational.hpp"
#include "Polynomial.hpp"
#include "Field.hpp"

using namespace sbl;

int main() {
    rational r{ 2, 4 };

    std::cout << r << std::endl;

    basic_complex<rational> c1{ 3, 2 };

    std::cout << c1 << std::endl;

    basic_complex<rational> c2{ 10, 6 };

    std::cout << c1 << "+" << c2 << "=" << (c1 + c2) << std::endl;
    std::cout << c1 << "-" << c2 << "=" << (c1 - c2) << std::endl;

    std::cout << c1 << "+5=" << (c1 + 5) << std::endl;
    std::cout << c1 << "*5=" << (c1 * 5) << std::endl;

    std::cout << c1 << "*" << c2 << "=" << (c1 * c2) << std::endl;
    std::cout << c1 << "/" << c2 << "=" << (c1 / c2) << std::endl;

    basic_complex<rational> c3{ rational{ 1,2 }, rational{ 1, 3 } };
    std::cout << c3 << std::endl;

    basic_rational<rational> emeletestort{ rational{1,2}, rational{1,4} };
    std::cout << emeletestort << std::endl;

    basic_polynomial<rational> p;
    p.setValue(6, 15);
    p.setValue(2, 6);

    std::cout << p << std::endl;
    std::cout << p(5) << std::endl;
    std::cout << ((2 * p) - p) << std::endl;
    std::cout << (p * p) << std::endl;
    std::cout << ((p * p) / p) << std::endl;

    basic_field<7> z7 = 1;
    std::cout << z7 << std::endl;
    z7 = z7 + 11;
    std::cout << z7 << std::endl;

    std::cin.ignore('\n');
}