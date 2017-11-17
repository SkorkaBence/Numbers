#pragma once

#include <iostream>
#include "Racional.hpp"

template<typename T>
class basic_complex {
private:

	T re;
	T im;

public:

	basic_complex() : re(0), im(0) {}
	basic_complex(T r) : re(r), im(0) {}
	basic_complex(T r, T i) : re(r), im(i) {}
	basic_complex(const basic_complex<T>& copy) : re(copy.re), im(copy.im) {}

	~basic_complex() {}

	friend std::ostream& operator << (std::ostream& ou, const basic_complex<T>& cn) {
		if (cn.re != 0 && cn.im != 0) {
			if (cn.im >= 0) {
				ou << cn.re << "+" << cn.im << "i";
			} else {
				ou << cn.re << "-" << (cn.im * -1) << "i";
			}
		} else if (cn.im != 0) {
			ou << cn.im << "i";
		} else {
			ou << cn.re;
		}
		return ou;
	}

	basic_complex& operator = (const basic_complex<T>& oc) {
		re = oc.re;
		im = oc.im;
		return *this;
	}

	basic_complex& operator += (const basic_complex<T>& oc) {
		re += oc.re;
		im += oc.im;
		return *this;
	}

	basic_complex operator + (const basic_complex<T>& oc) {
		basic_complex<T> r(re, im);
		r += oc;
		return r;
	}

	basic_complex& operator -= (const basic_complex<T>& oc) {
		re -= oc.re;
		im -= oc.im;
		return *this;
	}

	basic_complex operator - (const basic_complex<T>& oc) {
		basic_complex<T> r(re, im);
		r -= oc;
		return r;
	}

	basic_complex& operator *= (const basic_complex<T>& oc) {
		T newre = re * oc.re - im * oc.im;
		T newim = re * oc.im + im * oc.re;
		re = newre;
		im = newim;
		return *this;
	}

	basic_complex operator * (const basic_complex<T>& oc) {
		basic_complex<T> r(re, im);
		r *= oc;
		return r;
	}

	basic_complex& operator /= (const basic_complex<T>& oc) {
		T d = oc.re * oc.re + oc.im * oc.im;
		T newre = re * oc.re + im * oc.im;
		newre /= d;
		T newim = im * oc.re - re * oc.im;
		newim /= d;
		re = newre;
		im = newim;
		return *this;
	}

	basic_complex operator / (const basic_complex<T>& oc) {
		basic_complex<T> r(re, im);
		r /= oc;
		return r;
	}

	bool operator == (const basic_complex<T>& oc) {
		return (re == oc.re) && (im == oc.im);
	}

	bool operator != (const basic_complex<T>& oc) {
		return !(*this == oc);
	}

};

typedef basic_complex<int> complex;