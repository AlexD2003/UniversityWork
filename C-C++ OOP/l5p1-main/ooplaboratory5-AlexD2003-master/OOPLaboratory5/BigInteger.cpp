#include "BigInteger.h"

#include <cctype> // for isdigit
#include <iostream>
#include <iomanip>
using namespace std;
void prepend_zeros(BigInteger &other,int num_zeros) {
    int* new_arr = new int[other.get_size() + num_zeros];
    for (int i = 0; i < num_zeros; i++) {
        new_arr[i] = 0;
    }
    for (int i = num_zeros; i < other.get_size() + num_zeros; i++) {
        new_arr[i] = other.get_digits()[i - num_zeros];
    }
    other.set_digits(*new_arr);
    other.set_size(num_zeros+other.get_size());
}
void negate(BigInteger other){
    int* new_arr = new int[other.get_size()];
    for (int i = 0; i < other.get_size(); i++) {
        new_arr[i] = other.get_digits()[i] * -1;
    }
    other.set_digits(*new_arr);
}
BigInteger BigInteger::subtract(BigInteger& other) const {
    if (sgn == 0) {
        other.set_sgn(-1);
        return other;
    }
    if (other.sgn == 0) {
        return *this;
    }
    if (*this == other) {
        return BigInteger();
    }
    int result_sign = sgn;
    int* result_digits = new int[size];
    int carry = 0;
    int i, j;
    for (i = size - 1, j = other.size - 1; j >= 0; i--, j--) {
        int diff = digits[i] - other.digits[j] - carry;
        if (diff < 0) {
            diff += 10;
            carry = 1;
        }
        else {
            carry = 0;
        }
        result_digits[i] = diff;
    }
    while (i >= 0) {
        int diff = digits[i] - carry;
        if (diff < 0) {
            diff += 10;
            carry = 1;
        }
        else {
            carry = 0;
        }
        result_digits[i] = diff;
        i--;
    }
    i = 0;
    while (i < size && result_digits[i] == 0) {
        i++;
    }
    if (i == size) {
        return BigInteger();
    }
    BigInteger result;
    result.set_digits(*result_digits + i);
    result.set_size(size - i);
    result.set_sgn(result_sign);
    return result;
}

BigInteger BigInteger::add(const BigInteger& other) const {
    BigInteger result;
    int carry = 0;
    if (sgn == other.sgn) {
        result.sgn = sgn;
    }
    else {
        BigInteger temp = other;
        temp.sgn = -temp.sgn;
        return (*this).subtract(temp);
    }
    int max_size = max(size, other.size);
    result.digits = new int[max_size + 1];
    int i = 0;
    for (; i < size && i < other.size; i++) {
        int sum = digits[i] + other.digits[i] + carry;
        result.digits[i] = sum % 10;
        carry = sum / 10;
    }
    for (i=0; i < size; i++) {
        int sum = digits[i] + carry;
        result.digits[i] = sum % 10;
        carry = sum / 10;
    }
    for (i=0; i < other.size; i++) {
        int sum = other.digits[i] + carry;
        result.digits[i] = sum % 10;
        carry = sum / 10;
    }
    if (carry > 0) {
        result.digits[i] = carry;
        i++;
    }
    result.size = i;

    return result;
}