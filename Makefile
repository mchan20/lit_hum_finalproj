main : main.o myfilereader.o 
	g++ -Wall -g -std=c++11 main.o myfilereader.o  -o main

main.o : main.cpp myfilereader.h
	g++ -Wall -g -std=c++11 -c main.cpp  myfilereader.h 

myfilereader.o : myfilereader.cpp myfilereader.h
	g++ -Wall -g -std=c++11 -c myfilereader.cpp myfilereader.h


.PHONY: clean
clean: 
	rm -f *.o *.gch a.out core main

.PHONY: all
all:
	clean main
