#
# Makefile för att kompilera programmet lab1-5 med g++
#
CCC = g++
CCFLAGS = -g -std=c++11 -pedantic -Wall -Wextra
LDFLAGS = -L/sw/gcc-${GCC4_V}/lib -static-libstdc++

mlab1-5: lab1_5.o List.o 
	$(CCC) $(CCFLAGS) $(LDFLAGS) lab1_5.o List.o  -o main

lab1_5.o: lab1_5.cc
	$(CCC) $(CCFLAGS) -c main.cc

List.o: List.cc List.h
	$(CCC) $(CCFLAGS) -c List.cc List.h

clean:
	@ \rm -f *.o 
