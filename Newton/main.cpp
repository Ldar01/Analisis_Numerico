#include <iostream> // std::cout, std::endl
#include <cmath> //exp, std::abs, pow
#include <iomanip> //std::setprecision

using std::cout;	using std::endl;
using std::abs;		using std::setprecision;

double g = 32.17, k = 0.1, m = 0.25, s0 = 300;

double f(double x) {
	return (s0- ( ( (m*g)/k )*x )+ ( (pow(m,2)*g)/pow(k,2) )*(1- exp( (-k*x)/m ) ) ); 
}
double df(double x) {
	return ( (-g * m * (exp( ( (k*x)/m)-1) ) ) * ( exp( (k*x)/m )  )/ k  ); 
}
/*
p0/Pn: AproximaciÃ³n inicial
TOL: tolerancia
Nmax: nÃºmero mÃ¡ximo de iteraciones
*/
void newton(double p0,double TOL,double Nmax){
    cout<<"n"<<"\t\t"<<"Pn\t\t"<<"Pn+1\t\t"<<"ErrAbs"<<endl;
	double p;
	for(int i=0; i < Nmax; i++){
		p = p0 - f(p0)/df(p0);		
		cout << i << setprecision(9) << "\t" << p0 << 	"\t" << p << "\t" << abs(p0 - p) << endl;		
		if(abs(p - p0) < TOL)	break;
		p0 = p;				
	}

} 
	
int main(){	
	// Invocamos el mÃ©todo segÃºn los datos del problema
	newton(5, pow(10, -15), 30);
	//cout<< setprecision(20)<<(f(1))<<endl;
	//cout<< setprecision(20)<<(df(1))<<endl;
	return 0;
}
