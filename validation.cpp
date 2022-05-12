#include "validation.h"

bool is_valid_username(const std::string &username, std::map<std::string, User> users) {
    bool exists = false;
    if (*users[username].username == username) {
        exists = true;
    }

    std::regex expr(R"(^[\w]{8,16}$)");

    return std::regex_match(username, expr) && !exists;
}

bool is_valid_email(const std::string &email) {
    std::regex expr(R"(^([\w.]{1,64}@([\w.]){1,}\.[\w]{2,4})$)");
    return std::regex_match(email, expr);;
}

bool is_valid_password(const std::string &password) {
    std::regex expr(R"(^(?=.*\d)(?=.*[a-z])(?=.*[A-Z])(?=.*[a-zA-Z]).{8,16}$)");
    return std::regex_match(password, expr);
}

bool is_valid_phoneNumber(const std::string &phoneNumber) {
    std::regex expr(R"(^01\d{9}$)");
    return std::regex_match(phoneNumber, expr);
}