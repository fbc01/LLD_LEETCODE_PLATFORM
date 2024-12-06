#include <iostream>
#include "ScoreCalculator.h"
#include "../../../Model/DTO/Interactions/SolvedQuestion.h"
using namespace std;

class CalculateScoreWithoutTime : public ScoreCalculator {
public:
    int calculate(SolvedQuestion* question) override {
        return question->getQuestion()->getScore();
    }
};