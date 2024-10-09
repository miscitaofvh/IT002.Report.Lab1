#include <bits/stdc++.h>

using namespace std;

// Check Leap Year
bool isLeapYear(int year) 
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) 
    {
        return true;
    }
    return false;
}

// Caculator the number of days in the month
int daysInMonth(int month, int year) {
    switch (month) 
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(year) ? 29 : 28;
        default:
            return 0;
    }
}

// Caculator the previous day
void previousDay(int &day, int &month, int &year) {
    if (day > 1) {
        day--;
    } else {
        if (month > 1) {
            month--;
        } else {
            month = 12;
            year--;
        }
        day = daysInMonth(month, year);
    }
}

// Caculator the next day
void nextDay(int &day, int &month, int &year) {
    int daysInCurrentMonth = daysInMonth(month, year);
    if (day < daysInCurrentMonth) {
        day++;
    } else {
        day = 1;
        if (month < 12) {
            month++;
        } else {
            month = 1;
            year++;
        }
    }
}

// Caculator the number of days in year
int dayOfYear(int day, int month, int year) {
    int dayOfYear = 0;
    for (int i = 1; i < month; i++) {
        dayOfYear += daysInMonth(i, year);
    }
    dayOfYear += day;
    return dayOfYear;
}

int main()
{
    int day, month, year;

    cout << "Enter day: ";
    cin >> day;
    cout << "Enter month: ";
    cin >> month;
    cout << "Enter year: ";
    cin >> year;

    int prevDay = day, prevMonth = month, prevYear = year;
    int nextDayValue = day, nextMonth = month, nextYear = year;

    previousDay(prevDay, prevMonth, prevYear);
    nextDay(nextDayValue, nextMonth, nextYear);

    cout << "The day before " << day << '/' << month << '/' << year << " is: " << prevDay << '/' << prevMonth << '/' << prevYear << endl;
    cout << "The day before " << day << '/' << month << '/' << year << " is: " << nextDay << '/' << nextMonth << '/' << nextYear << endl;
    cout << "The day " << day << '/' << month << '/' << year << " is day " << dayOfYear(day, month, year) << " of the year" << endl;

    return 0;
}