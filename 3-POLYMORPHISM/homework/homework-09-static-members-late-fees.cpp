#include <iostream>
#include <string>

using namespace std;


/*
    Inheritance and Polymorphism with Static members
*/

/*
    Exercise: Create a library management program with C++ that models different types of items 
    (books and DVDs) and their late fee calculations. 
    Implement the missing parts of the code and complete the tasks below.

    Tasks:

    1. Implement the missing parts of the code, including the calculateLateFee method for both the Book and DVD classes.
    2. Initialize and update the totalItems static member in the LibraryItem class when a new item is created.
    3. In the main function, create instances of both Book and DVD, display their information, and calculate late fees for them.
    4. Finally, display the total number of library items using the totalItems static member.
*/

class LibraryItem {
    public:
        LibraryItem(const string& title) : title(title)  {
            totalItem++;
        }

        virtual double calculateLateFee(int daysLate) const = 0;

        virtual void displayInfo() const {
            cout << "Title: " << title << endl;
        }
        static int totalItem;

    protected:
        string title;
};

int LibraryItem::totalItem=0;

// Define the static member totalItems for the LibraryItem class here
// Initialize it to 0.

class Book : public LibraryItem {
    public:
        Book(const string& title, const string& author) : LibraryItem(title), author(author) {}
        
        double calculateLateFee(int daysLate) const override {
            // Implement the late fee calculation for books.
            return daysLate*5;
        }

        void displayInfo() const override {
            LibraryItem::displayInfo();
            cout << "Author: " << author << std::endl;
        }

    private:
        string author;
};

class DVD : public LibraryItem {
    public:
        DVD(const string& title, int duration) : LibraryItem(title), duration(duration) {}
        double calculateLateFee(int daysLate) const override {
            return daysLate*10;
        }

        void displayInfo() const override {
            LibraryItem::displayInfo();
            cout << "Duration: " << duration << " minutes" << endl;
        }

    private:
        int duration;
};


int main() {
    system("clear");
    // Create instances of Book and DVD and test their functionality.
    // Hint: Create Book and DVD objects, display their information, and calculate late fees.

    // Display the total number of library items using the static member totalItems.
    // Hint: Access the totalItems static member from the LibraryItem class.
    Book book("Roman", "Victor Hugo");
    DVD dvd("Music",3);
    DVD dvd2("Music",4);
    book.displayInfo();
    dvd.displayInfo();
    cout << "The number of items: " << LibraryItem::totalItem;

    return 0;
}
