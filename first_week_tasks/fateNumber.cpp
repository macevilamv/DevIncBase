#include <iostream>

using namespace std;

int sumDigits(int number);

int main()
{
    int day = 0;
    int month = 0;
    int year = 0;
    const int MAX_YEAR = 2022;
    const int MIN_YEAR = 1900;
    const int MAX_DAY = 31;
    const int MIN_DAY = 1;
    const int MAX_MONTH = 12;
    const int MIN_MONTH = 1;
    int numberOfFate = 0;

    cout << "Enter your birth day: ";
    cin >> day;
    cout << "Enter your birth month: ";
    cin >> month;
    cout << "Enter your birth year: ";  
    cin >> year;

    if (day > MAX_DAY or day < MIN_DAY) {
        cout << "Error! Incorrect input: day is: " << day;
        return 1;
    }
    if (month > MAX_MONTH or month < MIN_MONTH) {
        cout << "Error! Incorrect input: month is: " << month;
        return 2;
    }
    if (year > MAX_YEAR or year < MIN_YEAR) {
        cout << "Error! Incorrect input: year is: " << year;
        return 3;
    }
    
    numberOfFate = sumDigits(sumDigits(day) + sumDigits(month) + sumDigits(year));
    
    cout << "Your number of fate is: " << numberOfFate << endl;

    return 0;
}

int sumDigits(int number)
{
        int result = 0;

        while (number > 0)
        {
            result += number % 10;
            number /= 10;
        }

        return result;
}
