/*
ID: rodrigo40
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

ofstream fout ("transform.out");
ifstream fin ("transform.in");

vector<string> readMatrix(int n) {
    vector<string> out;
    for (int i = 0; i < n; i++) {
        string line;
        fin >> line;
        out.push_back(line);
    }
    return out;
}

vector<string> reflect(vector<string> matrix) {
    int n = matrix.size();
    vector<string> other;
    for (int i = 0; i < n; i++) {
        other.push_back(matrix[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char ch = matrix[i][j];
            other[i][n - j -1] = ch;
        }
    }

    return other;
}

vector<string> rotate90(vector<string> matrix) {
    int n = matrix.size();
    vector<string> other;
    for (int i = 0; i < n; i++) {
        other.push_back(matrix[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char ch = matrix[i][j];
            other[j][n - i -1] = ch;
        }
    }

    return other;
}

vector<string> rotate180(vector<string> matrix) {
    matrix = rotate90(matrix);
    return rotate90(matrix);
}

vector<string> rotate270(vector<string> matrix) {
    matrix = rotate180(matrix);
    return rotate90(matrix);
}

bool equal(vector<string> m1, vector<string> m2) {
    int n = m1.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (m1[i][j] != m2[i][j]) return false;
        }
    }

    return true;
}

int findTransform(vector<string> orig, vector<string> result, int n) {
    vector<string> r90 = rotate90(orig);
    if (equal(r90, result)) return 1;

    vector<string> r180 = rotate180(orig);
    if (equal(r180, result)) return 2;

    vector<string> r270 = rotate270(orig);
    if (equal(r270, result)) return 3;

    vector<string> ref = reflect(orig);
    if (equal(ref, result)) return 4;

    vector<string> c90 = rotate90(ref);
    vector<string> c180 = rotate180(ref);
    vector<string> c270 = rotate270(ref);
    if (equal(c90, result) || equal(c180, result) || equal(c270, result)) return 5;

    if (equal(orig, result)) return 6;

    return 7;
}

int main() {
    int n;
    fin >> n;

    vector<string> orig = readMatrix(n);
    vector<string> result = readMatrix(n);

    int transformation = findTransform(orig, result, n);
    fout << transformation << endl;
    return 0;
}
