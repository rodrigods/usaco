/*
ID: rodrigo40
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool pairCompare(const pair<int, int> &first, const pair<int, int> &second) {
    return first.first < second.first;
}

int main() {
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    int n;
    fin >> n;
    vector<pair<int, int> > values;

    for (int i = 0; i < n; i++) {
        int begin, end;
        fin >> begin >> end;
        values.push_back(make_pair(begin, end));
    }
    sort(values.begin(), values.end(), pairCompare);

    pair<int, int> milking = values[0];
    int maxMilking = milking.second - milking.first;
    int maxIdle = 0;
    for (int i = 1; i < n; i++) {
        if (values[i].first <= milking.second) {
            milking.second = max(milking.second, values[i].second);
        } else {
            maxMilking = max(maxMilking, milking.second - milking.first);
            maxIdle = max(maxIdle, values[i].first - milking.second);
            milking = values[i];
        }
    }

    fout << maxMilking << " " << maxIdle << endl;
    return 0;
}
