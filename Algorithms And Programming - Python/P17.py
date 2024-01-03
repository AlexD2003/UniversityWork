def sum(n):
    s=0
    while(n>0):
        s+=n%10
        n//=10
    return s    
a=input()
a=int(a)
i=1
ok=0
while(i<=a):
    if(i+sum(i)==a):
        ok=1
        break
    i+=1
if(ok==1):
    print("true")
else:
    print("false")