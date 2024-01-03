import math
#Pollard's p − 1 algorithm is a number theoretic integer factorization algorithm

def pollard_p_minus_1(N,B):  #basically factoring large composite numbers into their factors
    #initial a
    a = 2 
    non_trivial_factors = []
    #we estimate an implicit bound based on the size of N (the value of N greatly impacts memory performance)
    B = int(math.log(N))
    #greatest common divisor between a and N
    gcd = math.gcd(a, N)
    if gcd > 1: #=> a already non-trivial factor
        non_trivial_factors.append(gcd)
    for p in range(2, B + 1):
        a = pow(a, p)%N 
        #update gcd with the new value of a
        gcd = math.gcd(a - 1, N)
        if gcd > 1 : #non trivial factor found
            non_trivial_factors.append(gcd)
    if(len(non_trivial_factors)==0):
        return None #no trivial factor found between bounds
    else:
        non_trivial_factors = list(set(non_trivial_factors))
        return non_trivial_factors

print("Integer you want to factor:")
N = int(input()) #integer for factoring
print("Do you want to give and explicit bound or to estimate one by default? 0-no/1-yes:")
check=int(input())
if(check==1):
    print("Bound value:")
    B=int(input())
else:
    B = None
factor = pollard_p_minus_1(N,B)
if factor is None:
    print("No non-trivial factors found within the implicit bound.")
else:
    print(f"Non-trivial factors found: {factor}")
#source:https://en.wikipedia.org/wiki/Pollard%27s_p_−_1_algorithm