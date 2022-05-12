#ifndef USER_LOGIN_VALIDATION_H
#define USER_LOGIN_VALIDATION_H

#include <regex>
#include "user.h"

bool is_valid_username(const std::string &username, std::map<std::string, User> users);

bool is_valid_email(const std::string &email);

bool is_valid_password(const std::string &password);

bool is_valid_phoneNumber(const std::string &phoneNumber);


#endif //USER_LOGIN_VALIDATION_H
