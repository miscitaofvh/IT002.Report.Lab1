#include <bits/stdc++.h>

using namespace std;

// Storage infomation of student
struct Student
{
    string name, classify;
    double mathScore, literatureScore, englishScore, averageScore;
    
    Student(string _name = "", double _mathScore = 0, double _literatureScore = 0, double _englishScore = 0)
    {
        name = _name;
        mathScore = _mathScore;
        literatureScore = _literatureScore;
        englishScore = _englishScore;
        averageScore = (2 * mathScore + literatureScore + englishScore) / 4;

        if (averageScore < 5) classify = "Yeu";
        if (averageScore >= 5 && averageScore < 6.5) classify = "Trung Binh";
        if (averageScore >= 6.5 && averageScore < 8) classify = "Kha";
        if (averageScore >= 8 && averageScore < 9) classify = "Gioi";
        if (averageScore >= 9) classify = "Xuat sac";
    }
};

// check name invalid
string checkName(string name)
{
    if (name.length() > 30)
        return "Do dai cua ten khong the vuot qua 30 ki tu.";

    if (name[0] == ' ')
        return "Ki tu dau tien cua ten khong the la khoang trang.";
    if (name[name.length() - 1] == ' ')
        return "Ki tu cuoi cua ten khong the la khoang trang.";
    if (name.find("  ") != string::npos)
        return "Ten khong the chua hai khoang trang nam canh nhau.";

    for (auto u : name)
        if (u >= '0' && u <= '9')
            return "Ten khong the chua ky tu so.";
    
    for (auto u : name)
        if (u >= 'a' && u <= 'z') continue;
            else if (u >= 'A' && u <= 'Z') continue; else
                if (u == ' ') continue; else
                    return "Ten chua khong the chua ki tu dac biet.";

    return "ok";
}

//check Score >= 0 && <= 10
string checkScore(double score)
{
    if (score < 0)
        return "Diem khong the be hon 0.";
    if (score > 10) 
        return "Dien khong the lon hon 10.";
    
    return "ok";
}

// Find all students with highest average score
void findMaxAverageScore(vector<Student> students)
{
    double maxAverageScore = 0;

    for (auto student : students)
        maxAverageScore = max(maxAverageScore, student.averageScore);

    cout << "Hoc sinh co diem toan cao nhat la: " << endl;
    for (auto student : students)
        if (student.averageScore == maxAverageScore)
            cout << "- " << student.name << endl;

    cout << endl;
};

// Find student by name
void findStudentByName(vector<Student> students, string name)
{
    string _name = name;
    vector<string> answer;
    string studentName;
    for (auto &v : name)
        if (v >= 'A' && v <= 'Z') v += 32;

    for (auto u : students)
    {
        studentName = u.name;
        for (auto &v : studentName)
            if (v >= 'A' && v <= 'Z') v += 32;

        for (int i = 0; i + name.length() - 1 < studentName.length(); ++i)
            if (i == 0 || studentName[i - 1] == ' ')
            {
                if (studentName.substr(i, name.length()) == name)
                {
                    answer.push_back(u.name);
                    break;
                }
            }
    }

    if (answer.empty())
        cout << "Khong co hoc sinh nao co ten " << _name << endl;
    else 
    {
        cout << "Cac hoc sinh co ten " << _name << " la: " << endl;
        for (auto v : answer) 
            cout << "- " << v << endl;
    }    
    cout << endl;
};


// Find all students with lowest math score
void findMinMathScore(vector<Student> students)
{
    double minMathScore = 10;

    for (auto v : students)
        minMathScore = min(minMathScore, v.mathScore);

    cout << "Hoc sinh co diem toan thap nhat la: " << endl;

    for (auto v : students)
        if (v.mathScore == minMathScore)
            cout << "- " << v.name << endl;
    cout << endl;
}

int n;
vector<Student> students;
string name;
double mathScore, literatureScore, englishScore;

int main()
{
    cout << "Nhap so luong hoc sinh: ";
    cin >> n;

    for (int i = 1; i <= n; ++i) 
    {
        cout << "Nhap thong tin cho hoc sinh thu " << i << ":" << endl;
        cout << "Nhap ten cua hoc sinh: ";
        cin.ignore();
        getline(cin, name);

        while (checkName(name) != "ok")
        {
            cout << checkName(name) << " Nhap lai: ";
            getline(cin, name);
        }

        cout << "Nhap diem toan cua hoc sinh: ";
        cin >> mathScore;

        while (checkScore(mathScore) != "ok")
        {
            cout << checkScore(mathScore) << " Nhap lai: ";
            cin >> mathScore;
        }

        cout << "Nhap diem van cua hoc sinh: ";
        cin >> literatureScore;

        while (checkScore(literatureScore) != "ok")
        {
            cout << checkScore(literatureScore) << " Nhap lai: ";
            cin >> literatureScore;
        }

        cout << "Nhap diem anh cua hoc sinh: ";
        cin >> englishScore;

        while (checkScore(englishScore) != "ok")
        {
            cout << checkScore(englishScore) << " Nhap lai: ";
            cin >> englishScore;
        }

        students.push_back(Student(name, mathScore, literatureScore, englishScore));
    }

    findMaxAverageScore(students);

    cout << "Nhap ten cua tim kiem: ";
    cin.ignore();
    getline(cin, name);
    findStudentByName(students, name);

    findMinMathScore(students);

    return 0;
}