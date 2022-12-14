#include <iostream>
#include <algorithm>
#include <random>
#include <utility>
#include <fstream>
using namespace std;

#include "bst-2.h"
#include "myfilereader.h"

void print_node(BST::Node *node)
{
    cout << node->get() << " ";
}

int main()
{

	const char* iliad = "illiad.txt";
	const char* aeneid = "bartsch.vergil.aeneid.txt";

	MyFileReader i(iliad);
	MyFileReader a(aeneid);
	

	vector<vector<string> > store;
	vector<int> illiad_line_nums;
	vector<int> illiad_line_nums_books;
	
	int book = 0;
	int line = 0;

	//start reading the illiad
	ofstream test("test.txt", ofstream::out | ofstream::trunc);
	while (!i.haveAllLinesBeenRead()) {
		vector<string> v;
		i.tokenizeLine(v);
		if (v.size() > 0) {
			for (auto s : v) {
				test << s << ' ';
			}
			test << endl;
		}
	}

	MyFileReader inew("test.txt");
	while (!inew.haveAllLinesBeenRead()) {
		vector<string> v;
		inew.tokenizeLine(v);
		inew.tokenizeLine(v);
		inew.tokenizeLine(v);
		if (v.size() > 0) {
			line++;
			for (auto s : v) {
				if (s == "book")  {
					book++;
					line = 0;
					break;
				}
				else if (s == "tear" || 
					s == "tears" || 
					s == "weep" || 
					s == "wept" || 
					s == "mourning" || 
					s == "grieve" || 
					s == "grieving")  {
					store.push_back(v);
					illiad_line_nums.push_back(line);
					illiad_line_nums_books.push_back(book);
					break;
				}
			}
		}
	}


	vector<vector<string> > store_two;
	vector<int> aeneid_line_nums;
	vector<int> aeneid_line_nums_books;
	//start reading the aeneid 

	book = 0;
	line = 0;

	ofstream test_two("test.txt", ofstream::out | ofstream::trunc);
	while (!a.haveAllLinesBeenRead()) {
		vector<string> v;
		a.tokenizeLine(v);
		if (v.size() > 0) {
			for (auto s : v) {
				test_two << s << ' ';
			}
			test_two << endl;
		}
	}

	MyFileReader anew("test.txt");
	while (!anew.haveAllLinesBeenRead()) {
		vector<string> v;
		anew.tokenizeLine(v);
		anew.tokenizeLine(v);
		anew.tokenizeLine(v);
		if (v.size() > 0) {
			// if vector is certain size, 
			line++;
			for (auto s : v) {
				if (s == "book")  {
					book++;
					line = 0;
					break;
				}
				else if (s == "tear" || 
					s == "tears" || 
					s == "weep" || 
					s == "wept" || 
					s == "mourning" || 
					s == "grieve" || 
					s == "grieving")  {
					store_two.push_back(v);
					aeneid_line_nums.push_back(line);
					aeneid_line_nums_books.push_back(book);
					break;
				}
			}
		}
	}	

	
	cout << "hi" << endl;

	ofstream il_file("illiad.csv", ofstream::out | ofstream::trunc);
	// print out the illiad
	cout << "ILLIAD" << endl;
	il_file << "book,line,text" << endl;
	int lineno = 0;
	for (auto s : store) {
		// uncomment for pretty printing;
		// cout << "[" << setw(2) << illiad_line_nums_books[lineno] << "]" << ' ';
		// cout << "[" << setw(5) << illiad_line_nums[lineno] << "]";
		il_file << illiad_line_nums_books[lineno] << ',' << illiad_line_nums[lineno]*3 << ',';
		for (auto l : s) {
			il_file << l << ' ';
		}
		il_file << endl;
		lineno++;
	}

	ofstream an_file("aeneid.csv", ofstream::out | ofstream::trunc);
	// print out the aeneid
	lineno = 0;
	cout << "AENEID" << endl;
	an_file << "book,line,text" << endl;
	for (auto s : store_two) {
		// uncomment for pretty printing
		// cout << "[" << setw(2) << aeneid_line_nums_books[lineno] << "]" << ' ';
		// cout << "[" << setw(5) << aeneid_line_nums[lineno] << "]";
		an_file << aeneid_line_nums_books[lineno] << ',' << aeneid_line_nums[lineno]*3 << ',';
		for (auto l : s) {
			an_file << l << ' ';
		}
		an_file << endl;
		lineno++;
	}
	
	/*

	//spell check file
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
	*/
	return 0;	
}
