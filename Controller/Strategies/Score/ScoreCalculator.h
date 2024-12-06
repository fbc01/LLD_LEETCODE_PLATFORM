#include <iostream>
#include "../../../Model/DTO/Interactions/SolvedQuestion.h"
using namespace std;

class ScoreCalculator {
public:
    virtual int calculate(SolvedQuestion* question) = 0;
};