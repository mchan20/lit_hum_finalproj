#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    string str("   SOME  LONG    STRING\twith\nSPACES    ");
    
    istringstream iss(str);

    string s;
    while (iss >> s) {
        cout << "[" << s << "]" << endl;
    }
    return 0;
}
