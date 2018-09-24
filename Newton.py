import math


#Newton's methodPython

def dx(f, x):
    return abs(0-f(x))

def newtons_method(f, df, x0, e):
    delta = dx(f, x0)
    while delta > e:
        x0 = x0 - f(x0)/df(x0)
        delta = dx(f, x0)
    print ('Root is at: ', x0)
    print ('f(x) at root is: ', f(x0))


def f(x):
    #return 2*(math.exp(x-1)) - x**2 - 1
    return math.log(3-x) + x -2
def df(x):
    #return 2*(math.exp(x-1)) - 2*x
    return -(3-x)**-1 + 1
x0s = [1.9]
for x0 in x0s:
    newtons_method(f, df, x0, 1e-16)
