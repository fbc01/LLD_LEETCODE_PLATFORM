#include <iostream>
using namespace std;

class User {
private:
    string username;
    string password;
    string fullname;
    string department;

public:
    User(string& username, string& password, string& fullname, string& department) {
        this->username = username;
        this->password = password;
        this->fullname = fullname;
        this->department = department;
    }

    string getUsername() {
        return this->username;
    }

    string getPassword() {
        return this->password;
    }

    void showContestant() {
        cout << "Fullname = " << this->fullname << endl;
        cout << "Department = " << this->department << endl;
    }
};
