import math

#doc:
#https://en.wikipedia.org/wiki/Pollard%27s_p_−_1_algorithm
#https://www.geeksforgeeks.org/pollard-p-1-algorithm/



#basic prime check function with iteration till sqrt
def is_prime(n): 
    if n <= 1:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

#pollar implementation
def pollard(n, B=10):#bound is defined as how many iterations the functions is allowed to go through until returning,greatly affects complexity
    a = 2
    i = 2
    #iterate until a prime factor is obtained 
    while i <= B:
        a = pow(a, i, n)
        d = math.gcd(a - 1, n)
        #obtain the factor
        if d > 1 and d != n:#if factor was succesfully obtained => return factor
            return d
        #increment i to continue iteration in case of failure for factor
        i += 1
    
    return None

#default values in case of no choice made
n = 1
num = n
user_bound = 100

#basic ui handling for num and bound
print("Please insert your preffered bound,if you dont want to,insert -1:")
choice=int(input())
if(choice != -1):
    user_bound=choice
print("Insert the number you want to factorize:")
n=int(input())
num=n

#populating factors with the factors opbtained by applying pollard
factors = []
while True:
    factor = pollard(num, user_bound)
    if factor:
        factors.append(factor)
        #floor division
        num //= factor
        #check for prime
        if is_prime(num):
            #both factors obtained 
            factors.append(num)
            break
    else:
        factors.append(num)
        break
#printf for result
print(f"Prime factors of {n} are: {factors}")