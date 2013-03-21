#ifndef assets_vector_h
#define assets_vector_h

#define vector_print_prec 4

class Vector{
public:
	//fields
	int n;
	double* x;

	//constructors and destructors
	Vector( int n = 0);
	Vector( int, double*);
	Vector( const Vector&);
	~Vector();

	//operators
	//assignment
	Vector& operator=( const Vector&);
	//vector arithmatic
	Vector& operator+=( const Vector&);
	Vector& operator-=( const Vector&);
	//Vector& operator/=( const Vector&);
	const Vector operator+( const Vector&) const;
	const Vector operator-( const Vector&) const;
	//const Vector operator/( const Vector&) const;
	const double operator*( const Vector&) const;
	//scalar arithmatic
	Vector& operator*=( const double&);
	Vector& operator/=( const double&);
	const Vector operator*( const double&) const;
	const Vector operator/( const double&) const;
	//equality
	const bool operator==( const Vector&) const;
	const bool operator!=( const Vector&) const;

	//functions
	const double mag() const;
	const Vector normal() const;
	Vector& normalize();
	void print() const;
};

#endif
