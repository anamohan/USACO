/*
	ID: anandag2
	PROG: friday
	LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <cstring>


using namespace std;

int num_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int days[] = {0, 1, 2, 3, 4, 5, 6};
int count_days[7];

bool is_leap_year(int year) {
    if (year % 100 == 0) {
        if (year % 400 == 0)
            return true;
        return false;
    }
    if (year % 4 == 0) return true;
	return false;
}

int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    int N;
    fin >> N;
    int start_year = 1900, curr_year;
    int day = 1;
    memset(count_days, 0, sizeof count_days);
    for (int i = 0; i < N; i++) {
    	curr_year = start_year + i;
    	for (int j = 0; j < 12; j++) {
    		count_days[(day + 12) % 7] += 1;
            day += num_days[j];
    		if (j == 1 && is_leap_year(curr_year)) {
    			day++;
    		}
    		day %= 7;
    	}
    }
    fout << count_days[6] << " " << count_days[0] << " " << count_days[1] << " ";
    fout << count_days[2] << " " << count_days[3] << " " << count_days[4] << " ";
    fout << count_days[5] << endl;

    return 0;
}