main : main.o myfilereader.o bst-2.o
	g++ -Wall -g -std=c++11 main.o myfilereader.o bst-2.o -o main

main.o : main.cpp bst-2.h myfilereader.h
	g++ -Wall -g -std=c++11 -c main.cpp bst-2.h myfilereader.h 

myfilereader.o : myfilereader.cpp myfilereader.h
	g++ -Wall -g -std=c++11 -c myfilereader.cpp myfilereader.h

bst-2.o : bst-2.cpp bst-2.h
	g++ -Wall -g -std=c++11 -c bst-2.cpp bst-2.h

.PHONY: clean
clean: 
	rm -f *.o *.gch a.out core main

.PHONY: all
all:
	clean main
