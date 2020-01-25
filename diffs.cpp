#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::setprecision;

long double f(long double x){
	return log( pow(cos(x),2) );
}

long double forward_diff(long double x, long double h, int k){
	if(k == 0) return f(x);
	else return forward_diff(x + h, h, k - 1) - forward_diff(x, h, k - 1); 
}

long double central_diff(long double x, long double h, int k){
	if(k== 0) return f(x);
	else return central_diff(x + h/2.0, h, k-1) - central_diff(x - h/2.0, h, k-1);
}

int main(){
	
	cout << setprecision(6) << central_diff((M_PI/4), 0.0001, 3)/pow(0.0001, 3) << endl;	

	return 0;
}
