#ifndef USER_LOGIN_VALIDATION_H
#define USER_LOGIN_VALIDATION_H

#include <regex>

bool is_valid_username(const std::string &username, const std::vector<std::string>& usernames);

bool is_valid_email(const std::string &email, const std::vector<std::string>& emails);

bool is_valid_password(const std::string &password);

bool is_valid_phoneNumber(const std::string &phoneNumber);

#endif //USER_LOGIN_VALIDATION_H
