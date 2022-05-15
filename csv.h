//
// Created by Salah on 13/05/2022.
//

#ifndef USER_LOGIN_CSV_H
#define USER_LOGIN_CSV_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include "user.h"

using namespace std;

std::map<string, User> load_csv();

void save_csv(const std::map<string, User> &users);
void save_csv(User user);

#endif //USER_LOGIN_CSV_H
