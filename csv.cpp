#include "csv.h"

void save_csv(const std::map<string, User> &users) {
    // file pointer
    fstream csv_s;

    // opens a csv or creates one.
    csv_s.open("loginData.csv", ios::out);

    // Read the input
    for (const auto &user: users) {
        // Insert the data to file
        csv_s << user.first << ","
              << *user.second.password << ","
              << *user.second.email << ","
              << *user.second.phoneNumber << endl;
    }
}

map<string, User> load_csv() {
    map<string, User> users;
    // Open file:
    fstream csv_l("loginData.csv", ios::in); // Open in text-mode.

    // Opening may fail, always check.
    if (!csv_l) {
        fstream mkfile("loginData.csv", ios::out);
    }
    // Read the file and load the data:
    string csv_line;
    // Reads the values from the file then adding the values to the map
    while (csv_l >> csv_line) {
        stringstream sstream;
        sstream << csv_line;
        vector<string> v(4);
        int i = 0;
        while (getline(sstream, v[i], ',')) {
            i++;
        }
        cout << v[0] << v[1] << v[2] <<  v[3];
        users[v[0]] = User(v[0], v[1], v[2], v[3]);
    }
    csv_l.close();

    return users;
}
