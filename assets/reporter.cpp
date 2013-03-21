//libarary includes
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
//override include
#include "reporter.h"

Reporter::Reporter( const Configuration& conf){
	datafile.open( conf.datafile, std::ofstream::trunc);
	fail = ! datafile.good();
	datafile_path = new char[128];
	strcpy( datafile_path, conf.datafile);
	plotfile_base = new char[128];
	strcpy( plotfile_base, conf.plotfile_base);}

Reporter::~Reporter(){
	delete[] datafile_path;
	delete[] plotfile_base;}

void Reporter::capture( Population& p,
		const int& i){
	//assure we can read
	if( ! datafile.good()){
		fail = true;
		return;}
	//setup
	char* buffer = new char[50];
	//write the first part
	sprintf( buffer, "%d, %f, %f, %f",
		i, p.best(), p.average(), p.worst());
	datafile << buffer << std::endl;
	//done, clean up
	datafile.flush();
	delete[] buffer;}

void Reporter::finish( ){
	datafile.close();
	//call the script to dray the plot
	char* buffer = new char[256];
	sprintf( buffer, "scripts/makeplot.m %s %s &> %s.log2",
		datafile_path, plotfile_base, plotfile_base);
	if( debug_reporter) printf("running: '%s'\n", buffer);
	system( buffer);
	//clean up
	delete[] buffer;}