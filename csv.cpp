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
              << *user.second.phoneNumber << ","
              << *user.second.email
              << "\n";

    }
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
    string un, pass, pn, email;
    // Reads the values from the file then adding the values to the map
    while (csv_l >> un >> pass >> pn >> email) {
        cout << un << pass << pn << email << endl;
    }
    csv_l.close();

    return users;
}
