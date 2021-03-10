all: checker gen merger

checker: checker.o
	g++ -o checker checker.o
gen: generator.o
	g++ -o gen generator.o
merger: merger.o
	g++ -o merger merger.o
checker.o: checker.cpp
	g++ -c checker.cpp
generator.o: generator.cpp
	g++ -c generator.cpp
merger.o: merger.cpp
	g++ -c merger.cpp
clean:
	rm -f *.o *~
