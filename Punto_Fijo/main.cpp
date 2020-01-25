#include <iostream> // std::cout, std::endl
#include <cmath> //std::abs
#include <iomanip> //std::setprecision

using std::cout;	using std::endl;
using std::abs;		using std::setprecision;

// FunciÃ³n para IPF
inline double g(double x){
	double a=exp(x);
	double b=pow(x,2);
	return (2.0-a+b)/3.0;
}

/*
IteraciÃ³n de punto fijo
p0/Pn: aproximaciÃ³n inicial
Nmax: nÃºmero mÃ¡ximo de iteraciones
T: tolerancia
Pn+1/p: g(Pn)
*/

void fixedPoint(double p0, int Nmax, double T){
	
	double p;	
    cout<<"n\t\t"<<"Pn\t\t"<<"Pn+1\t\t"<<"ErrAbs"<<endl;	
	for(int i=0; i< Nmax; i++){
		p = g(p0);		
		cout << setprecision(10) <<  i << "\t" << p0 << "\t" << p << "\t" <<abs(p-p0) <<endl;
		
		if(abs(p-p0) < T) {
			cout << "Objetivo logrado con " << i+1 << " iteraciones"<< endl;
			break;
		}
		
		p0 = p;
	}
	
}

int main(){

	fixedPoint(0, 100, pow(10, -9));		
	
	return 0;
}
