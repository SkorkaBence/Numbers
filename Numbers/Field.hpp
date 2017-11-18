#pragma once

#include <iostream>

namespace sbl {

    template<int N, typename C = unsigned int>
    class basic_field {
    private:
        C value = 0;
    public:
        basic_field() {};
        basic_field(C in) : value(in) {};
        basic_field(const basic_field& copy) : value(copy.value) {}

        void setValue(C val) {
            value = val % N;
        }

        operator C () {
            return value;
        }

        basic_field& operator ++() {
            setValue(value + 1);
            return *this;
        }

        basic_field& operator +=(C v) {
            setValue(value + v);
            return *this;
        }

        basic_field& operator --() {
            setValue(value - 1);
            return *this;
        }

        basic_field& operator -=(C v) {
            setValue(value - v);
            return *this;
        }

        basic_field& operator *=(C v) {
            setValue(value * v);
            return *this;
        }

        basic_field& operator /=(C v) {
            setValue(value / v);
            return *this;
        }

        basic_field& operator = (const basic_field& cp) {
            value = cp.value;
            return *this;
        }

        basic_field& operator = (C cp) {
            setValue(cp);
            return *this;
        }

        friend std::ostream& operator << (std::ostream& ou, const basic_field& f) {
            ou << f.value;
            return ou;
        }

        friend std::istream& operator >> (std::istream& ou, const basic_field& f) {
            C v;
            ou >> v;
            f.setValue(v);
            return ou;
        }
    };

}