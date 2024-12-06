#include<iostream>
using namespace std;

// Question Tags
const string TAG1 = "TAG1";
const string TAG2 = "TAG2";
const string TAG3 = "TAG3";

// Difficulty Levels
const string EASY = "EASY";
const string MEDIUM = "MEDIUM";
const string HARD = "HARD";


vector<string> getQuestionTags() {
    return {TAG1, TAG2, TAG3};
}

vector<string> getDifficultyLevels() {
    return {EASY, MEDIUM, HARD};
}
