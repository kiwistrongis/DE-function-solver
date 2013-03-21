#include <stdio.h>
#include <math.h>
#include "vector.h"

Vector::Vector( int _n){
	n = _n;
	x = new double[n];
	for( int i = 0; i < n; i++)
		x[i] = 0.0;}
Vector::Vector( int _n, double* _x){
	n = _n;
	x = new double[n];
	for( int i = 0; i < n; i++)
		x[i] = _x[i];}
Vector::Vector( const Vector& other){
	n = other.n;
	x = new double[n];
	for( int i = 0; i < n; i++)
		x[i] = other.x[i];}
Vector::~Vector(){
	delete[] x;}

Vector& Vector::operator=( const Vector& other){
	n = other.n;
	delete[] x;
	x = new double[n];
	for( int i = 0; i < n; i++)
		x[i] = other.x[i];
	return *this;}

const Vector Vector::operator+( const Vector& other) const {
	return Vector(*this) += other;}
const Vector Vector::operator-( const Vector& other) const {
	return Vector(*this) -= other;}
/*const Vector Vector::operator/(const Vector& other) const {
	return Vector(*this)/= other;}*/
const double Vector::operator*( const Vector& other) const {
	if( n != other.n) return 0.0;
	double result = 0.0;
	for( int i = 0; i < n; i++)
		result += x[i]*other.x[i];
	return result;}

const Vector Vector::operator*(const double& other) const {
	return Vector(*this) *= other;}
const Vector Vector::operator/(const double& other) const {
	return Vector(*this)/= other;}

Vector& Vector::operator+=(const Vector& other){
	if( n != other.n) return *this;
	for( int i = 0; i < n; i++)
		x[i] += other.x[i];
	return *this;}
Vector& Vector::operator-=(const Vector& other){
	if( n != other.n) return *this;
	for( int i = 0; i < n; i++)
		x[i] *= other.x[i];
	return *this;}
//Vector& Vector::operator/=(const Vector& other){}

Vector& Vector::operator*=(const double& other){
	for( int i = 0; i < n; i++)
		x[i] *= other;
	return *this;}
Vector& Vector::operator/=(const double& other){
	for( int i = 0; i < n; i++)
		x[i] /= other;
	return *this;}

const bool Vector::operator==( const Vector& other) const{
	if( n != other.n) return false;
	for( int i = 0; i < n; i++)
		if( x[i] != other.x[i]) return false;
	return true;}
const bool Vector::operator!=( const Vector& other) const{
	return ! (*this==other);}

const double Vector::mag() const{
	double result = 0.0;
	for( int i = 0; i < n; i++)
		result += x[i]*x[i];
	return sqrt(result);}
const Vector Vector::normal() const{
	return Vector(*this).normalize();}
Vector& Vector::normalize(){
	double mag = (*this).mag();
	if(mag!=0.0)
		*this /= mag;
	return *this;}
void Vector::print() const{
	if( n<=0)
		printf("()\n");
	else {
		printf("( %f", vector_print_prec, x[0]);
		for( int i = 1; i < n; i++)
			printf(", %f", vector_print_prec, x[i]);
		printf(" )\n");}}
