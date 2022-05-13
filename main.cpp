#include "login_app.h"

using namespace std;
map<string, User> users;
vector<string> usernames, emails;

int main() {
    users = load_csv();

    for (const auto &user: users) {
        usernames.push_back(*user.second.username);
        emails.push_back(*user.second.email);
    }

    bool cont = true;
    while (cont) {
        cont = main_loop(users, usernames, emails);
    }
}