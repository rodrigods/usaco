/*
ID: rodrigo40
PROG: dualpal
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
    return '0' + number;
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
    ofstream fout ("dualpal.out");
    ifstream fin ("dualpal.in");
    int n, s;
    fin >> n >> s;

    int candidate = s + 1;
    int counter = 0;
    while (counter < n) {
        int palindromeCounter = 0;
        for (int i = 2; i <= 10; i++) {
            string candidateInBase = convertToBase(candidate, i);
            if (isPalindrome(candidateInBase)) {
                palindromeCounter++;
            }

            if (palindromeCounter >= 2) {
                break;
            }
        }
        if (palindromeCounter >= 2) {
            fout << candidate << endl;
            counter++;
        }
        candidate++;
    }
    return 0;
}
