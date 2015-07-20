/*
ID: rodrigo40
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compareGap(const pair<int, int> &g1, const pair<int, int> &g2) {
    return (g1.second - g1.first) < (g2.second - g2.first);
}

int main() {
    ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");
    int maxBoards, stalls, cowsCount;
    fin >> maxBoards >> stalls >> cowsCount;

    vector<int> cows;
    for (int i = 0; i < cowsCount; i++) {
        int s;
        fin >> s;
        cows.push_back(s);
    }
    sort(cows.begin(), cows.end());

    bool covered[stalls + 1];
    for (int i = 0; i <= stalls; i++) {
        if (i >= cows[0] && i <= cows[cowsCount-1]) {
            covered[i] = true;
        } else {
            covered[i] = false;
        }
    }

    vector<pair<int, int> > gaps;
    for (int i = 1; i < cowsCount; i++) {
        gaps.push_back(make_pair(cows[i-1], cows[i]));
    }
    sort(gaps.begin(), gaps.end(), compareGap);

    int idx = gaps.size() - 1;
    int boards = 1;
    while (idx >= 0 && boards < maxBoards) {
        for (int j = gaps[idx].first + 1; j <= gaps[idx].second - 1; j++) {
            covered[j] = false;
        }
        idx--;
        boards++;
    }

    int count = 0;
    for (int i = 0; i <= stalls; i++) {
        if (covered[i]) {
            count++;
        }
    }

    fout << count << endl;
    return 0;
}
