#globals
default: all
freshen: clean all
clean: clean-special
	tools/cleandir .
	tools/cleandir assets
	tools/cleandir tests
	tools/cleandir tools
clean-special:
	rm -rf documentation
	rm -f solver
	rm -rf results/*
docs: doxyfile
	doxygen
docs-view: docs
	chromium-browser documentation/html/index.html

#git
git-prepare: clean
	git add -u
	git add *

#groups
all: locals assets
locals: \
	DE-lib.a \
	solver
assets: \
	assets/entity.o \
	assets/population.o
commands:
tests: \
	tests/testEntity.out \
	tests/testPopulation.out \
	tests/testVector.out
resources: \
	data/run.csv \
	data/plot.png

#locals
DE-lib.a: \
		assets/configuration.o \
		assets/entity.o \
		assets/function.o \
		assets/globals.o \
		assets/population.o \
		assets/reporter.o \
		assets/vector.o
	ar rc DE-lib.a \
		assets/configuration.o \
		assets/entity.o \
		assets/function.o \
		assets/globals.o \
		assets/population.o \
		assets/reporter.o \
		assets/vector.o
	ranlib DE-lib.a

solver.o: \
		solver.cpp \
		DE-lib.h \
		assets/configuration.h \
		assets/debug.h \
		assets/entity.h \
		assets/globals.h \
		assets/population.h \
		assets/reporter.h
	g++ -c -o solver.o \
		solver.cpp
solver: \
		solver.o \
		DE-lib.a
	g++ -o solver \
		solver.o \
		DE-lib.a

#assets
assets/configuration.o: \
		assets/configuration.h \
		assets/configuration.cpp
	g++ -c -o assets/configuration.o \
		assets/configuration.cpp
assets/entity.o: \
		assets/debug.h \
		assets/vector.h \
		assets/entity.h \
		assets/entity.cpp
	g++ -c -o assets/entity.o \
		assets/entity.cpp
assets/function.o: \
		assets/debug.h \
		assets/vector.h \
		assets/function.h \
		assets/function.cpp
	g++ -c -o assets/function.o \
		assets/function.cpp
assets/globals.o: \
		assets/globals.h \
		assets/globals.cpp
	g++ -c -o assets/globals.o \
		assets/globals.cpp
assets/population.o: \
		assets/debug.h \
		assets/entity.o \
		assets/population.h \
		assets/population.cpp
	g++ -c -o assets/population.o \
		assets/population.cpp
assets/reporter.o: \
		assets/debug.h \
		assets/entity.o \
		assets/population.o \
		assets/reporter.h \
		assets/reporter.cpp
	g++ -c -o assets/reporter.o \
		assets/reporter.cpp
assets/vector.o: \
		assets/debug.h \
		assets/vector.h \
		assets/vector.cpp
	g++ -c -o assets/vector.o \
		assets/vector.cpp

#tests
test-s: test-solver
test-solver: solver
	./solver

test-e: test-entity
test-entity: tests/testEntity.out
	tests/testEntity.out
tests/testEntity.out: \
		tests/testEntity.o \
		DE-lib.a
	g++ -o tests/testEntity.out \
		tests/testEntity.o \
		DE-lib.a
tests/testEntity.o: \
		tests/testEntity.cpp \
		assets/debug.h \
		assets/entity.h
	g++ -c -o tests/testEntity.o \
		tests/testEntity.cpp

test-p: test-population
test-population: tests/testPopulation.out
	tests/testPopulation.out
tests/testPopulation.out: \
		tests/testPopulation.o \
		DE-lib.a
	g++ -o tests/testPopulation.out \
		tests/testPopulation.o \
		DE-lib.a
tests/testPopulation.o: \
		tests/testPopulation.cpp \
		assets/debug.h \
		assets/entity.h
	g++ -c -o tests/testPopulation.o \
		tests/testPopulation.cpp

test-c: test-configuration
test-configuration: tests/testConfiguration.out
	tests/testConfiguration.out
tests/testConfiguration.out: \
		tests/testConfiguration.o \
		DE-lib.a
	g++ -o tests/testConfiguration.out \
		tests/testConfiguration.o \
		DE-lib.a
tests/testConfiguration.o: \
		tests/testConfiguration.cpp \
		assets/debug.h \
		assets/entity.h
	g++ -c -o tests/testConfiguration.o \
		tests/testConfiguration.cpp

test-v: test-vector
test-vector: tests/testVector.out
	tests/testVector.out
tests/testVector.out: \
		tests/testVector.o \
		assets/vector.o
	g++ -o tests/testVector.out \
		tests/testVector.o \
		assets/vector.o
tests/testVector.o: \
		tests/testVector.cpp \
		assets/debug.h \
		assets/vector.h
	g++ -c -o tests/testVector.o \
		tests/testVector.cpp

test-f: test-function
test-function: tests/testFunction.out
	tests/testFunction.out
tests/testFunction.out: \
		tests/testFunction.o \
		assets/function.o \
		assets/vector.o
	g++ -o tests/testFunction.out \
		tests/testFunction.o \
		assets/function.o \
		assets/vector.o
tests/testFunction.o: \
		tests/testFunction.cpp \
		assets/debug.h \
		assets/function.h \
		assets/vector.h
	g++ -c -o tests/testFunction.o \
		tests/testFunction.cpp
