/*
ID: rodrigo40
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

ofstream fout ("namenum.out");
ifstream fin ("namenum.in");
set<string> names;
map<int, string> dict;
bool found = false;

void initDict() {
    dict['2'] = "ABC";
    dict['3'] = "DEF";
    dict['4'] = "GHI";
    dict['5'] = "JKL";
    dict['6'] = "MNO";
    dict['7'] = "PRS";
    dict['8'] = "TUV";
    dict['9'] = "WXY";
}

void readNames() {
    ifstream reader ("dict.txt");
    while (!reader.eof()) {
        string name;
        reader >> name;
        names.insert(name);
    }
}

void genCandidates(string number, string curr, int i) {
    if (i == number.length()) {
        if (names.count(curr)) {
            fout << curr << endl;
            found = true;
        }
        return;
    }

    string values = dict[number[i]];
    for (int j = 0; j < values.length(); j++) {
        curr += values[j];
        genCandidates(number, curr, i + 1);
        curr = curr.substr(0, curr.length() - 1);
    }
}

int main() {
    initDict();
    readNames();
    string number;
    fin >> number;

    genCandidates(number, "", 0);
    if (!found) {
        fout << "NONE" << endl;
    }
    return 0;
}
