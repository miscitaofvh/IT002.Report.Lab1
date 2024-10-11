#include <bits/stdc++.h>

using namespace std;

struct Time
{
    int minute, hour, day, month, year;

    Time(int _minute = 0, int _hour = 0, int _day = 0, int _month = 0, int _year = 0) : minute(_minute), hour(_hour), day(_day), month(_month), year(_year) {}
    Time(string flightDay)
    {
        if (flightDay.size() != 10 || flightDay[2] != '/' || flightDay[5] != '/')
        {
            day = 0;
            return;
        }

        for (int i = 0; i < 10; ++i)
        {
            if (i == 2 || i == 5) continue;
            if (flightDay[i] >= 0 && flightDay[i] <= '9') continue;
            day = 0;
            return;
        }

        day = (flightDay[0] - 48) * 10 + (flightDay[1] - 48);
        month = (flightDay[3] - 48) * 10 + (flightDay[4] - 48);
        year = (flightDay[6] - 48) * 1000 + (flightDay[7] - 48) * 100 + (flightDay[8] - 48) * 10 + (flightDay[9] - 48);
    }
    Time(string flightDay, string flightTime)
    {
        if (flightDay.size() != 10 || flightDay[2] != '/' || flightDay[5] != '/')
        {
            day = 0;
            return;
        }

        for (int i = 0; i < 10; ++i)
        {
            if (i == 2 || i == 5) continue;
            if (flightDay[i] >= '0' && flightDay[i] <= '9') continue;
            day = 0;
            return;
        }

        day = (flightDay[0] - 48) * 10 + (flightDay[1] - 48);
        month = (flightDay[3] - 48) * 10 + (flightDay[4] - 48);
        year = (flightDay[6] - 48) * 1000 + (flightDay[7] - 48) * 100 + (flightDay[8] - 48) * 10 + (flightDay[9] - 48);

        if (flightTime.size() != 5 || flightTime[2] != ':')
        {
            hour = 24;
            return;
        }

        for (int i = 0; i < 5; ++i)
        {
            if (i == 2) continue;
            if (flightTime[i] >= '0' && flightTime[i] <= '9') continue;
            hour = 24;
            return;
        }

        hour = (flightTime[0] - 48) * 10 + (flightTime[1] - 48);
        minute = (flightTime[3] - 48) * 10 + (flightTime[4] - 48);
    }
};

//storage infomation of flight
struct Flight
{
    string flightCode, origin, destination;
    Time flightTime;

    Flight(string _flightCode = "", Time _flightTime = Time(), string _origin = "", string _destination  = "") : flightCode(_flightCode), flightTime(_flightTime), origin(_origin), destination(_destination) {}
};

// check flight code
bool checkFlightCode(string flightCode)
{
    if (flightCode.length() > 5) return false;
    for (auto u : flightCode)
    {
        if (u >= 'a' && u <= 'z') continue;
        if (u >= 'A' && u <= 'Z') continue;
        if (u >= '0' && u <= '9') continue;
        return false;
    }   

    return true;
}

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

// check flight day
bool checkFlightDay(Time flightDay)
{
    if (flightDay.day < 1 || flightDay.month < 1 || flightDay.year < 1 || flightDay.month > 12 || flightDay.day > daysInMonth(flightDay.month, flightDay.year))
        return false;
    return true;
}

// check flight time
bool checkFlightTime(Time flightTime)
{
    if (flightTime.hour < 0 || flightTime.minute < 0 || flightTime.hour > 23 || flightTime.minute > 59)
        return false;
    return true;
}

// check origin and destination
bool checkPlaceName(string placeName)
{
    if (placeName.size() > 20)
        return false;

    for (auto v : placeName)
    {
        if (v == ' ') continue;
        if (v >= 'a' && v <= 'z') continue;
        if (v >= 'A' && v <= 'Z') continue;
        return false;
    }

    return true;
}

// Find flight by flightCode, origin, destination
void findFlight(vector<Flight> flights, string flightCode, string origin, string destination)
{
    vector<Flight> answer;

    if (flightCode == "_" && origin == "_" && destination == "_")
    {
        cout << "Khong du thong tin de tim chuyen bay" << endl;
        return;
    }

    for (auto v : flights)
    {
        if (flightCode != "_" && v.flightCode != flightCode) continue;
        if (origin != "_" && v.origin != origin) continue;
        if (destination != "_" && v.destination != destination) continue;
        answer.push_back(v);
    }

    if (answer.empty())
        cout << "Khong tim duoc chuyen bay nao voi thong tin da cho" << endl;
    else
    {
        cout << "Cac chuyen bay tim duoc la: " << endl;
        for (auto v : answer)
        {
            cout << v.flightCode << " " << v.flightTime.hour << ":" << v.flightTime.minute << " " << v.flightTime.day << "/" << v.flightTime.month << "/" << v.flightTime.year << " '" << v.origin << "' '" << v.destination << "'" << endl;
        }
    }
    cout << endl;
    return;
}

