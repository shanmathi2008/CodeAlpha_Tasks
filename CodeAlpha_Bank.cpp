#include <iostream>
#include <string>

using namespace std;

class BankAccount
{
private:
    string name;
    int accountNumber;
    float balance;

public:

    // Create Account
    void createAccount()
    {
        cout << "\n===== CREATE ACCOUNT =====" << endl;

        cout << "Enter Customer Name: ";
        cin >> name;

        cout << "Enter Account Number: ";
        cin >> accountNumber;

        cout << "Enter Initial Balance: ";
        cin >> balance;

        cout << "\nAccount Created Successfully!" << endl;
    }

    // Deposit Money
    void deposit()
    {
        float amount;

        cout << "\nEnter Amount to Deposit: ";
        cin >> amount;

        if(amount > 0)
        {
            balance += amount;
            cout << "Amount Deposited Successfully!" << endl;
        }
        else
        {
            cout << "Invalid Amount!" << endl;
        }
    }

    // Withdraw Money
    void withdraw()
    {
        float amount;

        cout << "\nEnter Amount to Withdraw: ";
        cin >> amount;

        if(amount <= balance)
        {
            balance -= amount;
            cout << "Withdrawal Successful!" << endl;
        }
        else
        {
            cout << "Insufficient Balance!" << endl;
        }
    }

    // Display Account Details
    void display()
    {
        cout << "\n===== ACCOUNT DETAILS =====" << endl;

        cout << "Customer Name : " << name << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: " << balance << endl;
    }
};

int main()
{
    BankAccount user;

    int choice;

    do
    {
        cout << "\n=============================" << endl;
        cout << "      BANKING SYSTEM" << endl;
        cout << "=============================" << endl;

        cout << "1. Create Account" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Check Balance" << endl;
        cout << "5. Exit" << endl;

        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                user.createAccount();
                break;

            case 2:
                user.deposit();
                break;

            case 3:
                user.withdraw();
                break;

            case 4:
                user.display();
                break;

            case 5:
                cout << "\nThank You for Using Banking System!" << endl;
                break;

            default:
                cout << "\nInvalid Choice! Try Again." << endl;
        }

    } while(choice != 5);

    return 0;
}