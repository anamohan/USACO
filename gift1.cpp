/*
	ID: anandag2
	PROG: gift1
	LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    map<string, int> spend, received;
    int NP;
    fin >> NP;
    vector<string> names(NP);
    for (int i = 0; i < NP; i++) {
    	fin >> names[i];
    }
    string giver_name, receiver_name;
    int num_receivers, gift_amt;
    for (int i = 0; i < NP; i++) {
    	fin >> giver_name;
    	fin >> gift_amt >> num_receivers;
    	if (num_receivers == 0) continue;
    	int individual_amt = gift_amt / num_receivers;
    	int left_amt = gift_amt % num_receivers;
    	// received[giver_name] += left_amt;
    	spend[giver_name] += (individual_amt * num_receivers);
    	for (int j = 0; j < num_receivers; j++) {
    		 fin >> receiver_name;
    		 received[receiver_name] += individual_amt;
    	}
    }
    for (int i = 0; i < names.size(); i++) {
    	fout << names[i] << " " << received[names[i]] - spend[names[i]] << endl;
    }
    return 0;
}