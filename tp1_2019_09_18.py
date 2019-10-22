from math import e

# The result is the cash in a bank account with a starting value of e-1. 
# Each year, the value is multiplied for the year and subtracted 1.

a = (e-1)

for i in range(1, 26, 1):
    a = (a*i)-1

print("The result is " + str(a))

# This simple program shows how different can be the result of two similar, but symmetrical, for lopps
# In this case, it will print true, but it could print false if a and b were not 0.0 initially.

a=0.0
b=0.0

for i in range(-10, 11, 1):
    a+=(10**i)

for i in range(10, -11, -1):
    b+=(10**i)

print(a==b)