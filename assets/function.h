#ifndef assets_function_h
#define assets_function_h

//local includes
#include "vector.h"

class Function {
public:
	enum Type {
		DeJong,
		APHE,
		Schwefel,
		Valley,
		Banana,
		Null};
	Type type;

	Function( Type _type = Null);
	const double operator[]( const Vector&) const;

private:
	const double _DeJong( const Vector&) const;
	const double _APHE( const Vector&) const;
	const double _Schwefel( const Vector&) const;
	const double _Valley( const Vector&) const;
	const double _Banana( const Vector&) const;
};

#endif