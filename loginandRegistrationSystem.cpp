#include <bits/stdc++.h>
using namespace std;

// Registration Function
void registerUser() {
    string username, password;
    string fileUser, filePass;
    bool userExists = false;

    cout << "\n--- User Registration ---\n";

    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    // Validation
    if (username.empty() || password.empty()) {
        cout << "Username or Password cannot be empty!\n";
        return;
    }

    // Check duplicate username
    ifstream readFile("users.txt");

    while (readFile >> fileUser >> filePass) {
        if (fileUser == username) {
            userExists = true;
            break;
        }
    }

    readFile.close();

    if (userExists) {
        cout << "Username already exists! Try another username.\n";
        return;
    }

    // Store credentials
    ofstream writeFile("users.txt", ios::app);
    writeFile << username << " " << password << endl;
    writeFile.close();

    cout << "Registration Successful!\n";
}

// Login Function
void loginUser() {
    string username, password;
    string fileUser, filePass;
    bool loginSuccess = false;

    cout << "\n--- User Login ---\n";

    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    ifstream readFile("users.txt");

    while (readFile >> fileUser >> filePass) {
        if (fileUser == username && filePass == password) {
            loginSuccess = true;
            break;
        }
    }

    readFile.close();

    if (loginSuccess) {
        cout << "Login Successful! Welcome, " << username << endl;
    } else {
        cout << "Invalid Username or Password!\n";
    }
}

// Main Function
int main() {
    int choice;

    do {
        cout << "\n===== Login & Registration System =====\n";
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
                cout << "Exiting Program...\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 3);

    return 0;
}