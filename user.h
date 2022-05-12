#ifndef USER_LOGIN_USER_H
#define USER_LOGIN_USER_H

#include <sstream>
#include <string>
#include <ostream>

struct User {
public:
    std::string *username{};
    std::string *password{};
    std::string *phoneNumber{};
    std::string *email{};

    User();
    User(std::string &csv);
    User(std::string &username, const std::string &password, const std::string &email, const std::string &phoneNumber);

    friend auto operator<<(std::ostream &stream, User &m) -> std::ostream &;
};

User user_from_csv(const std::string& csv_line);

#endif //USER_LOGIN_USER_H
