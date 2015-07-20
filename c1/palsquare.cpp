/*
ID: rodrigo40
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

bool isPalindrome(string str) {
    int l = 0;
    int r = str.length() - 1;

    while (l < r) {
        if (str[l] != str[r]) {
            return false;
        }
        l++;
        r--;
    }

    return true;
}

char numberToChar(int number) {
    if (number < 10) {
        return '0' + number;
    }

    string aux = "ABCDEFGHIJ";
    return aux[number - 10];
}

string convertToBase(int number, int base) {
    string result = "";
    while (number > 0) {
        result += numberToChar(number % base);
        number /= base;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    ofstream fout ("palsquare.out");
    ifstream fin ("palsquare.in");
    int base;
    fin >> base;

    for (int i = 1; i <= 300; i++) {
        int square = i*i;
        string squareInBase = convertToBase(square, base);
        if (isPalindrome(squareInBase)) {
            fout << convertToBase(i, base) << " " << squareInBase << endl;
        }
    }
    return 0;
}
