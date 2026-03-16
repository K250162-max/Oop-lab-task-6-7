#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    Person(string n, int a) {
        name = n;
        age = a;
    }
};
class Student : public Person {
protected:
    int studentID;
    int gradeLevel;
public:
    Student(string n, int a, int id, int grade) : Person(n, a) {
        studentID = id;
        gradeLevel = grade;
    }
};
class Teacher : public Person {
protected:
    string subject;
    int roomNumber;
public:
    Teacher(string n, int a, string sub, int room) : Person(n, a) {
        subject = sub;
        roomNumber = room;
    }
};
class graduateStudent : public Student, public Teacher {
public:
    graduateStudent(string n, int a, int id, int grade, string sub, int room)
        : Student(n, a, id, grade), Teacher(n, a, sub, room) {}

    void display() {
        cout << "Name: " << Student::name << endl;
        cout << "Age: " << Student::age << endl;
        cout << "Student ID: " << studentID << endl;
        cout << "Grade Level: " << gradeLevel << endl;
        cout << "Subject: " << subject << endl;
        cout << "Room Number: " << roomNumber << endl;
    }
};
int main() {
    graduateStudent g("Ali", 24, 1023, 16, "Programming", 205);
    g.display();
    return 0;
}
