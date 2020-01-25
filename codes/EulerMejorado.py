import math as m

# Python program to implement Runge Kutta method 
# A sample differential equation "dy / dx = (x - y)/2" 
def dydx(x, y): 
    return 2*x*y
  
# Finds value of y for a given x using step size h 
# and initial value y0 at x0. 
def Euler(x0, y0, x1, h): 
    # Count number of iterations using step size or 
    # step height h 
    x = x0
    n = (int)((x1 - x0)/h)  
    # Iterate for number of iterations 
    y = y0 
    for i in range(1, n + 1): 
        # "Apply Euler Formulas to find next value of y"
        # Update next value of y
        print 'X= ',x,'Y= ',y
        y = y +h*(dydx(x,y) + dydx(x+h,y + h*dydx(x,y)))/2
        x = x+h
    print 'X= ',x,'Y= ',y 
    return y 
  
# Driver method 
x0 = 1
y = 1
x1 = 1.50
h = 0.1
a = Euler(x0, y, x1, h) 
print 'The value of y at x is:', a
