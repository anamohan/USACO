/*
	ID: anandag2
	PROG: ride
	LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string a, b;
    fin >> a >> b;
    int prod_a = 1, prod_b = 1;
    for (int i = 0; i < a.length(); i++) {
    	prod_a *= (a[i] - 'A' + 1);
    }
    prod_a = prod_a % 47;
    for (int i = 0; i < b.length(); i++) {
    	prod_b *= (b[i] - 'A' + 1);
    }
    prod_b = prod_b % 47;
    if (prod_a == prod_b) {
    	fout <<"GO"<<endl;
    } else {
    	fout <<"STAY"<<endl;
    }
    return 0;
}
