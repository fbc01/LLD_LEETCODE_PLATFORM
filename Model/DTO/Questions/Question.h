#include <iostream>
using namespace std;

static int AUTO_INCREMENTOR = 1;

class QuestionInterface {
public:
    virtual int getQuestionId() = 0;
    virtual string getDescription() = 0;
    virtual string getDifficultyLevel() = 0;
    virtual string getTag() = 0; // vector<string> for multiple tags
    virtual int getScore() = 0;
    virtual void display() = 0;
};

class Question : public QuestionInterface {
private:
    int questionId; // uuid better option
    string description;
    string tag;
    string difficultyLevel;
    int score;

public:
    Question() {
        this->questionId = AUTO_INCREMENTOR++;
        this->description = "";
        this->tag = "";
        this->difficultyLevel = "";
        this->score = 0;
    }

    // getters
    int getQuestionId() override {
        return this->questionId;
    }

    string getDescription() override {
        return this->description;
    }

    string getDifficultyLevel() override {
        return this->difficultyLevel;
    }

    string getTag() override {
        return this->tag;
    }

    int getScore() override {
        return this->score;
    }

    // setters
    void setDescription(string& description) {
        this->description = description;
    }
    
    void setTag(string& tag) {
        this->tag = tag;
    }

    void setDifficultyLevel(string& difficultyLevel) {
        this->difficultyLevel = difficultyLevel;
    }

    void setScore(int score) {
        this->score = score;
    }

    void display() override {
        cout << "QuestionId = " << this->questionId << endl;
        cout << "Description = " << this->description << endl;
        cout << "Tag = " << this->tag << endl;
        cout << "DifficultyLevel = " << this->difficultyLevel << endl;
    }
};
