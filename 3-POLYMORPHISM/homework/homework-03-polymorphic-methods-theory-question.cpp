#include <iostream>
#include <string>

using namespace std;

/*
    Exercise: Bank Account Management System

    You need to implement a simple bank account management system using encapsulation. 
    The system should have the following features:

    1. Each account should have a unique account number, holder name, and balance.
    2. The balance should not be directly accessible from outside the class.
    3. The account holder should be able to deposit and withdraw funds.
    4. The account holder should be able to check their account balance.
    
    Your task is to create a C++ class called BankAccount that encapsulates the above features. 
    Here's a code template to get you started:
*/

class BankAccount {
    private:
        // Private member variables
        int accountNumber;
        string holderName;
        double balance;

    public:
        // Constructor
        BankAccount(int accountNumber, const string &holderName, double initialBalance) {
            this->accountNumber=accountNumber;
            this->holderName=holderName;
            this->balance=initialBalance;
        }

        void withdraw(int a) {
            balance=balance-a;
        }
        void deposit(int a) {
            balance=balance+a;
        }
        void getter() {
            cout << "balance: " << balance << endl;
        }
};



int main() {

    // TODO: Create an instance of the BankAccount class
    // TODO: Test the deposit, withdraw, and check balance operations

    /*
        You need to complete the implementation of the BankAccount class by:

        1. Initializing the member variables in the constructor.
        2. Implementing member functions for deposit, withdraw, and check balance.
        3. Testing the functionality of your class in the main function by creating an instance 
        of BankAccount and performing deposit, withdrawal, and balance checks.
        
        Remember to enforce encapsulation by keeping the member variables private and providing public member functions to access and modify them.

        This exercise will help you practice encapsulation and understand how to hide 
        implementation details while exposing a controlled interface to the users of your class!
    */

    BankAccount acc1(4169, "David", 1000);
    acc1.withdraw(100);
    acc1.getter();
    acc1.deposit(500);
    acc1.getter();

    return 0;
}

