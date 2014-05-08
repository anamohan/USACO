/*
	ID: anandag2
	PROG: beads
	LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>


using namespace std;


int N;
string beads;

int mod(int n, int m) {
    while (n < 0) {
        n += m;
    }
    return n % m;
}

int break_necklace(int p, int dir) {
    int i = (dir > 0) ? p : mod(p - 1, N);
    char color = 'w';
    int n;
    for (n = 0; n < N; n++, i = mod(i + dir, N)) {
        if (color == 'w' && beads[i] != 'w') {
            color = beads[i];
        }
        if (color != 'w' && beads[i] != 'w' && beads[i] != color) {
            break;
        }
    }
    return n;
}


int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");

    fin >> N;
    fin >> beads;

    int n, m;
    m = 0;
    for (int i = 0; i < N; i++) {
        n = break_necklace(i, 1) + break_necklace(i, -1);
        if (n > m) {
            m = n;
        }
    }
    if (m > N) {
        m = N;
    }
    fout << m << endl;

    return 0;
}