#include <iostream> // std::cout, std::endl
#include <cmath> //std::abs
#include <iomanip> //std::setprecision

using std::cout;	using std::endl;
using std::abs;		using std::setprecision;

// FunciÃ³n para IPF
inline long double g(long double x){ return (10 - 20*(exp(-0.2*x) -exp(-0.75*x))-5);  }


// Inline para calcular cada tÃ©rmino de la sucesiÃ³n de Aitken
inline long double p_hat(long double p0,long double p1,long double p2){ return p0 - pow( p1-p0 , 2.0)/(p2 - 2.0*p1 + p0);}

/*
p0: aproximaciÃ³n inicial
Nmax: nÃºmero mÃ¡ximo de iteraciones
T: tolerancia
Si no se usa long double, algÃºn dato se puede aproximar a 0
*/
void steffensen(long double p0, int Nmax, long double T){

	long double p, p1, p2;

    cout<<"n\t"<<"Pn^(n)\t\t"<<"Pn+1^(n)\t"<<"Pn+2^(n)\t"<<"P Gorro\t\t"<<"ErrAbs"<<endl; 
	for(int i = 0; i <= Nmax; i++){
		
		p1 = g(p0);
		p2 = g(p1);
		p = p_hat(p0, p1, p2);

		if(i == 0) cout <<i << setprecision(10) << "\t" << p0 << "\t" << p1 << "\t" << p2 << "\t"  << p << endl;
		else cout <<  i<<setprecision(10) << "\t" << p0 << "\t" << p1 << "\t" << p2 << "\t"  << p << "\t"  << abs(p0 - p) << endl;


		if(abs(p0-p) < T){
			cout << "Objetivo logrado con " << i+1 << " iteraciones"<< endl;
			break;
		}

		p0 = p;
	}
}

int main(){
	steffensen(1, 100, pow(10, -15));
}
