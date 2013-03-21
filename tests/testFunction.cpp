//lib includes
#include <cstdio>
//local includes
#include "../assets/function.h"
#include "../assets/vector.h"

int main(){
	Vector v(3);
	v.x[0] = 2;
	v.x[1] = 0.001;
	v.x[2] = 4;
	printf("v: ");
	v.print();

	Function f;
	f.type = Function::DeJong;
	printf("DeJong(v) = %f\n", f[v]);
	f.type = Function::APHE;
	printf("APHE(v) = %f\n", f[v]);
	f.type = Function::Schwefel;
	printf("Schwefel(v) = %f\n", f[v]);
	f.type = Function::Valley;
	printf("Valley(v) = %f\n", f[v]);
	f.type = Function::Banana;
	printf("Banana(v) = %f\n", f[v]);
}