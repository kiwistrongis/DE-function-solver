//lib includes
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdio>
//local includes
//override include
#include "function.h"

Function::Function( Type _type){
	type = _type;}
const double Function::operator[]( const Vector& v) const{
	switch( type){
		case DeJong:
			return _DeJong( v);
		case APHE:
			return _APHE( v);
		case Schwefel:
			return _Schwefel( v);
		case Valley:
			return _Valley( v);
		case Banana:
			return _Banana( v);
		case Null:
		default:
			return 0.0;}}

const double Function::_DeJong( const Vector& v) const{
	double result = 0.0;
	for( int i = 0; i < v.n; i++)
		result += pow( v.x[i], 2);
	return result;}

const double Function::_APHE( const Vector& v) const{
	double result = 0.0;
	for( int i = 0; i < v.n; i++)
		result += i * pow( v.x[i], 2);
	return result;}

const double Function::_Schwefel( const Vector& v) const{
	double result = 0.0;
	for( int i = 0; i < v.n; i++){
		double r_2 = 0.0;
		for( int j = 0; j <= i; j++)
			r_2 += v.x[j];
		result += pow( r_2, 2);}
	return result;}

const double Function::_Valley( const Vector& v) const{
	double result = 0.0;
	for( int i = 1; i < v.n; i++)
		result += 100 *
			pow( v.x[i] - pow(v.x[i-1],2), 2) +
			pow( 1 - v.x[i-1], 2);
	return result;}

const double Function::_Banana( const Vector& v) const{
	double result = 10*v.n;
	for( int i = 0; i < v.n; i++)
		result += pow( v.x[i], 2) -
			10 * cos( 2 * M_PI * v.x[i]);
	return result;}
