import timeit
import random

def EuclideanAlgorithm(a, b):
    while b != 0:
        #swap the values of a and b and swap b with the reminder of a div b
        (a, b) = (b, a % b)
    #when b becomes 0,return a as gcd
    return a

def RecursiveEuclideanAlgorithm(a, b):
    #same logic as euclidean algorithm,just using recursivity
    if b == 0:
        return a
    else:
        return RecursiveEuclideanAlgorithm(b, a % b)

def LehmerGCD(a, b):
    #ensure a greater or equal than b+
    if a < b:
        (a, b) = (b, a)
    #while b is not null,using floor division find q,a updates as b,a - q * b updates b with the remainder of the division a/b,being an efficient way to find the remainder
    while b != 0:
        q = a // b
        (a, b) = (b, a - q * b)

    return a

def BinaryGcd(a, b):
    #basically reduct the smaller number from the greater until the numbers are equall,returning the gcd
    while a != b:
        if a > b:
            a = a - b
        else:
            b = b - a
    return a

#measure execution time for 10 random input pairs
i=0
for i in range(10):
    a = random.randint(1, 10000000000)
    b = random.randint(1, 10000000000)
    
    euclidean_time = timeit.timeit('EuclideanAlgorithm(a, b)', globals=globals(), number=10)
    binary_time = timeit.timeit('BinaryGcd(a, b)', globals=globals(), number=10)
    lehmer_time = timeit.timeit('LehmerGCD(a, b)', globals=globals(), number=10)
    
    print("a="+str(a)+" "+"b="+str(b))
    print(f"Euclidean Algorithm: {euclidean_time * 1000:.2f} ms")
    print(f"Binary Algorithm: {binary_time * 1000:.2f} ms")
    print(f"Lehmer's Algorithm: {lehmer_time * 1000:.2f} ms")
    print()