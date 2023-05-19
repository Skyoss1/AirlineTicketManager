#pragma once
#include <iostream>
using namespace std;
class Date
{
private:
    int day, month, year;
public:
    bool NamNhuan(int year)
    {
        if (year % 400 == 0)
        {
            return true;
        }
        return false;
    }

    int NOD(int month, int year)
    {
        int NumOfDays;
        switch (month)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            NumOfDays = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            NumOfDays = 30;
            break;
        case 2:
            if (NamNhuan(year))
                NumOfDays = 29;
            else
                NumOfDays = 28;
            break;
        }
        return NumOfDays;
    }

    Date(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }


    void input()
    {
        int inputDay, inputMonth, inputYear;

        do {
            cout << "Nhap ngay: ";
            cin >> inputDay;

            if (inputDay <= 0 || inputDay > NOD(inputMonth, inputYear)) {
                cout << "Ngay khong hop le. Nhap lai." << endl;
            }
        } while (inputDay <= 0 || inputDay > NOD(inputMonth, inputYear));

        do {
            cout << "Nhap thang: ";
            cin >> inputMonth;

            if (inputMonth < 1 || inputMonth > 12) {
                cout << "Thang khong hop le. Nhap lai." << endl;
            }
        } while (inputMonth < 1 || inputMonth > 12);

        do {
            cout << "Nhap nam: ";
            cin >> inputYear;

            if (inputYear <= 0) {
                cout << "Nam khong hop le. Nhap lai." << endl;
            }
        } while (inputYear <= 0);

        day = inputDay;
        month = inputMonth;
        year = inputYear;
    }
    void  print()
    {
        cout << day << "/" << month << "/" << year << endl;
    }
};