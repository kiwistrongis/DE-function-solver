#ifndef assets_entity_h
#define assets_entity_h

//library includes
//local includes
#include "debug.h"
#include "vector.h"
#include "function.h"

/** @class Entity
 * @brief Represents a candidate solution to the N-Queens problem
 * 
 * The class implements all of the following functionality:
 * - encoding and decoding of the chromosome
 * - evaluation of the fitness function
 * - multiple mutation and crossover evolutionary operators
 * 
 * The following mutation operators are implemented:
 * - Flip a random bit
 * 
 * The following crossover operators are implemented.
 * - Copy bits after some random n
 **/
class Entity {
public:
	//Fields
	Vector chromosome;
	Function function;
	double x_min;
	double x_max;

	//Constructors and Destructor
	Entity( int, Function, double, double);
	Entity( const Entity&);
	~Entity();

	//Operators
	Entity& operator=( const Entity& other);
	bool operator==( const Entity& other) const;
	bool operator!=( const Entity& other) const;

	//Evaluation and Evolution
	double fitness() const;
	Entity& cross( const Entity& other);
private:
};

#endif