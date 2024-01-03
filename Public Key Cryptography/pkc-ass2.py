from math import gcd

#eulers totient-calculates count of natural numbers <=n that are coprime with n
def phi(n):
    count = 0
    for i in range(1, n + 1):
        if gcd(n, i) == 1:
            count += 1
    return count
#if phi(x)==v we append the number thats found and later return it
def find_numbers_with_euler_value(v, b):
    numbers_with_value_v = []
    for x in range(1, b):
        if phi(x) == v:
            numbers_with_value_v.append(x)
    return numbers_with_value_v


#input
print("Insert desired euler`s value:")
v=input()
vfin=int(v)
print("Insert upper bound:")
b=input()5
bfin=int(b)


result = find_numbers_with_euler_value(vfin, bfin)
print(f"Natural numbers less than {b} with Euler's function value {v}:")
print(result)