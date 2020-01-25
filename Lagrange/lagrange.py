from sympy import * # Usaremos SymPy como herramienta para realizar manipulaciones simbólicas

# Las siguientes dos librerías serán utilizadas para graficar
import matplotlib.pyplot as plt;
import numpy as np

# Usaremos lo siguiente para mostrar los polinomios de forma bonita
from sympy.interactive import printing;
printing.init_printing(use_latex=True);
from IPython.display import display, Latex

x = Symbol('x')

#funcion


def f(z):
    return sin(pi*z)

xs = [1, 1.25, 1.6]
ys = [f(1), f(1.25), f(1.6)]


'''
Esta primera función calcula la combinación lineal. Es una traducción directa de la fórmula e 
invoca la función lagrangeBasisFunction para calcular las funciones base.
xs: arreglo con valores en x
ys: arreglo con valores en y
degree: grado del polinomio
'''
def lagrangePolynomial(xs, ys, degree):
    polynomial = 0.0;
    for i in range(0, degree + 1):
        polynomial += ys[i]*lagrangeBasisFunction(xs, degree, i)
    return polynomial    
   
'''
Esta función calcula la función base correspondiente. Es, también, una traducción directa de la fórmula.
xs: arreglo con valores en x
degree: grado del polinomio, índice superior del producto
k: índice de la función base 
'''    
def lagrangeBasisFunction(xs, degree, k):
    L = 1.0
    for i in range(0, degree + 1):
        if i == k:
            continue
        else:
            L *= (x - xs[i])/(xs[k] - xs[i])
    return L

pol = lagrangePolynomial(xs, ys, 2)
print(str(pol))
display(Latex('$$ p_{2}(x) = '+ latex(simplify(pol.evalf())) + '$$'))



pol.subs(x, 1.6).evalf()

f(1.6).evalf()
print(f(1.6))


fig, ax = plt.subplots(figsize=(10, 10));

lambdaf = lambdify(x, pol)

xv = np.linspace(0, 2, 50);
ax.plot(xv, lambdaf(xv), color='green');
ax.plot(xv, np.sin(np.pi*xv), color = 'red')
ax.scatter(xs, ys, color='blue', marker='o');
plt.show(); 



