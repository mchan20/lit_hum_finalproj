#include <iostream>
#include <algorithm>
#include <random>
#include <utility>
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
	
	int temp = 0;
	//start reading the illiad
	while (!i.haveAllLinesBeenRead()) {
		vector<string> v;
		i.tokenizeLine(v);
		if (v.size() > 0) {
			temp++;
			// if vector is certain size, 
			for (auto s : v) {
				if (s == "tear" || 
					s == "tears" || 
					s == "weep" || 
					s == "wept" || 
					s == "mourning" || 
					s == "grieve" || 
					s == "grieving")  {
					store.push_back(v);
					illiad_line_nums.push_back(temp);
					break;
				}
			}
		}
	}	

	vector<vector<string> > store_two;
	vector<int> aeneid_line_nums;
	//start reading the aeneid 

	int temp_two = 0;
	while (!a.haveAllLinesBeenRead()) {
		vector<string> v;
		a.tokenizeLine(v);
		if (v.size() > 0) {
			// if vector is certain size, 
			temp_two++;
			for (auto s : v) {
				if (s == "tear" || 
					s == "tears" || 
					s == "weep" || 
					s == "wept" || 
					s == "mourning" || 
					s == "grieve" || 
					s == "grieving")  {
					store_two.push_back(v);
					aeneid_line_nums.push_back(temp_two);
					break;
				}
			}
		}
	}	
	
	int lineno = 0;
	for (auto s : store) {
		cout << "[" << setw(5) << illiad_line_nums[lineno] << "]" << ' ';
		for (auto l : s) {
			cout << l << ' ';
		}
		cout << endl;
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
