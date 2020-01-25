import math

a = 0
b = 10.0
g = 32.17
k = 0.1
m = 0.25
s0 = 300
#t = 6.00372630876


#Para transformar la ecuación en un problema de encontrar raíces, simplemente buscamos que quede igualada a 0

# Definimos la función anterior (la que nos piden), para verificar los signos opuestos
def f(x):
    return (s0- ( ( (m*g)/k )*x )+ ( (math.pow(m,2)*g)/math.pow(k,2) )*(1- math.e**( (-k*x)/m ) ) )

#f: función para la cual buscamos la raíz 
#a: extremo izquierdo del intervalo
#b: extremo derecho del intervalo
#T: tolerancia 

def bisection(f, a, b, T):
    n = math.ceil( math.log( (b - a)/T  , 2) ) #En esta línea estoy calculando el número de iteraciones necesarias
    print("Iteraciones necesarias: "+str(n)+"\n")
    print("n\t\t"+"a\t\t"+"b\t\t"+"p = (a+b)/2\t"+"f(p)\n")
    for i in range(0, n):
        p = (a + b)/2
	#aqui falta imprimir el valor absoluto y agregar mas tab para mas bonis
        print(str(i) + " \t "+ " \t " + str(a) + " \t " + " \t "+ str(b) + " \t "+ " \t " + str(p) + " \t " + " \t "+ str(f(p)) )
        if f(a)*f(p) < 0:
            b = p
        else:
            a = p


bisection(f, a, b, math.pow(10,-5))
#print ( f(b)) 
#print(math.pow(10,-5))




