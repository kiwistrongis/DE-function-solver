//library includes
#include <cstddef>
#include <cstring>
#include <fstream>
#include <sstream>
#include <string>
//override includes
#include "configuration.h"
#include "debug.h"

using namespace std;

Configuration::Configuration( char* filename){
	//set default values
	population_size = 200;
	dimensionality = 3;
	mutation_constant = 0.1;
	crossover_rate = 0.7;
	x_min = -0.1;
	x_max = 0.1;
	functionType = Function::DeJong;

	nGenerations = 500;

	//datafile
	datafile = new char[ 128];
	char datafile_default[] = "results/default.csv";
	strcpy( datafile, datafile_default);
	//chart
	plotfile_base = new char[ 128];
	char plotfile_base_default[] = "results/default.png";
	strcpy( plotfile_base, plotfile_base_default);

	//try to load from file
	if( NULL != filename){
		string line;
		ifstream file( filename);
		while( file.good()){
			//get the key and value
			getline( file, line);
			int splitLoc = line.find('=');
			if( string::npos == splitLoc)
				continue;
			string key = line.substr( 0, splitLoc);
			string value = line.substr( splitLoc + 1);

			istringstream valueStream( value);
			//apply the value to the relevant key
			if( 0 == key.compare("population_size")){
				int newField;
				if( valueStream >> newField)
					population_size = newField;
				else
					printf("Reading field 'population_size' failed.\n");}
			else if( 0 == key.compare("dimensionality")){
				int newField;
				if( valueStream >> newField)
					dimensionality = newField;
				else
					printf("Reading field 'dimensionality' failed.\n");}
			else if( 0 == key.compare("mutation_constant")){
				double newField;
				if( valueStream >> newField)
					mutation_constant = newField;
				else
					printf("Reading field 'mutation_constant' failed.\n");}
			else if( 0 == key.compare("crossover_rate")){
				double newField;
				if( valueStream >> newField)
					crossover_rate = newField;
				else
					printf("Reading field 'crossover_rate' failed.\n");}
			else if( 0 == key.compare("x_min")){
				double newField;
				if( valueStream >> newField)
					x_min = newField;
				else
					printf("Reading field 'x_min' failed.\n");}
			else if( 0 == key.compare("x_max")){
				double newField;
				if( valueStream >> newField)
					x_max = newField;
				else
					printf("Reading field 'x_max' failed.\n");}
			else if( 0 == key.compare("nGenerations")){
				int newField;
				if( valueStream >> newField)
					nGenerations = newField;
				else
					printf("Reading field 'nGenerations' failed.\n");}
			else if( 0 == key.compare("functionType")){
				int newField;
				if( valueStream >> newField)
					switch( newField){
						case DeJong_ftype:
							functionType = Function::DeJong;
							break;
						case APHE_ftype:
							functionType = Function::APHE;
							break;
						case Schwefel_ftype:
							functionType = Function::Schwefel;
							break;
						case Valley_ftype:
							functionType = Function::Valley;
							break;
						case Banana_ftype:
							functionType = Function::Banana;
							break;
						default:
							functionType = Function::Null;
							break;}
				else
					printf("Reading field 'functionType' failed.\n");}
			else if( 0 == key.compare("datafile")){
				strcpy( datafile, value.c_str());}
			else if( 0 == key.compare("plotfile_base")){
				strcpy( plotfile_base, value.c_str());}
			else
				printf("Failed to interpret key '%s'\n",key.c_str());}
		//done
		file.close();}}

Configuration::~Configuration(){
	delete[] datafile;
	delete[] plotfile_base;}	
