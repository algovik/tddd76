#
# Makefile för att kompilera Expression_Tree med g++
#
CCC = g++
CCFLAGS += -g -std=c++11 -std=c++11 -Wpedantic -Wall -Wextra -Werror
# LDFLAGS += -L/sw/gcc-${GCC4_V}/lib -static-libstdc++

expression_tree-test: expression_tree-test.o Expression_Tree.o
	$(CCC) $(CCFLAGS) $(LDFLAGS) expression_tree-test.o Expression_Tree.o -o expression_tree-test

expression_tree-test.o: expression_tree-test.cc
	$(CCC) $(CCFLAGS) -c expression_tree-test.cc

Expression_Tree.o: Expression_Tree.cc Expression_Tree.h
	$(CCC) $(CCFLAGS) -c Expression_Tree.cc

clean:
	@ \rm -f *.o *.gch core

zap: clean
	@ \rm -f *~ string-test string-conversion-test string-iterator-test
