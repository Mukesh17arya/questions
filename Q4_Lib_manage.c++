#include <iostream>
#include <string>
using namespace std;

class Book {
protected:
    string title;
    string author;
    string ISBN;

public:
    void setBookDetails(const string& t, const string& a, const string& i) {
        title = t;
        author = a;
        ISBN = i;
    }

    void displayBookDetails() const {
        cout << "Book Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
    }
};

class Borrower {
protected:
    string name;
    int id;
    string borrowedBook;

public:
    void setBorrowerDetails(const string& n, int i) {
        name = n;
        id = i;
    }

    void borrowBook(const string& book) {
        borrowedBook = book;
    }

    void returnBook() {
        borrowedBook = "None";
    }

    void displayBorrowerDetails() const {
        cout << "Borrower Name: " << name << endl;
        cout << "Borrower ID: " << id << endl;
        cout << "Borrowed Book: " << borrowedBook << endl;
    }
};

class Library : public Book, public Borrower {
public:
    void borrow(const string& t) {
        borrowBook(t);
    }

    void returnBorrowedBook() {
        returnBook();
    }

    void displayDetails() const {
        cout << "Library Record:" << endl;
        displayBookDetails();
        displayBorrowerDetails();
    }
};

int main() {
    Library library;

    string title, author, ISBN, name;
    int id;

    cout << "Enter book details (Title, Author, ISBN): ";
    cin.ignore();
    getline(cin, title);
    getline(cin, author);
    getline(cin, ISBN);

    cout << "Enter borrower details (Name, ID): ";
    getline(cin, name);
    cin >> id;

    library.setBookDetails(title, author, ISBN);
    library.setBorrowerDetails(name, id);

    library.borrow(title);
    cout << "\nAfter Borrowing:\n";
    library.displayDetails();

    library.returnBorrowedBook();
    cout << "\nAfter Returning:\n";
    library.displayDetails();

    return 0;
}
