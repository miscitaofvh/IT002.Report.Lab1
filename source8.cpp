#include <bits/stdc++.h>

using namespace std;

long double sInterestRate = 0.55, lInterestRate = 0.6;
struct Time
{
    int day, month, year;

    Time(int _day = 0, int _month = 0, int _year = 0) : day(_day), month(_month), year(_year) {}
    Time(string openingDate)
    {
        if (openingDate.size() != 10 || openingDate[2] != '/' || openingDate[5] != '/')
        {
            day = 0;
            return;
        }

        for (int i = 0; i < 10; ++i)
        {
            if (i == 2 || i == 5) continue;
            if (openingDate[i] >= 0 && openingDate[i] <= '9') continue;
            day = 0;
            return;
        }

        day = (openingDate[0] - 48) * 10 + (openingDate[1] - 48);
        month = (openingDate[3] - 48) * 10 + (openingDate[4] - 48);
        year = (openingDate[6] - 48) * 1000 + (openingDate[7] - 48) * 100 + (openingDate[8] - 48) * 10 + (openingDate[9] - 48);
    }

    bool operator <= (const Time& v) const
    {
        if (year != v.year)
            return year < v.year;
        if (month != v.month)
            return month < v.month;
        return day <= v.day;
    }

    bool operator < (const Time& v) const
    {
        if (year != v.year)
            return year < v.year;
        if (month != v.month)
            return month < v.month;
        return day < v.day;
    }
};

// Print and exit program
void alert(string msg)
{
    cout << msg << endl;
    exit(0);
}

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

bool checkBookCode(string bookCode)
{
    if (bookCode.size() > 5) return false;
    
    for (auto v : bookCode)
    {
        if (v >= '0' && v <= '9') continue;
        if (v >= 'a' && v <= 'z') continue;
        if (v >= 'A' && v <= 'Z') continue;

        return false;
    }

    return true;
}

bool checkName(string customerName)
{
    if (customerName.size() > 30) return false;

    for (auto v : customerName)
    {
        if (v == ' ') continue;
        if (v >= 'a' && v <= 'z') continue;
        if (v >= 'A' && v <= 'Z') continue;
        
        return false;
    }

    return true;
};

bool checkIDcard(string IDcard)
{
    if (IDcard.size() != 9 && IDcard.size() != 12) return false;

    for (auto v : IDcard)  
    {
        if (v >= '0' && v <= '9') continue;
        return false;
    }

    return true;
}

bool checkOpeningDate(Time openingDate)
{
    if (openingDate.day < 1 || openingDate.month < 1 || openingDate.year < 1 || openingDate.month > 12 || openingDate.day > daysInMonth(openingDate.month, openingDate.year))
        return false;
    return true;
};

bool checkDepositAmount(long double depositAmount)
{
    if (depositAmount > 0) 
        return true;
    return false;
}

bool checkInterestRate(long double interestRate)
{
    if (interestRate <= 0 || interestRate > 1)
        return false;
    return true;
}

struct SavingsBook
{
    string bookCode, typeOfSavingsBook, customerName, IDcard;
    Time openingDate;
    long double depositAmount, currentAmount;

    SavingsBook(string _bookCode = "", string _typeOfSavingsBook = "", string _customerName = "", string _IDcard = "", Time _openingDate = Time(), long double _depositAmount = 0)
    {
        bookCode = _bookCode;
        typeOfSavingsBook = _typeOfSavingsBook;
        customerName = _customerName;
        IDcard = _IDcard;
        openingDate = _openingDate;
        depositAmount = _depositAmount;
        calcInterestRate();
    }

    void write() const
    {
        cout << "Ma so tiet kiem la: " << bookCode << endl;
        cout << "Loai so tiet kiem la: " << typeOfSavingsBook << endl;
        cout << "Ho ten khach hang la: " << customerName << endl;
        cout << "So chung minh nhan dan la: " << IDcard << endl;
        cout << "Ngay mo so la: " << openingDate.day << ' ' << openingDate.month << ' ' << openingDate.year << endl;
        cout << "So tien gui la: " << depositAmount << endl;
        cout << endl;
    }

