#include <bits/stdc++.h>
#include "user.h"
#include "validation.h"

using namespace std;

int main() {
    string un = "Salah2Eddin", pwd = "Salah!@34", mail = "Hi@Yahoo.com", pn = "01013904876";
    map<string, User> users;
    users[un] = User(un, pwd, mail, pn);

    cout << users[un] << endl;

    string new_email;
    cout << "Enter new email:";
    cin >> new_email;
    if (!is_valid_email(new_email)) {
        cout << "Invalid Email!" << endl;
        cout << "Enter new email:";
        cin >> new_email;
    }
    *users[un].email = new_email;

    cout << users[un] << endl;
    return 0;
}
