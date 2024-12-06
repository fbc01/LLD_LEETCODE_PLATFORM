#include <iostream>
#include "User.h"
#include "../Interactions/AttemptedQuestion.h"
#include "../Interactions/SolvedQuestion.h"
#include "../../../Controller/Strategies/Score/ScoreCalculator.h"
using namespace std;

class UserWithAttempts {
private:
    User* user;
    vector<AttemptedQuestion*> attemptedQuestions;
    vector<SolvedQuestion*> solvedQuestions;
    int score;

public:
    UserWithAttempts(User* user) {
        this->user = user;
        attemptedQuestions = {};
        solvedQuestions = {};
        score = 0;
    }

    void addScore(SolvedQuestion* question, ScoreCalculator* scoreCalculator) {
        int size = solvedQuestions.size();
        for (int i=0; i<size; i++) {
            if (solvedQuestions[i]->getQuestion()->getQuestionId() == question->getQuestion()->getQuestionId()) {
                cout << "User has already solved this problem" << endl;
                return;
            }
        }
        score += scoreCalculator->calculate(question);
        solvedQuestions.push_back(question);
    }

    int getScore() {
        return this->score;
    }

    User* getUser() {
        return this->user;
    }
};