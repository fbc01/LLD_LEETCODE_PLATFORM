#include <iostream>
#include <mutex>
#include "../DTO/Users/User.h"
using namespace std;

class UserLibrary {
private:
    unordered_map<string, User*> userLibrary;
    static mutex mtx;
    static UserLibrary* instance;

    UserLibrary() {}

public:
    static UserLibrary* getInstance() {
        if (instance == NULL) {
            unique_lock<mutex> locker(mtx);
            locker.lock();
            if (instance == NULL) {
                instance = new UserLibrary();
            }
            locker.unlock();
        }
        return instance;
    }

    void addUser(User* user) {
        if (userLibrary.find(user->getUsername()) != userLibrary.end()) {
            cout << "Username = " << user->getUsername() << " already exists" << endl;
            return;
        }
        userLibrary[user->getUsername()] = user;
    }

    User* getUser(string& username) {
        if (userLibrary.find(username) != userLibrary.end()) {
            return userLibrary[username];
        }
        else {
            cout << "User with username = " << username << " not found";
            return NULL;
        }
    }

    vector<User*> getAllUsers() {
        vector<User*> result;
        for (unordered_map<string, User*>::iterator itr = begin(userLibrary); itr != end(userLibrary); itr++) {
            result.push_back(itr->second);
        }
        return result;
    }

};