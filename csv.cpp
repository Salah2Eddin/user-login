#include "csv.h"

void save_csv(const std::map<string, User> &users) {
    // file stream
    fstream csv_s;

    // opens a csv or creates one.
    csv_s.open("loginData.csv", ios::out);
    for (const auto &user: users) {
        // Insert the data to file
        csv_s << user.first << ","
              << *user.second.password << ","
              << *user.second.email << ','
              << *user.second.phoneNumber
              << "\n";

    }

    csv_s.close();
}

std::map<string, User> load_csv() {
    std::map<string, User> users;
    // Open file:
    std::fstream csv_l("loginData.csv", ios::in); // Open in text-mode.

    // Opening may fail, always check.
    if (!csv_l) {
        std::cout << "Error, could not open file." << std::endl;
    }

    // Read the file and load the data:
    string line;
    // Reads the values from the file then adding the values to the map
    while (csv_l >> line) {
        stringstream sstream;
        sstream << line;
        int i = 0;
        vector<string> v(4);
        while (getline(sstream, v[i], ',')) {
            i++;
        }
        users[v[0]] = User(v[0], v[1], v[2], v[3]);
    }
    csv_l.close();

    return users;
}
