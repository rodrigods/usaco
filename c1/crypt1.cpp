/*
ID: rodrigo40
PROG: crypt1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <cstdlib>

using namespace std;

vector<int> input;
set<string> n1Set;
set<string> n2Set;

void getNumbers(string curr, int size) {
    if (curr.length() == size) {
        if (size == 3) n1Set.insert(curr);
        if (size == 2) n2Set.insert(curr);
        return;
    }

    for (int j = 0; j < input.size(); j++) {
        curr += (input[j] + '0');
        getNumbers(curr, size);
        curr = curr.substr(0, curr.length() - 1);
    }
}

bool isValid(int number) {
    while (number) {
        int digit = number % 10;
        bool found = false;
        for (int j = 0; j < input.size(); j++) {
            if (digit == input[j]) {
                found = true;
                break;
            }
        }
        if (!found) return false;

        number /= 10;
    }
    return true;
}

int numberSize(int number) {
    int size = 0;
    while (number) {
        number /= 10;
        size++;
    }

    return size;
}

bool checkTerm(int number, int size) {
    if (numberSize(number) != size) {
        return false;
    }

    return isValid(number);
}


int main() {
    ofstream fout ("crypt1.out");
    ifstream fin ("crypt1.in");
    int n;
    fin >> n;

    for (int i = 0; i < n; i++) {
        int d;
        fin >> d;
        input.push_back(d);
    }

    getNumbers("", 3);
    getNumbers("", 2);

    vector<string> n1(n1Set.begin(), n1Set.end());
    vector<string> n2(n2Set.begin(), n2Set.end());

    int counter = 0;
    for (int i = 0; i < n1.size(); i++) {
        int abc = atoi(n1[i].c_str());

        for (int j = 0; j < n2.size(); j++) {
            string de = n2[j];
            int p1 = (de[0] - '0') * abc;
            int p2 = (de[1] - '0') * abc;

            if (!checkTerm(p1, 3) || !checkTerm(p2, 3)) {
                continue;
            }

            p2 *= 10;
            int result = p1 + p2;
            if (checkTerm(result, 4)) {
                counter++;
            }
        }
    }

    fout << counter << endl;
    return 0;
}
