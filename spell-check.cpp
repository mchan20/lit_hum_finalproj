#include <iostream>
#include <algorithm>
#include <random>
using namespace std;

#include "bst-2.h"
#include "myfilereader.h"

void print_node(BST::Node *node)
{
    cout << node->get() << " ";
}

int main(int argc, char **argv)
{
	if (argc != 3) {
        cerr << "usage: spell-check <dictionary_file> <file_name>" << endl;
        exit(1);
    }
	
	const char *dictionary = argv[1];
	const char *filename = argv[2];
	MyFileReader d(dictionary);
	MyFileReader f(filename);
	
	// Construct an empty tree
	BST t;

	//tokenize all lines, and if the vector is not empty, then insert onto BST
	int tokens = 0;
	
	//create storage vector for randomization
	vector<string> store;	
	
	while (!d.haveAllLinesBeenRead()) {
		vector<string> v;
		d.tokenizeLine(v);
		if (v.size() > 0) {
			for (auto s : v) {
				store.push_back(s);
				tokens++;
			}
		}
	}
	
	/*
	//randomize store	
	int size = store.size();
	for(int i=0;i<size;i++) {
		srand(100);
		//range should be store.size()-i-1, start of range should be i+1
		int random = (i+1) + (rand() % (size-(i+1)));
		string temp = store[i];
		store[i] = store[random];
		store[random] = temp;
	}
	
	*/
	
	random_shuffle(store.begin(), store.end());	
	
	//insert into bianary tree
	for (auto s : store) {
		t.insert(s);
	}			
	
	cout << "Dictionary info:" << endl;
	cout << "  Tokens read:    " << tokens << endl;
	
	//count number of tokens in tree
	cout << "  Tree size:      " << t.count() << endl;
	cout << "  Tree height:    " << t.height() << endl;

	//calculate balance index
	double b_index = (t.height() + 1) / ceil(log2(tokens + 1));
	cout << "  Balance index:  " << b_index << endl;
	
	//spell check file
	cout << '\n' << "Misspelled tokens in istringstream-test.cpp:" << endl;
	while (!f.haveAllLinesBeenRead()) {
		vector<string> v;		
		f.tokenizeLine(v);
		int lineno = f.getCurrentLineNumber() - 1;
		if (v.size() > 0) {
			// first print line number
			
			vector<string> temp;	
			for (auto s : v) {
				if (t.lookup(s) == NULL) temp.push_back(s);
			}
			
			if (temp.size() > 0) { 
				cout << "[" << setw(4) << lineno << "]";
				
				for (auto s : temp) {
					cout << ' ' << s;
				}
				cout << endl;
			}
		}
	}	
	return 0;	
}
