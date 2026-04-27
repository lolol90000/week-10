#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    string id;
    string name;
    string major;
    string hobby;
    double gpa;
    string email;
    string city;
};

void saveToFile(Student s[], int n, const string& filename);
int loadFromFile(Student s[], const string& filename);
void displayAll(Student s[], int n);
int countHonors(Student s[], int n);
void queryByCity(Student s[], int n, const string& city);

void saveToFile(Student s[], int n, const string& filename) {
    ofstream out(filename);

    for (int i = 0; i < n; i++) {
        out << s[i].id << " "
            << s[i].name << " "
            << s[i].major << " "
            << s[i].hobby << " "
            << s[i].gpa << " "
            << s[i].email << " "
            << s[i].city << endl;
    }

    out.close();

    cout << "[1] Data saved to " << filename << endl;
}

int loadFromFile(Student s[], const string& filename) {
    ifstream in(filename);

    int count = 0;

    while (in >> s[count].id
              >> s[count].name
              >> s[count].major
              >> s[count].hobby
              >> s[count].gpa
              >> s[count].email
              >> s[count].city) {
        count++;
    }

    in.close();

    cout << "[2] Loaded " << count << " students from " << filename << endl;

    return count;
}

void displayAll(Student s[], int n) {
    cout << "\n[3] Displaying all students:" << endl;
    cout << "----------------------------------------" << endl;

    for (int i = 0; i < n; i++) {
        cout << s[i].id << " "
             << s[i].name << " ("
             << s[i].major << ") - "
             << s[i].city << " - GPA: "
             << s[i].gpa << endl;
    }
}

int countHonors(Student s[], int n) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (s[i].gpa >= 3.0) {
            count++;
        }
    }

    return count;
}

void queryByCity(Student s[], int n, const string& city) {
    cout << "\n[5] Students from " << city << ":" << endl;

    bool found = false;

    for (int i = 0; i < n; i++) {
        if (s[i].city == city) {
            cout << s[i].name << " ("
                 << s[i].major << ", GPA "
                 << s[i].gpa << ")" << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No students found in that city." << endl;
    }
}

int main() {
    Student students[100];
    int n = 3;

    students[0] = {"S01", "Tom", "MATH", "Football", 2.8, "tom@google.com", "Modesto"};
    students[1] = {"S02", "Alice", "CS", "Reading", 3.5, "alice@google.com", "Modesto"};
    students[2] = {"S03", "Scott", "CS", "Basketball", 3.2, "scott@google.com", "SanJose"};

    saveToFile(students, n, "students.txt");

    Student loaded[100];
    int count = loadFromFile(loaded, "students.txt");

    displayAll(loaded, count);

    cout << "\n[4] Students with GPA >= 3.0: "
         << countHonors(loaded, count) << endl;

    queryByCity(loaded, count, "Modesto");

    cout << "\nProgram finished." << endl;
    return 0;
}