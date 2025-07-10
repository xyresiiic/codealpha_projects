#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool userExists(const string& username) {
    ifstream file("users.txt");
    string line, user;

    while (getline(file, line)) {
        size_t separator = line.find(':');
        if (separator != string::npos) {
            user = line.substr(0, separator);
            if (user == username) {
                return true;
            }
        }
    }
    return false;
}

void registerUser() {
    string username, password;
    cout << "Register a new account\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (userExists(username)) {
        cout << "Username already exists. Please choose a different one.\n";
        return;
    }

    ofstream file("users.txt", ios::app);
    if (file.is_open()) {
        file << username << ":" << password << endl;
        file.close();
        cout << "Registration successful.\n";
    } else {
        cout << "Failed to open user file.\n";
    }
}


void loginUser() {
    string username, password;
    cout << "Login to your account\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");
    string line, user, pass;
    bool found = false;

    while (getline(file, line)) {
        size_t separator = line.find(':');
        if (separator != string::npos) {
            user = line.substr(0, separator);
            pass = line.substr(separator + 1);
            if (user == username && pass == password) {
                found = true;
                break;
            }
        }
    }

    file.close();

    if (found) {
        cout << "Login successful. Welcome, " << username << ".\n";
    } else {
        cout << "Invalid username or password.\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\nLogin and Registration System\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid option. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}

