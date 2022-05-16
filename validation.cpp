#include "validation.h"

bool is_valid_username(const std::string &username, const std::vector<std::string> &usernames) {
    bool exists = false;
    if (std::find(usernames.begin(), usernames.end(), username) != usernames.end()) {
        exists = true;
    }

    std::regex expr(R"(^[\w]{8,16}$)");

    return std::regex_match(username, expr) && !exists;
}

bool is_valid_email(const std::string &email, const std::vector<std::string>& emails) {
    bool exists = false;
    if (std::find(emails.begin(), emails.end(), email) != emails.end()) {
        exists = true;
    }
    
    std::regex expr(R"(^(([\w]?[\.]?(?=[^\.]))+@([\w.])+\.[\w]{2,4})$)");
    
    return std::regex_match(email, expr) && !exists;
}

bool is_valid_password(const std::string &password) {
    std::regex expr(R"(^(?=.*\d)(?=.*[a-z])(?=.*[A-Z])(?=.*[a-zA-Z])(?=.*[!@#$%^&*()_-]).{8,}$)");
    return std::regex_match(password, expr);
}

bool is_valid_phoneNumber(const std::string &phoneNumber) {
    std::regex expr(R"(^01\d{9}$)");
    return std::regex_match(phoneNumber, expr);
}