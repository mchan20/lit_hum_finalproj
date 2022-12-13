#ifndef MYFILEREAD
#define MYFILEREAD

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <vector> 

using namespace std;

class MyFileReader {
	public: 

	//constructor
	MyFileReader(const char* filename);
	
	//close the file
	~MyFileReader();

	//get next line and add it to buffer
	int getLine(char *buffer, int size);

	int getCurrentLineNumber();
	
	void tokenizeLine(vector<string>& vec);
	
	bool haveAllLinesBeenRead() const;
	private:
	
	FILE *fp;
	
	int line = 1;	
	
	bool all_lines_read = false;
	// disallow copy ctor & op=()
	MyFileReader(const MyFileReader&);
	MyFileReader& operator=(const MyFileReader&);
};


#endif
