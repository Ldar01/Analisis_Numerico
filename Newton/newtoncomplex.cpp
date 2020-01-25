#include <iostream> // std::cout, std::endl
//#include <cmath> //exp, std::abs, pow 
#include <complex> //exp, std::abs, pow//
#include <iomanip> //std::setprecision

using std::cout;	using std::endl;
using std::abs;		using std::setprecision;
using std::complex;

//Definimos la funciÃ³n
inline complex<double> f(complex<double> x) { return pow(x,3) - 2.0*x +2.0; }//cambiar complex<double> a complex<complex<double>>
//Derivada de la funciÃ³n
inline complex<double> df(complex<double> x) { return 3.0*pow(x,2.0) - 2.0; }
/*
p0: AproximaciÃ³n inicial
TOL: tolerancia
Nmax: nÃºmero mÃ¡ximo de iteraciones
*/
void newton(complex<double> p0,float TOL,int Nmax){

	complex<double> p;
	for(int i=0; i < Nmax; i++){
		p = p0 - f(p0)/df(p0);		
		cout << i << setprecision(20) << "\t" << p0 << 	"\t" << p << "\t" << abs(p0 - p) << endl;		
		if(abs(p - p0) < TOL)	break;
		p0 = p;				
	}

} 
	
int main(){	
	// Invocamos el mÃ©todo segÃºn los datos del problema
	complex<double> z(1.0, 1.0);
    newton(z, pow(10, -10), 40);
	return 0;
}