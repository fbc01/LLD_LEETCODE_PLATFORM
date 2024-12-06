#include <iostream>
#include "../Builders/QuestionBuilder.h"
#include "../Strategies/Filter/Filter.h"
#include "../Strategies/Filter/FilterFactory.h"
#include "../Strategies/Sort/Sorting.h"
#include "../Strategies/Sort/SortingFactory.h"
#include "../../Model/DTO/Questions/QuestionWithLikesAndSolves.h"
#include "../../Model/Storage/QuestionLibrary.h"
#include <mutex>
using namespace std;

class QuestionManager {
private:
    static QuestionManager* instance;
    static mutex mtx;
    FilterFactory* filterFactory;
    SortingFactory* sortingFactory;

    QuestionManager() {
        filterFactory = new FilterFactory();
        sortingFactory = new SortingFactory();
    }

public:

    static QuestionManager* getInstance() {
        if (instance == NULL) {
            unique_lock<mutex> locker(mtx);
            mtx.lock();
            if (instance == NULL) {
                instance = new QuestionManager();
            }
            mtx.unlock();
        }
        return instance;
    }

    void addQuestion() {
        string description;
        string tag;
        string difficultyLevel;
        int score;
        cout << "Add Description = " << endl;
        cin >> description;
        cout << "Add Score = " << endl;
        cin >> score;
        cout << "Add Tag = " << endl;
        cin >> tag;
        cout << "Add DifficultyLevel = " << endl;
        cin >> difficultyLevel;

        QuestionBuilder* questionBuilder = new QuestionBuilder();
        questionBuilder->buildDescription(description);
        questionBuilder->buildScore(score);
        questionBuilder->buildTag(tag);
        questionBuilder->buildDifficultyLevel(difficultyLevel);
        Question* question = questionBuilder->build();

        QuestionWithLikesAndSolves* decoratedQuestion = new QuestionWithLikesAndSolves(question);
        QuestionLibrary* questionLibrary = QuestionLibrary::getInstance();
        questionLibrary->addQuestion(decoratedQuestion);
    }

    void showAllQuestions() {
        QuestionLibrary* questionLibrary = QuestionLibrary::getInstance();
        questionLibrary->showAllQuestions();
    }

    void filter() {
        string filterType, filterKey;
        cout << "How do you want to Filter Questions " << endl;
        cin >> filterType;
        cout << "Enter filter key" << endl;
        cin >> filterKey;
        FilterInterface* filterObject = filterFactory->getFilter(filterType);
        QuestionLibrary* questionLibrary = QuestionLibrary::getInstance();
        vector<QuestionWithLikesAndSolves*> questions = questionLibrary->getAllQuestions();
        vector<QuestionWithLikesAndSolves*> filteredQuestions = filterObject->filter(questions, filterKey);
        int size = filteredQuestions.size();
        for (int i=0; i<size; i++) {
            filteredQuestions[i]->display();
        }
    }

    void sorting() {
        string sortingType;
        cout << "How do you want to Sort questions" << endl;
        cin >> sortingType;
        Sorting* sortingObject = sortingFactory->getSortingObject(sortingType);
        QuestionLibrary* questionLibrary = QuestionLibrary::getInstance();
        vector<QuestionWithLikesAndSolves*> questions = questionLibrary->getAllQuestions();
        vector<QuestionWithLikesAndSolves*> sortedQuestions = sortingObject->sortList(questions);
        int size = sortedQuestions.size();
        for (int i=0; i<size; i++) {
            sortedQuestions[i]->display();
        }
    }

    void showQuestion(int questionId) {
        QuestionLibrary* questionLibrary = QuestionLibrary::getInstance();
        vector<QuestionWithLikesAndSolves*> questions = questionLibrary->getAllQuestions();
        int size = questions.size();
        for (int i=0; i<size; i++) {
            if (questions[i]->getQuestionId() == questionId) {
                questions[i]->display();
                return;
            }
        }
    }

    void showNMostLikedQuestionsWithGivenTag(int n, string tag) {
        FilterInterface* filterObject = filterFactory->getFilter("TAG");
        QuestionLibrary* questionLibrary = QuestionLibrary::getInstance();
        vector<QuestionWithLikesAndSolves*> questions = questionLibrary->getAllQuestions();
        vector<QuestionWithLikesAndSolves*> filteredQuestions = filterObject->filter(questions, tag);

        Sorting* sortingObject = sortingFactory->getSortingObject("LIKES");
        QuestionLibrary* questionLibrary = QuestionLibrary::getInstance();
        vector<QuestionWithLikesAndSolves*> questions = questionLibrary->getAllQuestions();
        vector<QuestionWithLikesAndSolves*> sortedQuestions = sortingObject->sortList(filteredQuestions);
        int size = sortedQuestions.size();
        for (int i=0; i<min(size, n); i++) {
            sortedQuestions[i]->display();
        }
    }
};