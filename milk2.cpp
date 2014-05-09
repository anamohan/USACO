/*
	ID: anandag2
	PROG: milk2
	LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

class schedule {
public:
    int start;
    int end;
};

bool schedule_sort(schedule const& lhs, schedule const& rhs) {
    if (lhs.start != rhs.start)
        return lhs.start < rhs.start;
    return lhs.end > rhs.end;
}

int main() {
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    int N;
    fin >> N;
    schedule schedule_list[N];
    
    for (int i = 0; i < N; i++) {
    	fin >> schedule_list[i].start >> schedule_list[i].end;
    }

    sort(schedule_list, schedule_list + N, &schedule_sort);
    int start_time = schedule_list[0].start;
    int end_time = schedule_list[0].end;
    int max_time_activity = end_time - start_time;
    int max_time_no_activity = 0;
    int curr_time_activity = 0, curr_time_no_activity = 0;

    for (int i = 1; i < N; i++) {
        int start = schedule_list[i].start;
        int end   = schedule_list[i].end;
    	if (start > end_time) {
            curr_time_no_activity = start - end_time;
            start_time = start;
            end_time = end;
        } else if (end > end_time) {
            end_time = end;
        }
        curr_time_activity = end_time - start_time;
        if (curr_time_activity > max_time_activity) {
            max_time_activity = curr_time_activity;
        }
        if (curr_time_no_activity > max_time_no_activity) {
            max_time_no_activity = curr_time_no_activity;
        }
    }

    fout << max_time_activity << " " << max_time_no_activity << endl;

    return 0;
}