    // To day is 12/10/2024
    void calcInterestRate()
    {
        currentAmount = 0;
        if (openingDate.month == 10 && openingDate.year == 2024)
            currentAmount = 12 - openingDate.day;
        else
        {
            currentAmount += daysInMonth(openingDate.month, openingDate.year) - openingDate.day;
            if (openingDate.day == 2024)
            {
                for (int i = openingDate.month + 1; i < 10; ++i)
                    currentAmount += daysInMonth(i, 2024);
                currentAmount += 12;
            }
            else
            {
                for (int i = openingDate.month + 1; i <= 12; ++i)
                    currentAmount += daysInMonth(i, openingDate.year);
                for (int i = openingDate.year + 1; i < 2024; ++i)
                    currentAmount += 365 + isLeapYear(i);
                for (int i = 1; i <= 10; ++i) 
                    currentAmount += daysInMonth(i, 2024);
                currentAmount += 12;
            }
        }

        if (currentAmount > 180)
            currentAmount = depositAmount * sInterestRate * currentAmount / 365;
        else 
            currentAmount = depositAmount * lInterestRate * currentAmount / 365;
    }
};

int n;
vector<SavingsBook> savingsBook;
string bookCode, typeOfSavingsBook, customerName, IDcard, _openingDate, exitKey;
Time openingDate;
long double depositAmount, withdrawAmount;

void read()
{
    cin.ignore();
    cout << "Nhap ma so tiet kiem: ";

    getline(cin, bookCode);

    while (!checkBookCode(bookCode))
    {
        cout << "Ma so khong hop le. Nhap lai: ";
        getline(cin, bookCode);
    }

    cout << "Nhap loai hinh so tiet kiem (ngan han hoac dai han): ";
    getline(cin, typeOfSavingsBook);

    while (typeOfSavingsBook != "ngan han" && typeOfSavingsBook != "dai han")
    {
        cout << "Loai hinh so tiet kiem khong ton tai. Nhap lai: ";
        getline(cin, typeOfSavingsBook);
    }     

    cout << "Nhap ho ten khach hang: ";
    getline(cin, customerName);

    while (!checkName(customerName))
    {
        cout << "Ten khach hang sai dinh dang. Nhap lai: ";
        getline(cin, customerName);
    }

    cout << "Nhap so chung minh nhan dan: ";
    getline(cin, IDcard);

    while (!checkIDcard(IDcard))
    {
        cout << "So chung minh nhan dan khong hop le. Nhap lai: ";
        getline(cin, IDcard);
    }

    cout << "Nhap ngay mo so tiet kiem (Format: dd/mm/yyyy): ";
    getline(cin, _openingDate);
    openingDate = Time(_openingDate);

    while (!checkOpeningDate(openingDate))
    {
        cout << "Ngay mo so tiet kiem sai dinh dang. Nhap lai: ";
        getline(cin, _openingDate);
        openingDate = Time(_openingDate);
    }

    cout << "Nhap so tien gui: ";
    cin >> depositAmount;
    while (!checkDepositAmount(depositAmount))
    {
        cout << "So tien gui phai la so duong. Nhap lai: ";
        cin >> depositAmount;
    }

    savingsBook.push_back(SavingsBook(bookCode, typeOfSavingsBook, customerName, IDcard, openingDate, depositAmount));
    
    cout << "Da them thong tin so tiet kiem." << endl;
    cout << endl;
    cin.ignore();
    cout << "Enter to exit";
    getline(cin, exitKey);
    return;
}

void updateInterestRate()
{
    cout << "Nhap lai suat dai han (%/nam): ";
    cin >> lInterestRate;

    while (lInterestRate <= 0 || lInterestRate >= 1)
    {
        cout << "Lai suat dai han phai lon hon 0 va nho hon 1. Nhap lai: ";
        cin >> lInterestRate;
    }

    cout << "Nhap lai suat ngan han (%/nam): ";
    cin >> sInterestRate;

    while (sInterestRate <= 0 || sInterestRate >= lInterestRate)
    {
        cout << "Lai suat ngan han phai lon hon 0 va nho hon lai suat dai han. Nhap lai: ";
        cin >> sInterestRate;
    }
    
    cout << "Da cap nhat lai suat tiet kiem." << endl;
    cout << endl;
    cout << "Enter to exit";
    cin.ignore();
    getline(cin, exitKey);

    return;
}

