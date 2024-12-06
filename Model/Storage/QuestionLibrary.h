#include <iostream>
#include <map>
#include <mutex>
#include "../DTO/Questions/QuestionWithLikesAndSolves.h"

using namespace std;

class QuestionLibrary {
private:
    map<int, QuestionWithLikesAndSolves*> questionsLibrary;
    QuestionLibrary() {} // singleton class
    static QuestionLibrary* instance;
    static mutex mtx;

public:
    static QuestionLibrary* getInstance() {
        if (instance == NULL) {
            unique_lock<mutex> locker(mtx);
            locker.lock();
            if (instance == NULL) {
                instance = new QuestionLibrary();
            }
            locker.unlock();
        }
        return instance;
    }

    void addQuestion(QuestionWithLikesAndSolves* question) {
        if (questionsLibrary.find(question->getQuestionId()) != questionsLibrary.end()) {
            cout << "Question with question id = " << question->getQuestionId() << " already exists" << endl;
            return;
        }
        questionsLibrary[question->getQuestionId()] = question;
    }

    QuestionWithLikesAndSolves* getQuestion(int questionId) {
        if (questionsLibrary.find(questionId) != questionsLibrary.end()) {
            return questionsLibrary[questionId];
        }
        else {
            cout << "Question with question id = " << questionId << " not found";
            return NULL;
        }
    }

    void removeQuestion(QuestionWithLikesAndSolves* question) {
        if (questionsLibrary.find(question->getQuestionId()) != questionsLibrary.end()) {
            questionsLibrary.erase(questionsLibrary.find(question->getQuestionId()));
            cout << "Question with question id = " << question->getQuestionId() << " is removed found";
        }
        else {
            cout << "Question with question id = " << question->getQuestionId() << " not found in bank";
        }
    }

    void showAllQuestions() {
        for (map<int, QuestionWithLikesAndSolves*>::iterator itr = begin(questionsLibrary); itr != end(questionsLibrary); itr++) {
            itr->second->display();
            cout << "-------------------------------" << endl;
        }
    }

    vector<QuestionWithLikesAndSolves*> getAllQuestions() {
        vector<QuestionWithLikesAndSolves*> questions;
        for (map<int, QuestionWithLikesAndSolves*>::iterator itr = begin(questionsLibrary); itr != end(questionsLibrary); itr++) {
            questions.push_back(itr->second);
        }
        return questions;
    }
};