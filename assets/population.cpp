//library includes
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
//local includes
#include "globals.h"
#include "configuration.h"
//override include
#include "population.h"

// Constructors and Destructor
Population::Population( const Configuration& conf){
	//fields
	N = conf.population_size;
	D = conf.dimensionality;
	F = conf.mutation_constant;
	Cr = conf.crossover_rate;
	functionType = conf.functionType;

	//create all the entities
	while( entities.size() < N)
		entities.push_back(
			Entity(
				D,
				Function(functionType),
				conf.x_min, conf.x_max));}

// Evolution
void Population::evolve(){
	std::vector<Entity> newEntities;
	for( int i = 0; i < N; i++){
		//select parents
		int a = rand() % N;
		int b = a;
		while( b!=a)
			b = rand() % N;
		int c = b;
		while( c != a && c != b)
			c = rand() % N;
		//mutantation
		Entity mutant( entities[0]);
		mutant.chromosome =
			entities[a].chromosome +
			(entities[b].chromosome -
				entities[c].chromosome) * F;
		//crossover
		mutant.cross( entities[i]);
		//selection
		newEntities.push_back(
			(mutant.fitness() < entities[i].fitness())?
				mutant : entities[i]);}
	entities.swap( newEntities);}

// Statistics
double Population::average() const{
	double result = 0.0;
	for( int i = 0; i < N; i++)
		result += entities[i].fitness();
	return result / N;}
double Population::best() const{
	double result = entities[0].fitness();
	for( int i = 1; i < N; i++){
		double newResult = entities[i].fitness();
		if( newResult < result)
			result = newResult;}
	return result;}
double Population::worst() const{
	double result = entities[0].fitness();
	for( int i = 1; i < N; i++){
		double newResult = entities[i].fitness();
		if( newResult > result)
			result = newResult;}
	return result;}
double Population::standardDeviation() const{
	double avg = average();
	double result = 0.0;
	for( int i = 0; i < N; i++)
		result += pow( avg - entities[i].fitness(), 2);
	return sqrt( result / N);}
Vector Population::findBest() const{
	int result = 0;
	double result_fitness = entities[0].fitness();
	for( int i = 1; i < N; i++){
		double newFitness = entities[i].fitness();
		if( newFitness < result_fitness){
			result_fitness = newFitness;
			result = i;}}
	return result;}