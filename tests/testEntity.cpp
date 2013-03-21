#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "../assets/debug.h"
#include "../assets/entity.h"

int main( ){
	srand( time( NULL));

	printf(" Entity A:\n");
	Entity a( 8);

	printf(" fitness: %f\n", a.fitness());
}