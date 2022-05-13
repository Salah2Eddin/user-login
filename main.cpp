#include <iostream>
#include <string>

#include "validation.h"
#include "user.h"

using namespace std;

map<string, User> users;
vector<string> usernames, emails;

void login_loop();

void register_loop();

void change_password_loop();

void forget_password_loop();

void user_interface_loop(User user);

bool main_loop();

int main() {

    for (const auto &user: users) {
        usernames.push_back(*user.second.username);
        emails.push_back(*user.second.email);
    }

    bool cont = true;
    while (cont) {
        cont = main_loop();
    }
}

bool main_loop() {
    int choice;
    cout << "Welcome to Login App!" << endl;
    cout << "1.Login\n";
    cout << "2.Register\n";
    cout << "3.Forgot password\n";
    cout << "4.Exit\n";
    cout << "Enter your choice:";
    cin >> choice;

    switch (choice) {
        case 1: {
            login_loop();
            break;
        }
        case 2: {
            register_loop();
            break;
        }
        case 4: {
            cout << "Thanks for using Login App";
            return false;
        }
        default: {
            cout << "Invalid choice";
        }
    }
    return true;
}

void login_loop() {
    string username, password;

    cout << "Username: ";
    cin >> username;
    if (*users[username].username != username) {
        cout << "This user doesn't exist" << endl;
        return;
    }

    cout << "Password: ";
    cin >> password;

    int no_tries = 1;
    while (!users[username].login(password) && no_tries <= 3) {
        if (no_tries > 3) {
            cout << "You are forbidden from accessing the system" << endl;
            return;
        }

        cout << "Wrong password!" << endl;
        cout << "Password: ";
        cin >> password;

        no_tries++;
    }
    user_interface_loop(users[username]);
}

void register_loop() {
    string username, email, phoneNumber, password, rPassword;
    cout << "Username" << endl
         << "\t1.Your username length must be between 8 and 32" << endl
         << "\t2.Your username can only have uppercase and lowercase characters, digits, and underscore(_)" << endl
         << "\t3.Your username mustn't be of an existing" << endl
         << "Username:";
    cin >> username;
    while (!is_valid_username(username, usernames)) {
        cout << "Invalid username!" << endl;
        cout << "Username:";
        cin >> username;
    }

    cout << "Email:";
    cin >> email;
    while (!is_valid_email(email, emails)) {
        cout << "Invalid email!" << endl;
        cout << "Email:";
        cin >> email;
    }

    cout << "Phone number:";
    cin >> phoneNumber;
    while (!is_valid_phoneNumber(phoneNumber)) {
        cout << "Invalid phone number!" << endl;
        cout << "Phone number:";
        cin >> phoneNumber;
    }

    cout << "Password:" << endl
         << "\t1.The password must be at least 8 characters long." << endl
         << "\t2.The password must have at least one uppercase character, lowercase character,"
         << "and digit." << endl;
    cin >> password;
    while (!is_valid_password(password)) {
        cout << "Your password is weak!" << endl;

        cout << "Password:";
        cin >> password;
    }

    cout << "Repeat password:";
    cin >> rPassword;

    while (password != rPassword) {
        cout << "Passwords are not equal!" << endl;

        cout << "Password:";
        cin >> password;

        cout << "Repeat password:";
        cin >> rPassword;
    }
}

void change_password_loop(User user) {
    string oldPassword, newPassword, rNewPassword;

    cout << "Old password: ";
    cin >> oldPassword;

    if (*user.password != oldPassword) {
        cout << "Wrong password!" << endl;
        return;
    }

    cout << "New password:";
    cin >> newPassword;

    while (!is_valid_password(newPassword)) {
        cout << "Your new password is weak!" << endl;

        cout << "New password:";
        cin >> newPassword;
    }

    cout << "Enter the new password again:";
    cin >> rNewPassword;

    while (newPassword != rNewPassword) {
        cout << "Passwords are not equal" << endl;

        cout << "Password:";
        cin >> newPassword;

        cout << "Repeat password:";
        cin >> rNewPassword;
    }
}

void user_interface_loop(User user) {
    int choice = 0;
    cout << "Welcome " << *user.username << endl;
    while (true) {
        cout << "1. Change Password" << endl
             << "2. Logout" << endl;
        cout << "Choice:";
        cin >> choice;
        switch (choice) {
            case 1: {
                change_password_loop(user);
                break;
            }
            case 2: {
                return;
            }
            default : {
                cout << "Invalid choice" << endl;
            }
        }
    }
}
