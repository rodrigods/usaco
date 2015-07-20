/*
ID: rodrigo40
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

unsigned int nameCount(string name) {
    unsigned int count = name[0] - 'A' + 1;
    for (int i = 1; i < name.length(); i++) {
        count *= name[i] - 'A' + 1;
    }
    return count;
}

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string comet, group;
    fin >> comet;
    fin >> group;

    unsigned int cometCount = nameCount(comet);
    unsigned int groupCount = nameCount(group);
    if (cometCount % 47 == groupCount % 47) {
        fout << "GO\n";
    } else {
        fout << "STAY\n";
    }
    return 0;
}
