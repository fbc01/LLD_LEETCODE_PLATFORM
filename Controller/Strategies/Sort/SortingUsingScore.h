#include <iostream>
#include <algorithm>
#include "Sorting.h"
#include "../../../Model/DTO/Questions/QuestionWithLikesAndSolves.h"
using namespace std;

class SortingUsingScore: public Sorting {
public:
    vector<QuestionWithLikesAndSolves*> sortList (vector<QuestionWithLikesAndSolves*> questions) override {
        vector<QuestionWithLikesAndSolves*> copiedQuestions(begin(questions), end(questions));
        sort (begin(copiedQuestions), end(copiedQuestions), [](QuestionWithLikesAndSolves* question1, QuestionWithLikesAndSolves* question2){
            return question1->getScore() > question2->getScore();
        }) ;
        return copiedQuestions;
    }
};