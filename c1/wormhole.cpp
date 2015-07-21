/*
ID: rodrigo40
PROG: wormhole
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ofstream fout ("wormhole.out");
    ifstream fin ("wormhole.in");
    int n;
    fin >> n;

    vector<pair<int, int> > holes;
    for (int i = 0; i < n; i++) {
        int x, y;
        fin >> x >> y;
        holes.push_back(make_pair(x, y));
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;

            if (holes[i].second == holes[j].second && holes[i].first < holes[j].first) {
                // count += holes[j].first - holes[i].first;
                count++;
            }
        }
    }
    fout << count << endl;
    return 0;
}
