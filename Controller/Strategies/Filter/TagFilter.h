#include <iostream>
#include "Filter.h"
#include "../../../Model/DTO/Questions/QuestionWithLikesAndSolves.h"
using namespace std;

class TagFilter : public FilterInterface {
public:
    // should avoid using queues
    vector<QuestionWithLikesAndSolves*> filter (vector<QuestionWithLikesAndSolves*>& questions, string& value) override {
        vector<QuestionWithLikesAndSolves*> filteredQuestions;
        int size = questions.size();
        for (int i=0; i<size; i++) {
            if (questions[i]->getTag() == value) {
                filteredQuestions.push_back(questions[i]);
            }
        }
        return filteredQuestions;
    }
};