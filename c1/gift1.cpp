/*
ID: rodrigo40
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
    int np;
    fin >> np;

    string name;
    vector<string> names;
    map<string, int> members;
    for (int i = 0; i < np; i++) {
        fin >> name;
        names.push_back(name);
        members[name] = 0;
    }

    for (int i = 0; i < np; i++) {
        fin >> name;

        int amount, n;
        fin >> amount >> n;

        if (n > 0) {
            members[name] -= (amount - (amount % n));
            for (int j = 0; j < n; j++) {
                fin >> name;
                members[name] += amount / n;
            }
        }
    }

    for (int i = 0; i < np; i++) {
        fout << names[i] << " " << members[names[i]] << '\n';
    }
    return 0;
}
