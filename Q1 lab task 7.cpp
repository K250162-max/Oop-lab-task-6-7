#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    int accountNumber;
    double balance;
    string accountHolderName;
    string accountType;

public:
    Account(int accNo, string name, double bal, string type) {
        accountNumber = accNo;
        accountHolderName = name;
        balance = bal;
        accountType = type;
    }

    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }

    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Insufficient balance\n";
        }
    }

    virtual double calculateInterest() {
        return 0.0;
    }

    virtual void printStatement() {
        cout << "\nAccount Statement\n";
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance: " << balance << endl;
    }

    void getAccountInfo() {
        cout << "\nAccount Info\n";
        cout << "Name: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Type: " << accountType << endl;
        cout << "Balance: " << balance << endl;
    }
};

class SavingsAccount : public Account {
    double interestRate;
    double minimumBalance;

public:
    SavingsAccount(int accNo, string name, double bal, double rate, double minBal)
        : Account(accNo, name, bal, "Savings") {
        interestRate = rate;
        minimumBalance = minBal;
    }

    double calculateInterest() override {
        return balance * interestRate;
    }

    void withdraw(double amount) override {
        if (balance - amount >= minimumBalance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Minimum balance requirement violated\n";
        }
    }

    void printStatement() override {
        Account::printStatement();
        cout << "Interest Rate: " << interestRate << endl;
    }
};

class CheckingAccount : public Account {
public:
    CheckingAccount(int accNo, string name, double bal)
        : Account(accNo, name, bal, "Checking") {}

    double calculateInterest() override {
        return balance * 0.01;
    }

    void printStatement() override {
        Account::printStatement();
        cout << "Checking account interest applied\n";
    }
};

class FixedDepositAccount : public Account {
    string maturityDate;
    double fixedInterestRate;

public:
    FixedDepositAccount(int accNo, string name, double bal, string date, double rate)
        : Account(accNo, name, bal, "Fixed Deposit") {
        maturityDate = date;
        fixedInterestRate = rate;
    }

    double calculateInterest() override {
        return balance * fixedInterestRate;
    }

    void withdraw(double amount) override {
        cout << "Withdrawal not allowed before maturity date: " << maturityDate << endl;
    }

    void printStatement() override {
        Account::printStatement();
        cout << "Maturity Date: " << maturityDate << endl;
        cout << "Fixed Interest Rate: " << fixedInterestRate << endl;
    }
};

int main() {
    SavingsAccount s1(101, "Ali", 5000, 0.05, 1000);
    CheckingAccount c1(102, "Sara", 3000);
    FixedDepositAccount f1(103, "Ahmed", 10000, "2027-12-31", 0.08);

    Account* accounts[3];
    accounts[0] = &s1;
    accounts[1] = &c1;
    accounts[2] = &f1;

    accounts[0]->deposit(1000);
    accounts[0]->withdraw(2000);

    accounts[1]->deposit(500);
    accounts[1]->withdraw(1000);

    accounts[2]->deposit(2000);
    accounts[2]->withdraw(500);

    for (int i = 0; i < 3; i++) {
        accounts[i]->printStatement();
        cout << "Calculated Interest: " << accounts[i]->calculateInterest() << endl;
    }

    return 0;
}
