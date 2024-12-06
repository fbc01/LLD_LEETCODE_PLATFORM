#include <iostream>
#include "../../Model/DTO/Questions/Question.h"
using namespace std;


class QuestionBuilder {
private:
    Question* question;

public:
    QuestionBuilder() {
        question = new Question();
    }

    void buildDescription(string& description) {
        question->setDescription(description);
    }

    void buildTag(string& tag) {
        question->setTag(tag);
    }

    void buildDifficultyLevel(string& difficultyLevel) {
        question->setDifficultyLevel(difficultyLevel);
    }

    void buildScore(int score) {
        question->setScore(score);
    }

    Question* build() {
        return question;
    }
};
