#include <iostream> // std::cout, std::endl
#include <cmath> //exp, std::abs, pow
#include <iomanip> //std::setprecision

using std::cout;	using std::endl;
using std::abs;		using std::setprecision;

double f(double x){
	double pi = 3.1415926535897;
	double a = 0.5;
	double b = a*exp(-x/(2*pi));
	double c = sin(x);
	double d = 0.75;

	double fxx = a+b*c-d;
	return fxx;
}
/*
p0: aproximaciÃ³n inicial
p1: aproximaciÃ³n inicial
TOL: tolerancia
Nmax: nÃºmero mÃ¡ximo de iteraciones
*/
void secant(long double p0,long double p1,long double TOL,int Nmax){

	long double p;
	for(int i=0; i < Nmax; i++){
		p = p1 - f(p1)*(p1 - p0 )/( f(p1) - f(p0));		
		cout << i << setprecision(15) << "\t" << "\t"<< p0 << "\t" << "\t"<< p1 << "\t" << "\t"<< p << "\t"<< "\t"<< abs(p1 - p)<< endl;		
		if(abs(p - p1) < TOL)	break;
		
		p0 = p1;
		p1 = p;		
		
	}

} 
	
int main(){

	//Invocamos el mÃ©todo con los parÃ¡metros dados en el problema	
	secant(0.65625,0.65625+0.1,10^-12,30);

	return 0;
}
