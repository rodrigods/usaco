/*
ID: rodrigo40
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

#define DAYS 7
#define MONTHS 12
#define START_YEAR 1900

using namespace std;

int daysInMonth(int year, int month) {
    // Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
    int helper[MONTHS] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 1) {
        if (year % 4 == 0) {
            if (year % 100 != 0 || year % 400 == 0) {
                return 29;
            }
        }
    }
    return helper[month];
}

int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    // Sat, Sun, Mon, Tue, Wed, Thu, Fri
    int counter[DAYS] = {0, 0, 0, 0, 0, 0, 0};

    int years;
    fin >> years;

    int day = 2;
    for (int y = 0; y < years; y++) {
        int year = START_YEAR + y;
        for (int month = 0; month < MONTHS; month++) {
            int days = daysInMonth(year, month);
            for (int date = 1; date <= days; date++) {
                if (date == 13) {
                    counter[day]++;
                }
                day++;
                day %= DAYS;
            }
        }
    }

    fout << counter[0];
    for (int i = 1; i < DAYS; i++) {
        fout << " " << counter[i];
    }
    fout << "\n";
    return 0;
}
