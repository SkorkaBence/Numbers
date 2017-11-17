#pragma once

#include <iostream>

template<typename T>
class basic_racional {
private:

	T numerator;
	T denominator;

	T abs(T a) {
		if (a >= 0) {
			return a;
		} else {
			return -1 * a;
		}
	}

	T GreatestCommonDivisor(T a, T b) {
		a = abs(a);
		b = abs(b);
		while (a != b) {
			if (a > b) {
				a -= b;
			} else {
				b -= a;
			}
		}
		return a;
	}

	void Simplification() {
		if (denominator < 0) {
			numerator *= -1;
			denominator *= -1;
		}

		T div = GreatestCommonDivisor(numerator, denominator);
		numerator /= div;
		denominator /= div;
	}

public:

	basic_racional() : numerator(0), denominator(1) {}
	basic_racional(T n) : numerator(n), denominator(1) {}
	basic_racional(T n, T d) : numerator(n), denominator(d) {
		Simplification();
	}
	basic_racional(const basic_racional<T>& r) : numerator(r.numerator), denominator(r.denominator) {}

	~basic_racional() {}

	friend std::ostream& operator << (std::ostream& out, const basic_racional<T>& dt) {
		if (dt.denominator == 1) {
			out << dt.numerator;
		} else {
			out << dt.numerator << "/" << dt.denominator;
		}
		return out;
	}

	basic_racional& operator += (const basic_racional<T>& ot) {
		numerator = numerator * ot.denominator + ot.numerator * denominator;
		denominator *= ot.denominator;
		Simplification();
		return *this;
	}

	basic_racional operator + (const basic_racional<T>& ot) const {
		basic_racional<T> r(numerator, denominator);
		r += ot;
		return r;
	}

	basic_racional& operator -= (const basic_racional<T>& ot) {
		numerator = numerator * ot.denominator - ot.numerator * denominator;
		denominator *= ot.denominator;
		Simplification();
		return *this;
	}

	basic_racional operator - (const basic_racional<T>& ot) const {
		basic_racional<T> r(numerator, denominator);
		r -= ot;
		return r;
	}

	basic_racional& operator *= (const basic_racional<T>& ot) {
		numerator *= ot.numerator;
		denominator *= ot.denominator;
		Simplification();
		return *this;
	}

	basic_racional operator * (const basic_racional<T>& ot) const {
		basic_racional<T> r(numerator, denominator);
		r *= ot;
		return r;
	}

	basic_racional& operator /= (const basic_racional<T>& ot) {
		numerator *= ot.denominator;
		denominator *= ot.numerator;
		Simplification();
		return *this;
	}

	basic_racional operator / (const basic_racional<T>& ot) const {
		basic_racional<T> r(numerator, denominator);
		r /= ot;
		return r;
	}

	basic_racional& operator = (const basic_racional<T>& ot) {
		numerator = ot.numerator;
		denominator = ot.denominator;
		return *this;
	}

	// rac <-> rac ----------------------------------------------------------------

	bool operator < (const basic_racional<T>& ot) const {
		return (numerator * ot.denominator) < (ot.numerator * denominator);
	}

	bool operator > (const basic_racional<T>& ot) const {
		return ot < *this;
	}

	bool operator <= (const basic_racional<T>& ot) const {
		return !(*this > ot);
	}

	bool operator >= (const basic_racional<T>& ot) const {
		return !(*this < ot);
	}

	bool operator == (const basic_racional<T>& ot) const {
		return (*this <= ot) && (*this >= ot);
	}

	bool operator != (const basic_racional<T>& ot) const {
		return (*this < ot) || (*this > ot);
	}

	// rac <-> T ----------------------------------------------------------------

	bool operator < (T ot) const {
		basic_racional<T> r(ot);
		return *this < r;
	}

	bool operator > (T ot) const {
		basic_racional<T> r(ot);
		return r < *this;
	}

	bool operator <= (T ot) const {
		return !(*this > ot);
	}

	bool operator >= (T ot) const {
		return !(*this < ot);
	}

	bool operator == (T ot) const {
		return (*this <= ot) && (*this >= ot);
	}

	bool operator != (T ot) const {
		return (*this < ot) || (*this > ot);
	}

	// T <-> rac ----------------------------------------------------------------

	friend bool operator < (T ot, basic_racional<T> th) {
		return th > ot;
	}

	friend bool operator > (T ot, basic_racional<T> th) {
		return ot < th;
	}

	friend bool operator <= (T ot, basic_racional<T> th) {
		return !(th > ot);
	}

	friend bool operator >= (T ot, basic_racional<T> th) {
		return !(th < ot);
	}

	friend bool operator == (T ot, basic_racional<T> th) {
		return (th <= ot) && (*this >= ot);
	}

	friend bool operator != (const T& ot, basic_racional<T> th) {
		return (th < ot) || (th > ot);
	}

	T val() {
		return numerator / denominator;
	}

};

typedef basic_racional<int> racional;