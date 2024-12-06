#include <iostream>
#include "../DTO/Interactions/AttemptedQuestion.h"
#include "../DTO/Interactions/SolvedQuestion.h"
#include <mutex>
using namespace std;

class InteractionLibrary {
private:
    vector<AttemptedQuestion*> attemptedQuestions;
    vector<SolvedQuestion*> solvedQuestions;
    static InteractionLibrary* instance;
    static mutex mtx;

    InteractionLibrary() {}

public:

    static InteractionLibrary* getInstance() {
        if (instance == NULL) {
            unique_lock<mutex> locker(mtx);
            mtx.lock();
            if (instance == NULL) {
                instance = new InteractionLibrary();
            }
            mtx.unlock();
        }
        return instance;
    }

    void addAttemptedQuestion(AttemptedQuestion* attemptedQuestion) {
        this->attemptedQuestions.push_back(attemptedQuestion);
    }

    vector<AttemptedQuestion*> getAttemptedQuestions() {
        return this->attemptedQuestions;
    }

    void addSolvedQuestion(SolvedQuestion* solvedQuestion) {
        int size = this->solvedQuestions.size();
        for (int i=0; i<size; i++) {
            if (solvedQuestions[i]->getQuestion()->getQuestionId() == solvedQuestion->getQuestion()->getQuestionId() &&
                solvedQuestions[i]->getUsername() == solvedQuestion->getUsername()) {
                    cout << "User has already solved this question before" << endl;
                    return;
                }
        }
        this->solvedQuestions.push_back(solvedQuestion);
        cout << "User = " << solvedQuestion->getUsername() << "  has solved " << solvedQuestion->getQuestion()->getQuestionId() << " question" << endl;
    }

    vector<SolvedQuestion*> getSolvedQuestions() {
        return this->solvedQuestions;
    }
};