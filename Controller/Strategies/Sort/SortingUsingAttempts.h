#include <iostream>
#include <algorithm>
#include "Sorting.h"
#include "../../../Model/DTO/Questions/QuestionWithLikesAndSolves.h"
#include "../../../Model/Constants/QuestionConstants.h"
using namespace std;

class SortingUsingAttempts : public Sorting {
private:
    unordered_map<string, int> tagsWeight = {(EASY, 1), (MEDIUM, 2), (HARD, 3)};

public:
    vector<QuestionWithLikesAndSolves*> sortList (vector<QuestionWithLikesAndSolves*> questions) override {
        vector<QuestionWithLikesAndSolves*> copiedQuestions(questions.begin(), questions.end());
        sort (begin(copiedQuestions), end(copiedQuestions), [&](QuestionWithLikesAndSolves* question1, QuestionWithLikesAndSolves* question2){
            return question1->getSuccessfulAttempts() > question2->getSuccessfulAttempts();
        });
        return copiedQuestions;
    }
};