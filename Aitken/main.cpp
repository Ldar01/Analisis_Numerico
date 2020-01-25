#include <iostream> // std::cout, std::endl
#include <cmath> //std::abs
#include <iomanip> //std::setprecision

using std::cout;	using std::endl;
using std::abs;		using std::setprecision;

// FunciÃ³n para IPF para comprobar si g(x) existe en los intervalos dados
inline long double g(long double x){ return (2.0 - exp(x) + pow(x, 2))/3.0;  }

// Inline para calcular cada tÃ©rmino de la sucesiÃ³n de Aitken, P Gorro
inline double p_hat(double p0, double p1, double p2){ return p0 - pow( p1-p0 , 2.0)/(p2 - 2.0*p1 + p0);}

/*
p0: aproximaciÃ³n inicial
Nmax: nÃºmero mÃ¡ximo de iteraciones
T: tolerancia
*/
void aitken(double p0, int Nmax, double T){	

	double p0_hat; //Ãºltimo valor en la sucesiÃ³n de Aitken
	double p1_hat; //valor actual en la sucesiÃ³n de Aitken
		
	double p1, p2; //valores en la iteraciÃ³n de punto fijo 
    
    cout<<"n\t"<<"Pn\t\t"<<"Pn+1\t\t"<<"Pn+2\t\t"<<"P Gorro\t\t"<<"ErrAbs"<<endl;    

	for(int i = 0; i <= Nmax; i++){
		p1 = g(p0);	
		p2 = g(p1);
		
		p1_hat = p_hat(p0, p1, p2);		

		if(i == 0) cout << i <<setprecision(10) << "\t" << p0 << "\t" << p1 << "\t" << p2 << "\t" << p1_hat << endl;
		else cout <<i << setprecision(10) << "\t" << p0 << "\t" << p1 << "\t" << p2 << "\t" << p1_hat << "\t" << abs(p1_hat - p0_hat) <<endl;

		
		if(abs(p0_hat - p1_hat) < T){
			cout << "Objetivo logrado con " << i+1 << " iteraciones"<< endl;			
			break;						
		} 

		p0 = p1;
		p0_hat = p1_hat; 
	
	}		
}


int main(){

	aitken(0, 100, pow(10, -9));		
	
	return 0;
}
