//TASK 2: Banking System 
//● Design classes for Customer, Account and Transaction with necessary attributes. 
//● Implement functions to create and manage customers and accounts. 
//● Include features for deposits, withdrawals and fund transfers. 
//● Store transaction history and allow users to view recent transactions. 
//● Display account information like balance and transaction details to customers.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Transaction {
public:
    string type;
    double amount;

    Transaction(string type, double amount) {
        this->type = type;
        this->amount = amount;
    }

    void displayTransaction() {
        cout << type << ": " << amount << endl;
    }
};

class Account {
private:
    int accountId;
    double balance;
    vector<Transaction> transactions;

public:
    Account(int accountId, double initialBalance) {
        this->accountId = accountId;
        this->balance = initialBalance;
    }

    void deposit(double amount) {
        balance += amount;
        transactions.push_back(Transaction("Deposit", amount));
        cout << "Deposit successful. New balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            transactions.push_back(Transaction("Withdrawal", amount));
            cout << "Withdrawal successful. New balance: " << balance << endl;
        } else {
            cout << "Insufficient funds." << endl;
        }
    }

    void transfer(Account &recipientAccount, double amount) {
        if (balance >= amount) {
            balance -= amount;
            recipientAccount.balance += amount;
            transactions.push_back(Transaction("Transfer", amount));
            recipientAccount.transactions.push_back(Transaction("Transfer", amount));
            cout << "Transfer successful." << endl;
        } else {
            cout << "Insufficient funds." << endl;
        }
    }

    void displayAccountInfo() {
        cout << "Account ID: " << accountId << endl;
        cout << "Balance: " << balance << endl;
        cout << "Transaction History:" << endl;
        for (Transaction transaction : transactions) {
            transaction.displayTransaction();
        }
    }
};

class Customer {
private:
    string name;
    Account account;

public:
    Customer(string name, int accountId, double initialBalance) : account(accountId, initialBalance) {
        this->name = name;
    }

    void deposit(double amount) {
        account.deposit(amount);
    }

    void withdraw(double amount) {
        account.withdraw(amount);
    }

    void transfer(Customer &recipientCustomer, double amount) {
        account.transfer(recipientCustomer.account, amount);
    }

    void displayCustomerInfo() {
        cout << "\nCustomer Name: " << name << endl;
        account.displayAccountInfo();
    }
};

int main() {
    Customer customer1("John Doe", 12345, 1000.0);
    Customer customer2("Jane Doe", 67890, 500.0);

    customer1.displayCustomerInfo();
    customer2.displayCustomerInfo();

    customer1.deposit(500.0);
    customer1.withdraw(200.0);
    customer1.transfer(customer2, 300.0);

    customer1.displayCustomerInfo();
    customer2.displayCustomerInfo();

    return 0;
}
