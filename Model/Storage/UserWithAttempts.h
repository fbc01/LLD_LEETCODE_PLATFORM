#include <iostream>
#include "../DTO/Users/User.h"
#include "../DTO/Users/UserWithAttempts.h"
using namespace std;

class UserWithAttemptsLibrary {
private:
    unordered_map<string, UserWithAttempts*> userWithAttemptsLibrary;

public:
    void addUserWithAttempt(UserWithAttempts* userWithAttempt) {
        if (userWithAttemptsLibrary.find(userWithAttempt->getUser()->getUsername()) != userWithAttemptsLibrary.end()) {
            cout << "User entry already exists" << endl;
            return;
        }
        userWithAttemptsLibrary[userWithAttempt->getUser()->getUsername()] = userWithAttempt;
    }

    UserWithAttempts* getUserWithAttempts(string& username) {
        if (userWithAttemptsLibrary.find(username) != userWithAttemptsLibrary.end()) {
            return userWithAttemptsLibrary[username];
        }
        else {
            cout << "User with username = " << username << " not found";
            return NULL;
        }
    }
};