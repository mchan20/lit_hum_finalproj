#include "myfilereader.h"

MyFileReader::MyFileReader(const char* filename) {
	fp = fopen(filename, "r");
    if (fp == NULL) {
        perror(filename);
        exit(1);
    }
}

MyFileReader::~MyFileReader() {
	fclose(fp);
}

int MyFileReader::getLine(char *buffer, int size) {
    // first check if the null pointer is returned
	if (fgets(buffer, size, fp) != NULL) {
//		cout << buffer << "__" << buffer[size-1] << "__"  << flush;
		return (strstr(buffer,"\n") != NULL);
	}
	else {
		return -1;
	}
	
}

int MyFileReader::getCurrentLineNumber() {
    line++;
    return line;
}

void MyFileReader::tokenizeLine(vector<string>& vec) {
	string line = "";
	char buf[10];
    while(1) {
        int result = getLine(buf, sizeof(buf));
        if (result == -1) {
			all_lines_read = true;
			break;
		}
		else if (result == 0) {
			line += buf;
		}
		else if (result == 1) {
			line += buf;
			break;
		}
    }
	
	//start the string parsing
	istringstream iss(line);
	
	string s;
	while (iss >> s) {
		//check for lowercase and alpha
		string temp = "";
		for(string::size_type i=0;i<s.length();i++) {
			if (isalpha(s[i])) temp += tolower(s[i]);
		}

		//add to vector
		if (temp != "") vec.push_back(temp);
	}
}

bool MyFileReader::haveAllLinesBeenRead() const {
	return all_lines_read;		
}
