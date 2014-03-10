import math
def f(x):
	return (math.log(x))**2 - 1 - 2*math.log(x)
e, a, b = input()
c, cold = a, a + 2*e

edf = e/10
def df(x):
	return (f(x)*(f(x+edf)-f(x)))/((edf)*f(x))
while abs(c-cold)>e:
	cold, c = c, c - f(c)/df(c)
print(c)