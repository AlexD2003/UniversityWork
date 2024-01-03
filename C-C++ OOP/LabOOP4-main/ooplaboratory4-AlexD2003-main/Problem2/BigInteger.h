#pragma once
#include<string>
#include<iostream>


class BigInteger {
public:
    BigInteger() : digits(nullptr), size(0), sign(1) {}
    BigInteger(const std::string& str) : digits(nullptr), size(0), sign(1) {
        size_t n = str.size();
        if (n > 0 && (str[0] == '+' || str[0] == '-')) {
            sign = (str[0] == '-') ? -1 : 1;
            n--;
        }
        digits = new int[n];
        size = n;
        for (size_t i = 0; i < n; i++) {
            digits[i] = str[i + (str[0] == '+' || str[0] == '-')] - '0';
        }
        stripLeadingZeroes();
    }
    ~BigInteger() { delete[] digits; }

    int compare(const BigInteger& N) const {
        if (sign < N.sign) return -1;
        if (sign > N.sign) return 1;
        if (size < N.size) return -sign;
        if (size > N.size) return sign;
        for (int i = size - 1; i >= 0; i--) {
            if (digits[i] < N.digits[i]) return -sign;
            if (digits[i] > N.digits[i]) return sign;
        }
        return 0;
    }

    bool operator==(const BigInteger& N) const { return compare(N) == 0; }
    bool operator<(const BigInteger& N) const { return compare(N) == -1; }
    bool operator<=(const BigInteger& N) const { return compare(N) <= 0; }
    bool operator>(const BigInteger& N) const { return compare(N) == 1; }
    bool operator>=(const BigInteger& N) const { return compare(N) >= 0; }

private:
    int* digits;
    size_t size;
    int sign;

    void stripLeadingZeroes() {
        while (size > 1 && digits[size - 1] == 0) {
            size--;
        }
        if (size == 1 && digits[0] == 0) {
            sign = 1;
        }
    }
};