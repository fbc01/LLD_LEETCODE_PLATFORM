#include <iostream>
using namespace std;

class AttemptedQuestion {
private:
    string username;
    int questionId;

public:
    AttemptedQuestion(string& username, int& questionId) {
        this->username = username;
        this->questionId = questionId;
    }

    string getUsername() {
        return this->username;
    }

    int getQuestionId() {
        return this->questionId;
    }
};