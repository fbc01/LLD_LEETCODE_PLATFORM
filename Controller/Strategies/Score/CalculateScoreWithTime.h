#include <iostream>
#include "ScoreCalculator.h"
#include "../../../Model/DTO/Interactions/SolvedQuestion.h"
using namespace std;

class CalculateScoreWithTime : public ScoreCalculator {
public:
    int calculate(SolvedQuestion* question) override {
        int durationInMinutes = question->getDurationInMinutes();
        return question->getQuestion()->getScore() / durationInMinutes;
    }
};