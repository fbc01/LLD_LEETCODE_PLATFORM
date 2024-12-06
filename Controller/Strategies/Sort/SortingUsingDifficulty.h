#include <iostream>
#include <algorithm>
#include "Sorting.h"
#include "../../../Model/DTO/Questions/QuestionWithLikesAndSolves.h"
#include "../../../Model/Constants/QuestionConstants.h"
using namespace std;

class SortingUsingDifficultyLevel : public Sorting {
private:
    unordered_map<string, int> tagsWeight = {(EASY, 1), (MEDIUM, 2), (HARD, 3)};

public:
    vector<QuestionWithLikesAndSolves*> sortList (vector<QuestionWithLikesAndSolves*> questions) override {
        vector<QuestionWithLikesAndSolves*> copiedQuestions(begin(questions), end(questions));
        sort (begin(copiedQuestions), end(copiedQuestions), [&](QuestionWithLikesAndSolves* question1, QuestionWithLikesAndSolves* question2){
            string difficulty1 = question1->getDifficultyLevel();
            string difficulty2 = question2->getDifficultyLevel();
            return this->tagsWeight[difficulty1] < this->tagsWeight[difficulty2];
        });
        return copiedQuestions;
    }
};