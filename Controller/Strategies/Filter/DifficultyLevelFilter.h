#include <iostream>
#include "Filter.h"
#include "../../../Model/DTO/Questions/QuestionWithLikesAndSolves.h"
using namespace std;

class DifficultyLevelFilter : public FilterInterface {
public:
    vector<QuestionWithLikesAndSolves*> filter (vector<QuestionWithLikesAndSolves*>& questions, string& value) override {
        vector<QuestionWithLikesAndSolves*> filteredQuestions;
        int size = questions.size();
        for (int i=0; i<size; i++) {
            if (questions[i]->getDifficultyLevel() == value) {
                filteredQuestions.push_back(questions[i]);
            }
        }
        return filteredQuestions;
    }
};