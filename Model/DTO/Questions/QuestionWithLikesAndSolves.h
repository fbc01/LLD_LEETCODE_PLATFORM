#include <iostream>
#include "Question.h"
using namespace std;

// can be decorated with other properties also
class QuestionWithLikesAndSolves : public QuestionInterface {
private:
    Question* question; // instead of full object , use references
    vector<string> likedByUsers;
    vector<string> solvedByUsers;
    int totalTimeTaken;

public:
    QuestionWithLikesAndSolves(Question* question) {
        this->question = question;
        this->likedByUsers = {};
        this->solvedByUsers = {};
        this->totalTimeTaken = 0;
    }

    void display() override {
        question->display();
        cout << "number of likes = " << (int)likedByUsers.size() << endl;
        cout << "number of people solved this problem = " << (int)solvedByUsers.size() << endl;
        cout << "avarage time to solve this problem = " << ((double)this->totalTimeTaken / this->solvedByUsers.size()) << " minutes" << endl;
    }

    int getQuestionId() override {
        return question->getQuestionId();
    }

    string getDescription() override {
        return question->getDescription();
    }

    string getDifficultyLevel() override {
        return question->getDifficultyLevel();
    }

    string getTag() override {
        return question->getTag();
    }

    int getScore() override {
        return question->getScore();
    }

    void addUserWhoLiked(string& username) {
        int size = likedByUsers.size();
        for (int i=0; i<size; i++) {
            if (likedByUsers[i] == username) {
                cout << "User = " << username << " has already liked the question" << endl;
                return;
            }
        }
        likedByUsers.push_back(username);
        cout << "User = " << username << " has just liked the question" << endl;
    }

    void removeUserWhoLiked(string& username) {
        int size = likedByUsers.size();
        for (int i=0; i<size; i++) {
            if (likedByUsers[i] == username) {
                swap(likedByUsers[i], likedByUsers[size-1]);
                likedByUsers.pop_back();
                cout << "User = " << username << " no longer likes the question" << endl;
                return;
            }
        }
        cout << "User = " << username << " has never liked this question" << endl;
    }

    int getLikes() {
        return this->likedByUsers.size();
    }

    int getSuccessfulAttempts() {
        return this->solvedByUsers.size();
    }
    
    void addUserWhoSolved(string& username, int durationInMinutes) {
        int size = solvedByUsers.size();
        for (int i=0; i<size; i++) {
            if (solvedByUsers[i] == username) {
                cout << "User has already solved this earlier" << endl;
                return;
            }
        }
        solvedByUsers.push_back(username);
        totalTimeTaken += durationInMinutes;
    }
};