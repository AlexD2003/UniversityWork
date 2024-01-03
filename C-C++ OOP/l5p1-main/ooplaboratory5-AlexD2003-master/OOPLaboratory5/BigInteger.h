#pragma once
#include<string>
#include<iostream>


class BigInteger{

public:

    
    BigInteger() {
        digits = nullptr;
        sgn = 0;
        size = 0;
    }
    BigInteger(std::string str) {
        digits = nullptr;
        size = 0;
        sgn = 0;
        if (str.empty()) {
            return;
        }
        size_t i = 0;
        while (i < str.size() && str[i] == '0') {
            i++;
        }
        if (i == str.size()) {
            digits = new int[1];
            digits[0] = 0;
            size = 1;
            sgn = 0;
            return;
        }
        if (str[i] == '-') {
            sgn = -1;
            i++;
        }
        else {
            sgn = 1;
            if (str[i] == '+') {
                i++;
            }
        }
        size = str.size() - i;
        digits = new int[size];
        for (size_t j = 0; j < size; j++) {
            digits[j] = str[i + j] - '0';
        }
    }

    ~BigInteger() {
        delete[] digits;
    }
    void negate(BigInteger* other) {}
    BigInteger(const BigInteger& other) {
        sgn = other.sgn;
        size = other.size;
        digits = new int[size];
        for (int i = 0; i < size; i++) {
            digits[i] = other.digits[i];
        }
    }

    int getSign() const {
        return sgn;
    }
    bool operator==(const BigInteger& N) const {
        if (size != N.size || sgn != N.sgn) {
            return false;
        }
        for (int i = 0; i < size; i++) {
            if (digits[i] != N.digits[i]) {
                return false;
            }
        }
        return true;
    }
    int compare(const BigInteger& N) const {
        if (sgn < N.sgn) return -1;
        if (sgn > N.sgn) return 1;
        if (size < N.size) return -sgn;
        if (size > N.size) return sgn;

        for (int i = size - 1; i >= 0; i--) {
            if (digits[i] < N.digits[i]) return -sgn;
            if (digits[i] > N.digits[i]) return sgn;
        }
        return 0;
    }
    bool operator<(const BigInteger& N) const {
        return compare(N) < 0;
    }

    bool operator<=(const BigInteger& other) const {
        return compare(other) <= 0;
    }

    bool operator>(const BigInteger& other) const {
        return compare(other) > 0;
    }

    bool operator>=(const BigInteger& other) const {
        return compare(other) >= 0;
    }
    BigInteger subtract(BigInteger& other) const {}
    BigInteger add(const BigInteger& other) const {}
    void prepend_zeros(BigInteger &other, int num_zeros)
    int compare(const BigInteger& N) const {
        // compare the signs first
        if (sgn < N.sgn) return -1;
        if (sgn > N.sgn) return 1;

        // compare the actual digits
        if (size < N.size) return -sgn;
        if (size > N.size) return sgn;

        for (int i = size - 1; i >= 0; i--) {
            if (digits[i] < N.digits[i]) return -sgn;
            if (digits[i] > N.digits[i]) return sgn;
        }

        return 0; // equal
    }
    int add(const BigInteger& other) const;
    friend std::ostream& operator<<(std::ostream& os, const BigInteger& obj) {
        if (obj.sgn == -1) {
            os << "-";
        }
        for (int i = 0; i <= obj.size - 1; i++) {
            os << obj.digits[i];
        }
        return os;
    }
    void set_size(int size2) {
        size = size2;
    }
    void set_sgn(int sgn2) {
        sgn = sgn2;
    }
    void set_digits(int digits2) {
        *digits = digits2;
    }
    int* get_digits() const {
        return digits;
    }
    int get_sgn() const {
        return sgn;
    }
    int get_size() const {
        return size;
    }

private:
    int* digits;
    int sgn;
    int size;
};
