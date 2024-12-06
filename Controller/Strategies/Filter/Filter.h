#include <iostream>
#include "../../../Model/DTO/Questions/QuestionWithLikesAndSolves.h"
using namespace std;

class FilterInterface {
public:
    virtual vector<QuestionWithLikesAndSolves*> filter (vector<QuestionWithLikesAndSolves*>& questions, string& value) = 0;
};