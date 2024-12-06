#include <iostream>
#include "../../../Model/DTO/Questions/QuestionWithLikesAndSolves.h"
using namespace std;

class SolvedQuestion {
private:
    string username;
    QuestionWithLikesAndSolves* question;
    int durationInMinutes;

public:
    SolvedQuestion(string& username, QuestionWithLikesAndSolves* question, int& durationInMinutes) {
        this->username = username;
        this->question = question;
        this->durationInMinutes = durationInMinutes;
    }

    string getUsername() {
        return this->username;
    }

    QuestionWithLikesAndSolves* getQuestion() {
        return this->question;
    }

    int getDurationInMinutes() {
        return this->durationInMinutes;
    }

    void display() {
        question->display();
        cout << "time taken = " << durationInMinutes << endl;
    }
};