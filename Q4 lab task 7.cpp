#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int id;
    string address;
    string phoneNumber;
    string email;
public:
    Person(string n, int i, string a, string p, string e) {
        name = n;
        id = i;
        address = a;
        phoneNumber = p;
        email = e;
    }
    virtual void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Address: " << address << endl;
        cout << "Phone: " << phoneNumber << endl;
        cout << "Email: " << email << endl;
    }
    void updateInfo(string a, string p, string e) {
        address = a;
        phoneNumber = p;
        email = e;
    }
    int getId() {
        return id;
    }
    string getName() {
        return name;
    }
};
class Student : public Person {
    string coursesEnrolled;
    float GPA;
    int enrollmentYear;
public:
    Student(string n, int i, string a, string p, string e, string c, float g, int y)
        : Person(n, i, a, p, e) {
        coursesEnrolled = c;
        GPA = g;
        enrollmentYear = y;
    }
    void displayInfo() {
        Person::displayInfo();
        cout << "Courses Enrolled: " << coursesEnrolled << endl;
        cout << "GPA: " << GPA << endl;
        cout << "Enrollment Year: " << enrollmentYear << endl;
    }
};
class Professor : public Person {
    string department;
    string coursesTaught;
    double salary;
public:
    Professor(string n, int i, string a, string p, string e, string d, string c, double s)
        : Person(n, i, a, p, e) {
        department = d;
        coursesTaught = c;
        salary = s;
    }
    void displayInfo() {
        Person::displayInfo();
        cout << "Department: " << department << endl;
        cout << "Courses Taught: " << coursesTaught << endl;
        cout << "Salary: " << salary << endl;
    }
};
class Staff : public Person {
    string department;
    string position;
    double salary;
public:
    Staff(string n, int i, string a, string p, string e, string d, string pos, double s)
        : Person(n, i, a, p, e) {
        department = d;
        position = pos;
        salary = s;
    }
    void displayInfo() {
        Person::displayInfo();
        cout << "Department: " << department << endl;
        cout << "Position: " << position << endl;
        cout << "Salary: " << salary << endl;
    }
};
class Course {
    int courseId;
    string courseName;
    int credits;
    string instructor;
    string schedule;
    Student* students[50];
    int studentCount;
public:
    Course(int id, string n, int c, string ins, string sch) {
        courseId = id;
        courseName = n;
        credits = c;
        instructor = ins;
        schedule = sch;
        studentCount = 0;
    }
    void registerStudent(Student* s) {
        if (studentCount < 50) {
            students[studentCount] = s;
            studentCount++;
        }
    }
    void calculateGrades() {
        cout << "Grades calculated for " << studentCount << " students in " << courseName << endl;
    }
    void displayCourse() {
        cout << "Course ID: " << courseId << endl;
        cout << "Course Name: " << courseName << endl;
        cout << "Credits: " << credits << endl;
        cout << "Instructor: " << instructor << endl;
        cout << "Schedule: " << schedule << endl;
        cout << "Registered Students:" << endl;
        for (int i = 0; i < studentCount; i++) {
            cout << students[i]->getName() << " (ID: " << students[i]->getId() << ")" << endl;
        }
    }
};
int main() {
    Student s1("Ali", 101, "Lahore", "03001234567", "ali@email.com", "OOP, DSA", 3.5, 2023);
    Professor p1("Dr. Khan", 201, "Islamabad", "03111234567", "khan@email.com", "CS", "OOP", 120000);
    Staff st1("Ahmed", 301, "Karachi", "03221234567", "ahmed@email.com", "Administration", "Manager", 60000);
    Course c1(1, "Object Oriented Programming", 3, "Dr. Khan", "Mon-Wed");
    c1.registerStudent(&s1);
    cout << "Student Info:" << endl;
    s1.displayInfo();
    cout << endl << "Professor Info:" << endl;
    p1.displayInfo();
    cout << endl << "Staff Info:" << endl;
    st1.displayInfo();
    cout << endl << "Course Info:" << endl;
    c1.displayCourse();
    c1.calculateGrades();

    return 0;
}
