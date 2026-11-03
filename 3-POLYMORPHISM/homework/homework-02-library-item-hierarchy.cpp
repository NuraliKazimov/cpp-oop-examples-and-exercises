#include <iostream>
#include <string>

using namespace std;

/*
    Exercise: Polymorphism in a Backend Application

    Scenario:
    You are developing a backend application for a library management system. 
    The application needs to handle various types of items in the library, such as books, e-books, and audio CDs. 
    Each of these items has specific properties and actions associated with them.

    Requirements:

    1. Create a base class called LibraryItem with the following properties and methods:
        Properties:
        title (string): The title of the library item.
        year (int): The year of publication.
        Methods:
        virtual void checkout(): A virtual function that marks the item as checked out.
        virtual void checkin(): A virtual function that marks the item as checked in.
        virtual void displayInfo(): A virtual function that displays information about the item, 
        including its title and year of publication.

    2. Create three derived classes: Book, EBook, and AudioCD, each inheriting from LibraryItem. 
       These classes should have their own specific properties and methods:
        Book:
        Properties:
        author (string): The author of the book.
        Methods:
        Override the displayInfo() method to include information about the author.
        EBook:
        Properties:
        format (string): The format of the e-book (e.g., PDF, EPUB).
        Methods:
        Override the displayInfo() method to include information about the format.
        AudioCD:
        Properties:
        artist (string): The artist of the audio CD.
        Methods:
        Override the displayInfo() method to include information about the artist.

    3. In the main() function, create instances of Book, EBook, and AudioCD objects, each representing a library item.
    4. Create an array of pointers to LibraryItem objects and store the addresses of the items in the array.
    5. Use a loop to iterate through the array and perform the following actions:
        Check out and check in each item to simulate library operations.
        Display information about each item using the displayInfo() method.
    

    Example Output:

    Book Title: "The Great Gatsby"
    Author: F. Scott Fitzgerald
    Year: 1925
    Status: Checked out

    EBook Title: "The Hitchhiker's Guide to the Galaxy"
    Format: EPUB
    Year: 1979
    Status: Checked in

    Audio CD Title: "Abbey Road"
    Artist: The Beatles
    Year: 1969
    Status: Checked out

*/

// Solution

class LibraryItem {
    public:
    string title;
    int year;
    LibraryItem(string title, int year) : title(title), year(year) {}
    virtual void checkout() {
        cout << "Checked out!" << endl;
    }
    virtual void checkin() {
        cout << "Checked in!" << endl;
    }
    virtual void displayInfo() {
        cout << "Title: " <<  this->title << endl;
        cout << "Year: " << this->year << endl;
        cout << endl;
    }

};

class Book : public LibraryItem {
    public:
    string author;
    Book(string title, int year, string author) : LibraryItem(title,year), author(author) {}
    void displayInfo() override {
        cout << "Title: " <<  this->title << endl;
        cout << "Year: " << this->year << endl;
        cout << "Author: " << this->author << endl;
        cout << endl;
    }

};

class EBook : public LibraryItem {
    public:
    string format;
    EBook(string title, int year, string format) : LibraryItem(title,year), format(format) {}
    void displayInfo() override {
        cout << "Title: " <<  this->title << endl;
        cout << "Year: " << this->year << endl;
        cout << "Format: " << this->format << endl;
        cout << endl;
    }

};

class AudioCD : public LibraryItem {
    public:
    string artist;
    AudioCD(string title, int year, string artist) : LibraryItem(title,year), artist(artist) {}
    void displayInfo() override {
        cout << "Title: " <<  this->title << endl;
        cout << "Year: " << this->year << endl;
        cout << "Artist: " << this->artist << endl;
        cout << endl;
    }

};



int main() {

    system("clear");

    /*      Example usage:     */ 

    Book book("Crime and Punishment", 1866, "Dosteyevski");
    EBook EBook("Physics", 2000, "PDF");
    AudioCD audio("Bakılı Balası", 1997, "Eyyub Yagubov");

    LibraryItem* list[]={&book, &EBook, &audio};

    for (LibraryItem* i : list) {
         i->displayInfo();
    }

    return 0;
}
