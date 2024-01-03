#pragma once
#include<string>
#include<iostream>


class BigInteger {
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

    BigInteger(const BigInteger& other) {
        sgn = other.sgn;
        size = other.size;
        digits = new int[size];
        for (int i = 0; i < size; i++) {
            digits[i] = other.digits[i];
        }
    }
    BigInteger& operator=(const BigInteger& other) {
        if (this != &other) {
            delete[] digits;
            sgn = other.sgn;
            size = other.size;
            digits = new int[size];
            for (int i = 0; i < size; i++) {
                digits[i] = other.digits[i];
            }
        }
        return *this;
    }
    int getSign() const {
        return sgn;
    }
    int compare(const BigInteger& other) const {
        if (sgn < other.sgn) return -1;
        if (sgn > other.sgn) return 1;
        if (size < other.size) return -sgn;
        if (size > other.size) return sgn;

        for (int i = size - 1; i >= 0; i--) {
            if (digits[i] < other.digits[i]) return -sgn;
            if (digits[i] > other.digits[i]) return sgn;
        }
        return 0;
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
    bool operator<(const BigInteger& other) const {
        return compare(other) < 0;
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


private:
    int* digits;
    int sgn;
    int size;
};

