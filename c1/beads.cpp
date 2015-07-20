/*
ID: rodrigo40
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int countRight(string str, int i, char ch) {
    int tmp = i;
    while (i < str.length() && (str[i] == ch || str[i] == 'w')) {
        i++;
    }

    return i - tmp;
}

int countLeft(string str, int i, char ch) {
    int tmp = i;
    while (i >= 0 && (str[i] == ch || str[i] == 'w')) {
        i--;
    }

    return tmp - i;
}

int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    int n;
    string beads;
    fin >> n >> beads;

    int output = 0;
    beads += beads;
    for (int i = 0; i < beads.length(); i++) {
        int maxRight = max(countRight(beads, i + 1, 'r'), countRight(beads, i + 1, 'b'));
        int maxLeft = max(countLeft(beads, i, 'r'), countLeft(beads, i, 'b'));
        output = max(output, maxRight + maxLeft);
    }

    fout << min(n, output) << endl;
    return 0;
}
