#ifndef assets_population_h
#define assets_population_h

//library includes
#include <vector>
//local includes
#include "configuration.h"
#include "entity.h"

/** @class Population
 * @brief Represents a group of entities
 * 
 * The class contains multiple entities, and through evolving the group using some specific mutation and crossover operators
 **/
class Population{
public:
	//Fields
	std::vector<Entity> entities;
	int N;
	int D;
	double F;
	double Cr;
	double mutation_chance;
	double cross_chance;
	Function::Type functionType;

	//Constructors and Destructor
	Population( const Configuration& conf = Configuration());

	//Evolution
	void evolve();

	//Statistics
	double average() const;
	double best() const;
	double worst() const;
	double standardDeviation() const;
	Vector findBest() const;

private:
};

#endif