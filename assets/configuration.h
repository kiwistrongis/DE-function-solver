#ifndef assets_configuration_h
#define assets_configuration_h

//library includes
#include <cstddef>
//local includes
#include "function.h"

#define DeJong_ftype 1
#define APHE_ftype 2
#define Schwefel_ftype 3
#define Valley_ftype 4
#define Banana_ftype 5

/** @class Configuration
 * @brief Represents the initial configuration of a population
 * 
 * Configuration objects handle the loading of population parameters from files. This makes initialization easier for the population class.
 **/
class Configuration {
public:
	//Population Config Fields
	int population_size;
	int dimensionality;
	double mutation_constant;
	double crossover_rate;
	double x_min;
	double x_max;
	Function::Type functionType;

	//Run Config Fields
	int nGenerations;

	//Report Config Fields
	char* datafile;
	char* plotfile_base;

	//Constructor
	Configuration( char* filename = NULL);
	~Configuration();
private:
};

#endif