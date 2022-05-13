//
// Created by Salah on 13/05/2022.
//

#ifndef USER_LOGIN_LOGIN_APP_H
#define USER_LOGIN_LOGIN_APP_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <conio.h>

#include "validation.h"
#include "user.h"
#include "csv.h"


using namespace std;

bool main_loop(map<string, User> &users, vector<string> &usernames, vector<string> &emails);

void login_loop(map<string, User> &users);

void register_loop(map<string, User> &users, vector<string> &usernames, vector<string> &emails);

void change_password_loop();

void forget_password_loop();

void user_interface_loop(User &user);

string get_password();


#endif //USER_LOGIN_LOGIN_APP_H
