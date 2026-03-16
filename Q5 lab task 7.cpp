#include <iostream>
#include <string>
using namespace std;

class Media {
protected:
    string title;
    string publicationDate;
    int uniqueID;
    string publisher;
    bool checkedOut;

public:
    Media(string t, string pd, int id, string pub) {
        title = t;
        publicationDate = pd;
        uniqueID = id;
        publisher = pub;
        checkedOut = false;
    }

    virtual void displayInfo() {
        cout << "Title: " << title << endl;
        cout << "Publication Date: " << publicationDate << endl;
        cout << "ID: " << uniqueID << endl;
        cout << "Publisher: " << publisher << endl;
    }

    void checkOut() {
        if (!checkedOut) {
            checkedOut = true;
            cout << title << " checked out\n";
        } else {
            cout << title << " already checked out\n";
        }
    }

    void returnItem() {
        if (checkedOut) {
            checkedOut = false;
            cout << title << " returned\n";
        }
    }

    string getTitle() { return title; }
};

class Book : public Media {
    string author;
    string ISBN;
    int numberOfPages;

public:
    Book(string t, string pd, int id, string pub, string a, string i, int p)
        : Media(t, pd, id, pub) {
        author = a;
        ISBN = i;
        numberOfPages = p;
    }

    void displayInfo() {
        Media::displayInfo();
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Pages: " << numberOfPages << endl;
    }

    string getAuthor() { return author; }
};

class DVD : public Media {
    string director;
    int duration;
    string rating;

public:
    DVD(string t, string pd, int id, string pub, string d, int du, string r)
        : Media(t, pd, id, pub) {
        director = d;
        duration = du;
        rating = r;
    }

    void displayInfo() {
        Media::displayInfo();
        cout << "Director: " << director << endl;
        cout << "Duration: " << duration << " minutes\n";
        cout << "Rating: " << rating << endl;
    }
};

class CD : public Media {
    string artist;
    int numberOfTracks;
    string genre;

public:
    CD(string t, string pd, int id, string pub, string ar, int nt, string g)
        : Media(t, pd, id, pub) {
        artist = ar;
        numberOfTracks = nt;
        genre = g;
    }

    void displayInfo() {
        Media::displayInfo();
        cout << "Artist: " << artist << endl;
        cout << "Tracks: " << numberOfTracks << endl;
        cout << "Genre: " << genre << endl;
    }
};

class Magazine : public Media {
    int issueNumber;

public:
    Magazine(string t, string pd, int id, string pub, int in)
        : Media(t, pd, id, pub) {
        issueNumber = in;
    }

    void displayInfo() {
        Media::displayInfo();
        cout << "Issue Number: " << issueNumber << endl;
    }
};

class Library {
public:
    void search(string title) {
        cout << "Searching by title: " << title << endl;
    }

    void search(string title, string author) {
        cout << "Searching by title: " << title << " and author: " << author << endl;
    }

    void search(int year) {
        cout << "Searching by publication year: " << year << endl;
    }
};

int main() {
    Book b("C++ Programming", "2020", 101, "TechPress", "Bjarne", "12345", 500);
    DVD d("Inception", "2010", 102, "Warner", "Christopher Nolan", 148, "PG-13");
    CD c("Thriller", "1982", 103, "Epic", "Michael Jackson", 9, "Pop");
    Magazine m("Tech Today", "2024", 104, "FuturePub", 12);

    b.displayInfo();
    cout << endl;

    d.displayInfo();
    cout << endl;

    c.displayInfo();
    cout << endl;

    m.displayInfo();
    cout << endl;

    b.checkOut();
    b.returnItem();

    Library lib;
    lib.search("C++ Programming");
    lib.search("C++ Programming", "Bjarne");
    lib.search(2020);

    return 0;
}
