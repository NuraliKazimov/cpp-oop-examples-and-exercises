#include <iostream>
#include <string>

using namespace std;

/*
    Polymorphism

    15. Abstract Classes as Interfaces
*/

/*
    Exercise: Backend Data Storage Interface

    Instructions:

1. Define an abstract interface named DataStorage with the following pure virtual functions:
        void storeData(const string& data): This function should represent storing data.
        string retrieveData(): This function should represent retrieving data.
        Implement two concrete classes that inherit from the DataStorage interface:

    2. FileStorage: Implement the functions to store and retrieve data using a file.
        DatabaseStorage: Implement the functions to store and retrieve data using a database.
        In the main function:

    3. Create an instance of FileStorage, store and retrieve some data.
    4. Create an instance of DatabaseStorage, store and retrieve some data.
*/


// Abstract interface for data storage
class DataStorage {
    public:
        // Declare pure virtual functions for storing and retrieving data
        virtual void storeData(string data) = 0;
        virtual string retrieveData() = 0;

        virtual ~DataStorage() {}   // Virtual destructor
};


// Concrete class implementing data storage using a file
class FileStorage : public DataStorage {
    private:
        string fileData;

    public:
        // Implement functions to store and retrieve data using a file
        void storeData(string data) override {
            fileData = data;
        }

        string retrieveData() override {
            return fileData;
        }

        // Virtual destructor
         ~FileStorage() {
            cout << "FileStorage Destructor" << endl;
        }
};


// Concrete class implementing data storage using a database
class DatabaseStorage : public DataStorage {
    private:
        string dbData;

    public:
        // Implement functions to store and retrieve data using a database
        void storeData(string data) override {
            dbData = data;
        }

        string retrieveData() override {
            return dbData;
        }

        // Virtual destructor
        ~DatabaseStorage() {
            cout << "DatabaseStorage Destructor" << endl;
        }
};


int main() {
    
    // Example usage of the DataStorage interface

    // Using FileStorage
    FileStorage fileStorage;
    fileStorage.storeData("FileStorage Data");
    cout << "FileStorage: " << fileStorage.retrieveData() << endl;

    // Using DatabaseStorage
    DatabaseStorage databaseStorage;
    databaseStorage.storeData("DatabaseStorage Data");
    cout << "DatabaseStorage: " << databaseStorage.retrieveData() << endl;
    
    return 0;
}
