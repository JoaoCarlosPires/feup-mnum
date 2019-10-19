#from math import e
#from numpy import float64

#a = float16(e-1)

#for i in range(1, 26, 1):
#    a = float16((a*i)-1)

#print("The result is " + str(a))

a=0.0
b=0.0

for i in range(-10, 11, 1):
    a+=(10**i)

for i in range(10, -11, -1):
    b+=(10**i)

print(a==b)