// Sort all flights by time
void sortFlight(vector<Flight> flights)
{
    sort(flights.begin(), flights.end(), [](Flight u, Flight v){
        if (u.flightTime.year != u.flightTime.year)
            return u.flightTime.year < v.flightTime.year;
        if (u.flightTime.month != u.flightTime.month)
            return u.flightTime.month < v.flightTime.month;
        if (u.flightTime.day != v.flightTime.day)
            return u.flightTime.day < v.flightTime.day;
        if (u.flightTime.hour != v.flightTime.hour)
            return u.flightTime.hour > v.flightTime.hour;
        return u.flightTime.minute < v.flightTime.minute;
    });

    cout << "Cac chuyen bay sau khi duoc sap xep la: " << endl;

    for (auto v : flights)
    {
        cout << v.flightCode << " " << v.flightTime.hour << ":" << v.flightTime.minute << " " << v.flightTime.day << "/" << v.flightTime.month << "/" << v.flightTime.year << " '" << v.origin << "' '" << v.destination << "'" << endl;
    }
    cout << endl;
    return;
}

//find flight by origin and time
void findFlightByTime(vector<Flight> flights, string origin, Time flightTime)
{
    vector<Flight> answer;

    for (auto v : flights)
    {
        if (v.origin != origin) continue;
        if (v.flightTime.day != flightTime.day) continue;
        if (v.flightTime.month != flightTime.month) continue;
        if (v.flightTime.year != flightTime.year) continue;
        answer.push_back(v);
    }

    if (answer.empty())
        cout << "Khong tim duoc chuyen bay nao voi thong tin da cho" << endl;
    else
    {
        cout << "Cac chuyen bay tim duoc la: " << endl;
        for (auto v : answer)
        {
            cout << v.flightCode << " " << v.flightTime.hour << ":" << v.flightTime.minute << " " << v.flightTime.day << "/" << v.flightTime.month << "/" << v.flightTime.year << " '" << v.origin << "' '" << v.destination << "'" << endl;
        }
    }
    cout << endl;
    return;
}

void countFlight(vector<Flight> flights, string origin, string destination)
{
    int answer = 0;

    for (auto v : flights)
    {
        if (v.origin == origin && v.destination == destination) 
            answer++;
    }

    if (answer == 0)
        cout << "Khong co chuyen bay nao di tu " << origin << " den " << destination << endl;
    else 
        cout << "Co " << answer << " chuyen bay di tu " << origin << " den " << destination << endl;

    return;
}

int n;
string flightCode, flightDay, _flightTime, origin, destination;
Time flightTime;
vector<Flight> flights;

int main()
{
    cout << "Nhap so luong chuyen bay: ";
    cin >> n;
    cin.ignore();

    for (int i = 1;  i <= n; ++i) 
    {
        cout << "Nhap thong tin cho chuyen bay thu " << i << ": " << endl;
        cout << "Nhap ma chuyen bay: ";
        
        getline(cin, flightCode);

        if (!checkFlightCode(flightCode))
            alert("Ma chuyen bay khong hop le.");
        
        cout << "Nhap ngay bay (Format: dd/mm/yyyy): ";
        getline(cin, flightDay);
        flightTime = Time(flightDay);

        if (!checkFlightDay(flightTime))
            alert("Thong tin ngay bay khong hop le.");

        cout << "Nhap gio bay (Format: hh:mm): ";
        getline(cin, _flightTime);

        flightTime = Time(flightDay, _flightTime);

        if (!checkFlightTime(flightTime))
            alert("Thong tin gio bay khong hop le.");

        cout << "Nhap noi di: ";
        getline(cin, origin);
        
        if (!checkPlaceName(origin))
            alert("Noi di khong phai la ten dia danh hop le.");

        cout << "Nhap noi den: ";
        getline(cin, destination);

        if (!checkPlaceName(destination))
            alert("Noi den khong phai la ten dia danh hop le.");

        flights.push_back(Flight(flightCode, flightTime, origin, destination));
    }

    cout << "Nhap ma chuyen bay can tim (Neu khong co thi nhap _): ";
    getline(cin, flightCode);
    if (flightCode != "_" && !checkFlightCode(flightCode))
        alert("Ma chuyen bay khong hop le.");
    cout << "Nhap noi di (Neu khong co thi nhap _): ";
    getline(cin, origin);
    if (origin != "_" && !checkPlaceName(origin))
            alert("Noi di khong phai la ten dia danh hop le.");

    cout << "Nhap noi den (Neu khong co thi nhap _): ";
    getline(cin, destination);
    
    if (destination != "_" && !checkPlaceName(destination))
            alert("Noi den khong phai la ten dia danh hop le.");
    
    findFlight(flights, flightCode, origin, destination);
    sortFlight(flights);

    cout << "Nhap dia diem khoi hanh cua chuyen bay can tim kiem: ";
    getline(cin, origin);
    if (!checkPlaceName(origin))
            alert("Noi di khong phai la ten dia danh hop le.");

    cout << "Chuyen bay tren bay vao ngay nao (Format: dd/mm/yyyy): ";
    getline(cin, flightDay);
    flightTime = Time(flightDay);
    if (!checkFlightDay(flightTime))
        alert("Thong tin ngay bay khong hop le.");
    
    findFlightByTime(flights, origin, flightTime);

    cout << "Nhap dia diem khoi hanh can dem: ";
    getline(cin, origin);
    if (!checkPlaceName(origin))
            alert("Noi di khong phai la ten dia danh hop le.");

    cout << "Nhap dia diem ha canh can dem: ";
    getline(cin, destination);
    
    if (!checkPlaceName(destination))
            alert("Noi den khong phai la ten dia danh hop le.");

    countFlight(flights, origin, destination);
    return 0;
}