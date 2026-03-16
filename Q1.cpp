#include <iostream>
using namespace std;

class Book {
protected:
    string title;
    string author;
    string publisher;

public:
    Book(string t, string a, string p) {
        title = t;
        author = a;
        publisher = p;
    }

    void display() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publisher: " << publisher << endl;
    }
};

class FictionBook : public Book {
private:
    string genre;
    string protagonist;

public:
    FictionBook(string t, string a, string p, string g, string pro) 
        : Book(t, a, p) {
        genre = g;
        protagonist = pro;
    }

    void display() {
        Book::display();
        cout << "Genre: " << genre << endl;
        cout << "Protagonist: " << protagonist << endl;
    }
};

int main() {
    FictionBook book1("The Lost World", "Arthur Conan Doyle", "Penguin", "Adventure", "Edward Malone");
    book1.display();
    return 0;
}