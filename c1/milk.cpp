/*
ID: rodrigo40
PROG: milk
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool farmersCompare(const pair<int, int> &f1, const pair<int, int> &f2) {
    return f1.first < f2.first;
}

int main() {
    ofstream fout ("milk.out");
    ifstream fin ("milk.in");
    int n, m;
    fin >> n >> m;

    vector<pair<int, int> > farmers;
    for (int i = 0; i < m; i++) {
        int price, amount;
        fin >> price >> amount;
        farmers.push_back(make_pair(price, amount));
    }
    sort(farmers.begin(), farmers.end(), farmersCompare);

    int minSpent = 0;
    for (int i = 0; i < m; i++) {
        int buying = n > farmers[i].second ? farmers[i].second : n;
        minSpent += buying * farmers[i].first;
        n -= buying;
        if (n == 0) break;
    }
    fout << minSpent << endl;
    return 0;
}