void withdrawMoney()
{
    if (savingsBook.empty())
    {
        cout << "Khong ton tai bat ki so tiet kiem nao" << endl;
        cout << endl;
        cout << "Enter to exit";
        cin.ignore();
        getline(cin, exitKey);
        return;
    }

    cin.ignore();
    cout << "Neu rut tien bay gio thi lai suat chi duoc tinh voi lai suat " << sInterestRate - 0.01 << "%/nam" << endl;
    cout << "Nhap ma so tiet kiem can rut tien: ";
    getline(cin, bookCode);

    for (auto &v : savingsBook)
        if (v.bookCode == bookCode)
        {
            cout << "Nhap so tien can rut: ";
            cin >> withdrawAmount;

            while (withdrawAmount > v.currentAmount)
            {
                cout << fixed << setprecision(4) << "So du hien tai la: " << v.currentAmount << ". So du khong du de rut. Nhap lai: ";
                cin >> withdrawAmount; 
            }

            v.currentAmount -= withdrawAmount;
            
            cout << "Rut tien thanh cong" << endl;
            cout << endl;
            cout << "Enter to exit";
            cin.ignore();
            getline(cin, exitKey);
            return;
        }

    cout << "Ma so tiet kiem khong ton tai" << endl;
    cout << endl;
    cout << "Enter to exit";
    getline(cin, exitKey);
    return;
}

void findByIDcard()
{
    if (savingsBook.empty())
    {
        cout << "Khong ton tai bat ki so tiet kiem nao" << endl;
        cout << endl;
        cout << "Enter to exit";
        cin.ignore();
        getline(cin, exitKey);
        return;
    }

    cin.ignore();
    cout << "Nhap chung minh dan dan cua so tiet kiem can tim kiem: ";
    getline(cin, IDcard);

    bool ok = false;

    for (auto v : savingsBook)
        if (v.IDcard == IDcard)
        {
            if (!ok) 
                cout << "Cac so tiet kiem cua so chung minh nhan dan " << IDcard << " la: " << endl;
            cout << "- " << v.bookCode << ": so du hien tai la " << fixed << setprecision(4) << v.currentAmount << endl; 
            ok = true;
        }

    if (!ok)
        cout << "Khong co so tiet kiem nao cua chung minh nhan dan " << IDcard << endl;
    
    cout << endl;
    cout << "Enter to exit";
    getline(cin, exitKey);
    return;
}

void findByBookCode()
{
    if (savingsBook.empty())
    {
        cout << "Khong ton tai bat ki so tiet kiem nao" << endl;
        cout << endl;
        cout << "Enter to exit";
        cin.ignore();
        getline(cin, exitKey);
        return;
    }

    cin.ignore();
    cout << "Nhap ma so cua so tiet kiem can tim kiem: ";
    getline(cin, bookCode);

    bool ok = false;

    for (auto v : savingsBook)
        if (v.bookCode == bookCode)
        {
            cout << "So du cua ma so " << bookCode << " la: " << v.currentAmount << endl;
            ok = true;
        }

    if (!ok)
        cout << "Khong co so tiet kiem nao co ma so la " << bookCode << endl;
    cout << endl;
    cout << "Enter to exit";
    getline(cin, exitKey);
    return;
}

string Start, End;
Time _Start, _end;

