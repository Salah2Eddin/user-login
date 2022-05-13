//
// Created by Salah on 11/05/2022.
//
#include <iostream>
#include "user.h"

User::User(std::string &un, const std::string &pwd, const std::string &mail, const std::string &pn) :
        username(new std::string(un)), password(new std::string(pwd)), email(new std::string(mail)),
        phoneNumber(new std::string(pn)) {}

User::User() : username(new std::string), password(new std::string), email(new std::string),
               phoneNumber(new std::string) {}

bool User::login(const std::string &pwd) const {
    return pwd == *password;
}
