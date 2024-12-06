#include <iostream>
#include <algorithm>
#include "Sorting.h"
#include "../../../Model/DTO/Questions/QuestionWithLikesAndSolves.h"
using namespace std;

class SortingUsingLikes : public Sorting {
public:
    vector<QuestionWithLikesAndSolves*> sortList (vector<QuestionWithLikesAndSolves*> questions) override {
        vector<QuestionWithLikesAndSolves*> copiedQuestions(questions.begin(), questions.end());
        sort (begin(copiedQuestions), end(copiedQuestions), [](QuestionWithLikesAndSolves* question1, QuestionWithLikesAndSolves* question2){
            return question1->getLikes() > question2->getLikes();
        }) ;
        return copiedQuestions;
    }
};