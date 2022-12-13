spell-check : spell-check.o myfilereader.o bst-2.o
	g++ -Wall -g -std=c++11 spell-check.o myfilereader.o bst-2.o -o spell-check

spell-check.o : spell-check.cpp bst-2.h myfilereader.h
	g++ -Wall -g -std=c++11 -c spell-check.cpp bst-2.h myfilereader.h 

myfilereader.o : myfilereader.cpp myfilereader.h
	g++ -Wall -g -std=c++11 -c myfilereader.cpp myfilereader.h

bst-2.o : bst-2.cpp bst-2.h
	g++ -Wall -g -std=c++11 -c bst-2.cpp bst-2.h

.PHONY: clean
clean: 
	rm -f *.o *.gch a.out core spell-check

.PHONY: all
all:
	clean spell-check
