#include <iostream>
#include <algorithm>
#include "../../../Model/DTO/Questions/QuestionWithLikesAndSolves.h"
using namespace std;

class Sorting {
public:
    virtual vector<QuestionWithLikesAndSolves*> sortList (vector<QuestionWithLikesAndSolves*> questions) = 0;
};