#
# Makefile för att kompilera programmet lab1-5 med g++
#
CCC = g++
CCFLAGS = -g -std=c++11 -pedantic -Wall -Wextra
# LDFLAGS = -L/sw/gcc-${GCC4_V}/lib -static-libstdc++

lab1-5: lab1-5.o List.o
	$(CCC) $(CCFLAGS) $(LDFLAGS) lab1-5.o List.o -o main

lab1-5.o: lab1-5.cc
	$(CCC) $(CCFLAGS) -c lab1-5.cc

List.o: List.cc List.h
	$(CCC) $(CCFLAGS) -c List.cc List.h

clean:
	@ \rm -f *.o
