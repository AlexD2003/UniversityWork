from hashlib import sha3_384


k=input()
k=int(k)
s=1
s2=0
s3=1
while(s2<k):
    s2+=s3
    s3+=1
    s+=1
s-=1
print(s)