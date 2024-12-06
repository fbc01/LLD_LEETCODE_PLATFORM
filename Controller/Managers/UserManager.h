#include <iostream>
#include <mutex>
#include "../../Model/DTO/Interactions/SolvedQuestion.h"
#include "../../Model/DTO/Questions/QuestionWithLikesAndSolves.h"
#include "../../Model/DTO/Users/User.h"
#include "../../Model/DTO/Users/UserWithAttempts.h"
#include "../../Model/Storage/InteractionLibrary.h"
#include "../../Model/Storage/QuestionLibrary.h"
#include "../../Model/Storage/UserLibrary.h"
#include "../Strategies/Score/ScoreCalculator.h"
#include "../Strategies/Score/ScoreFactory.h"
using namespace std;

class UserManager {
private:
    static UserManager* instance;
    static mutex mtx;
    ScoreFactory* scoreFactory;

    UserManager() {
        scoreFactory = new ScoreFactory();
    }

public:
    static UserManager* getInstance() {
        if (instance == NULL) {
            unique_lock<mutex> locker(mtx);
            locker.lock();
            if (instance == NULL) {
                instance = new UserManager();
            }
            locker.unlock();
        }
        return instance;
    }

    void registerUser() {
        string username;
        string password;
        string fullname;
        string department;
        cout << "Enter Username = " << endl;
        cin >> username;
        cout << "Enter Fullname = " << endl;
        cin >> fullname;
        cout << "Enter Department = " << endl;
        cin >> department;
        cout << "Enter Password = " << endl;
        cin >> password;

        User* user = new User(username, password, fullname, department);

        UserLibrary* userLibrary = UserLibrary::getInstance();
        userLibrary->addUser(user);
    }

    void login() {
        // this should be at User level
        string username;
        string password;
        cout << "Enter Username = " << endl;
        cin >> username;
        cout << "Enter Password = " << endl;
        cin >> password;

        UserLibrary* userLibrary = UserLibrary::getInstance();
        User* existingUser = userLibrary->getUser(username);
        if (existingUser != NULL) {
            if (existingUser->getPassword() == password) {
                cout << "User logged in successfully" << endl;
            } else {
                cout << "User password not correct" << endl;
            }
        }
    }

    void solve(int questionId, string& username, int durationInMinutes) {
        InteractionLibrary* interactionLibrary = InteractionLibrary::getInstance();
        QuestionLibrary* questionLibrary = QuestionLibrary::getInstance();
        QuestionWithLikesAndSolves* question = questionLibrary->getQuestion(questionId);
        SolvedQuestion* solvedQuestion = new SolvedQuestion(username, question, durationInMinutes);
        interactionLibrary->addSolvedQuestion(solvedQuestion);
    }

    void getSolvedQuestionsByUser(string& username) {
        InteractionLibrary* interactionLibrary = InteractionLibrary::getInstance();
        vector<SolvedQuestion*> solvedQuestions = interactionLibrary->getSolvedQuestions();
        vector<SolvedQuestion*> solvedByCurrentUser = {};
        int size = solvedQuestions.size();
        for (int i=0; i<size; i++) {
            if (solvedQuestions[i]->getUsername() == username) {
                solvedQuestions[i]->display();
            }
        }
    }

    double getScore(string& username, string scoringStrategy) {
        ScoreCalculator* scoreCalculator = scoreFactory->getScoreCalculator(scoringStrategy);
        double score = 0;
        InteractionLibrary* interactionLibrary = InteractionLibrary::getInstance();
        vector<SolvedQuestion*> solvedQuestions = interactionLibrary->getSolvedQuestions();
        vector<SolvedQuestion*> solvedByCurrentUser = {};
        int size = solvedQuestions.size();
        for (int i=0; i<size; i++) {
            if (solvedQuestions[i]->getUsername() == username) {
                score += scoreCalculator->calculate(solvedQuestions[i]);
            }
        }
        return score;
    }

    void showScore(string& username) {

        string scoringStrategy;
        cout << "Which Scoring strategy do you want to use" << endl;
        cin >> scoringStrategy;
        cout << getScore(username, scoringStrategy) << endl;
    }

    void getLeader() {
        UserLibrary* userLibrary = UserLibrary::getInstance();
        vector<User*> allUsers = userLibrary->getAllUsers();
        string leaderUsername = "";

        string scoringStrategy;
        cout << "Which Scoring strategy do you want to use" << endl;
        cin >> scoringStrategy;

        double maxScore = 0;
        int size = allUsers.size();
        for (int i=0; i<size; i++) {
            string username = allUsers[i]->getUsername();
            double score = getScore(username, scoringStrategy);
            if (score > maxScore) {
                leaderUsername = username;
                maxScore = score;
            }
        }
        User* user = userLibrary->getUser(leaderUsername);
        cout << "Current Leader = " << endl;
        user->showContestant();
    }
};