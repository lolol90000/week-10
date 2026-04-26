#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student
{
    int studentID;
    string name;
    double score;
};

int main()
{
    Student s1 = {1001, "David", 85.5};
    Student s2 = {1002, "Lisa", 92.0};
    Student s3 = {1003, "John", 78.3};

    ofstream outFile("students.txt");

    outFile << s1.studentID << " " << s1.name << " " << s1.score << endl;
    outFile << s2.studentID << " " << s2.name << " " << s2.score << endl;
    outFile << s3.studentID << " " << s3.name << " " << s3.score << endl;

    outFile.close();

    ifstream inFile("students.txt");

    Student temp;

    cout << "===== Student Records Read From File =====" << endl;

    while (inFile >> temp.studentID >> temp.name >> temp.score)
    {
        cout << "ID: " << temp.studentID
             << " | Name: " << temp.name
             << " | Score: " << temp.score << endl;
    }

    inFile.close();

    return 0;
}