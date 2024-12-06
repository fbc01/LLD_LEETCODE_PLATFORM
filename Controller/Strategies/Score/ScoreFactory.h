#include <iostream>
#include "ScoreCalculator.h"
#include "CalculateScoreWithoutTime.h"
#include "CalculateScoreWithTime.h"
using namespace std;

class ScoreFactory {
public:
    ScoreCalculator* getScoreCalculator(string scoreCalculationType) {
        if (scoreCalculationType == "WITHOUT_TIME") {
            return new CalculateScoreWithoutTime();
        }
        else if (scoreCalculationType == "WITH_TIME") {
            return new CalculateScoreWithTime();
        }
        else return NULL;
    }
};