void findByTime()
{
    if (savingsBook.empty())
    {
        cout << "Khong ton tai bat ki so tiet kiem nao" << endl;
        cout << endl;
        cout << "Enter to exit";
        cin.ignore();
        getline(cin, exitKey);
        return;
    }

    cin.ignore();
    cout << "Nhap thoi gian bat dau tim kiem (Format: dd/mm/yyyy): ";
    getline(cin, Start);
    cout << "Nhap thoi gian ket thuc tim kiem (Format: dd/mm/yyyy): ";
    getline(cin, End);

    _Start = Time(Start);
    _end = Time(End);

    bool ok = false;
    for (auto v : savingsBook)
        if (_Start <= v.openingDate && v.openingDate <= _end)
        {
            if (!ok) 
                cout << "Cac so tiet kiem mo trong khoang thoi gian " << Start << " den " << End << " la: " << endl;
            cout << "- " << v.bookCode << ": so du hien tai la " << v.currentAmount << endl;
            ok = true;
        }

    if (!ok)
        cout << "Khong co so tiet kiem nao mo trong khoang thoi gian tu " << Start << " den " << End << endl;
    
    cout << endl;
    cout << "Enter to exit";
    getline(cin, exitKey);
    return;
}

void sortByAmountMoney()
{
    if (savingsBook.empty())
    {
        cout << "Khong ton tai bat ki so tiet kiem nao" << endl;
        cout << endl;
        cout << "Enter to exit";
        cin.ignore();
        getline(cin, exitKey);
        return;
    }

    sort(savingsBook.begin(), savingsBook.end(), [](SavingsBook u, SavingsBook v)
    {
        return u.depositAmount > v.depositAmount;
    });

    cout << "Danh sach cac so tiet kiem da sap xep la: " << endl;

    for (auto v : savingsBook)
        cout << "- " << v.bookCode << ": so tien gui la " << fixed << setprecision(4) << v.depositAmount << endl;

    cout << endl;
    
    cout << "Enter to exit";
    cin.ignore();
    getline(cin, exitKey);
    return;
}

void sortByOpeningDate()
{
    if (savingsBook.empty())
    {
        cout << "Khong ton tai bat ki so tiet kiem nao" << endl;
        cout << endl;
        cout << "Enter to exit";
        cin.ignore();
        getline(cin, exitKey);
        return;
    }

    sort(savingsBook.begin(), savingsBook.end(), [](SavingsBook u, SavingsBook v)
    {
        return u.openingDate < v.openingDate;
    });

    cout << "Danh sach cac so tiet kiem da sap xep la: " << endl;

    for (auto v : savingsBook)
        cout << "- " << v.bookCode << ": thoi gian mo so la " << v.openingDate.day << '/' << v.openingDate.month << '/' << v.openingDate.year << endl;

    cout << endl;
    cout << "Enter to exit";
    cin.ignore();
    getline(cin, exitKey);
    return;
}

int option; 

int main()
{    
    while (true)
    {
        system("clear");
        cout << "----------CHUONG TRINH QUAN LI SO TIET KIEM----------" << endl;
        cout << "1. Them thong tin so tiet kiem" << endl;
        cout << "2. Cap nhap thong tin lai suat" << endl;
        cout << "3. Rut tien" << endl;
        cout << "4. Tim so tiet kiem theo CMND" << endl;
        cout << "5. Tim so tiet kiem theo ma so" << endl;
        cout << "6. Tim so tiet kiem mo trong khoang thoi gian" << endl;
        cout << "7. In ra danh sach cac so tiet kiem theo so tien gui giam dan" << endl;
        cout << "8. In ra danh sach cac so tiet kiem theo ngay mo so tang dan" << endl;
        cout << "9. Ket thuc chuong trinh" << endl;
        cout << endl;
        cout << endl;

        cout << "Nhap lua chon: ";
        cin >> option; 

        while (option < 1 || option > 9)
        {
            cout << "Lua chon khong ton tai. Nhap lai: ";
            cin >> option;
        }

        if (option == 1) read();
        if (option == 2) updateInterestRate();
        if (option == 3) withdrawMoney();
        if (option == 4) findByIDcard();
        if (option == 5) findByBookCode();
        if (option == 6) findByTime();
        if (option == 7) sortByAmountMoney();
        if (option == 8) sortByOpeningDate();
        if (option == 9) return 0;
    }

    return 0;
}