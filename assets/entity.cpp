//library includes
#include <cassert>
#include <cstdio>
#include <cstdlib>
//local inlucdes
#include "function.h"
#include "globals.h"
#include "vector.h"
//override include
#include "entity.h"

// Constructor and Destructor
Entity::Entity( int problem_size, Function _function, double _x_min, double _x_max){
	chromosome = Vector( problem_size);
	function = _function;
	x_min = _x_min;
	x_max = _x_max;
	//generate a random chromosome
	double domainSize = x_max - x_min;
	for( int i = 0; i < problem_size; i++)
		chromosome.x[i] = x_min + domainSize*randDouble();}

Entity::Entity( const Entity& other){
	*this = other;}

Entity::~Entity(){}

// Operators
Entity& Entity::operator=( const Entity& other){
	//check for self assignment
	if( this == &other)
		return *this;
	//shallow fields
	chromosome = other.chromosome;
	function = other.function;
	x_min = other.x_min;
	x_max = other.x_max;
	//done
	return *this;}

bool Entity::operator==( const Entity& other) const{
	return chromosome == other.chromosome;}

bool Entity::operator!=( const Entity& other) const{
	return !(*this==other);}

// Evaluation and Evolution
double Entity::fitness() const{
	return function[chromosome];}

Entity& Entity::cross( const Entity& other){
	for( int i = 0; i < chromosome.n; i++)
		if( rand() % 2)
			chromosome.x[i] = other.chromosome.x[i];}
