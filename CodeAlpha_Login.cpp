#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to check duplicate username
bool checkUserExists(string username)
{
    string user, pass;

    ifstream file("users.txt");

    while(file >> user >> pass)
    {
        if(user == username)
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

// Registration Function
void registerUser()
{
    string username, password;

    cout << "\n===== USER REGISTRATION =====" << endl;

    cout << "Enter username: ";
    cin >> username;

    // Username validation
    if(username.length() < 4)
    {
        cout << "Username must contain at least 4 characters!" << endl;
        return;
    }

    // Duplicate username check
    if(checkUserExists(username))
    {
        cout << "Username already exists! Try another username." << endl;
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    // Password validation
    if(password.length() < 4)
    {
        cout << "Password must contain at least 4 characters!" << endl;
        return;
    }

    // Store data in file
    ofstream file("users.txt", ios::app);

    file << username << " " << password << endl;

    file.close();

    cout << "Registration Successful!" << endl;
}

// Login Function
void loginUser()
{
    string username, password;
    string storedUser, storedPass;

    cout << "\n===== USER LOGIN =====" << endl;

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");

    bool loginSuccess = false;

    while(file >> storedUser >> storedPass)
    {
        if(username == storedUser && password == storedPass)
        {
            loginSuccess = true;
            break;
        }
    }

    file.close();

    if(loginSuccess)
    {
        cout << "Login Successful! Welcome " << username << endl;
    }
    else
    {
        cout << "Invalid Username or Password!" << endl;
    }
}

// Main Function
int main()
{
    int choice;

    do
    {
        cout << "\n=================================" << endl;
        cout << " LOGIN & REGISTRATION SYSTEM " << endl;
        cout << "=================================" << endl;

        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                registerUser();
                break;

            case 2:
                loginUser();
                break;

            case 3:
                cout << "Exiting Program..." << endl;
                break;

            default:
                cout << "Invalid Choice! Try Again." << endl;
        }

    } while(choice != 3);

    return 0;
}