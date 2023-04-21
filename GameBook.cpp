#include <iostream>
#include <vector>
#include <fstream>
#include "Player.h"
#include "Human.h"
#include "AI.h"
#include "Evaluator.h"
#include "Results.h"
#include "HelpTool.h"

using namespace std;

class Game {
private:
    HumanAgent* human_agent;
    Evaluator* evaluator;
    AI* ai_agent;
    vector<string> prompts;
    map<string, string> responses;
    Results* result;

public:
    Game(HumanAgent* human_agent, Evaluator* evaluator, AI* ai_agent) {
        this->human_agent = human_agent;
        this->evaluator = evaluator;
        this->ai_agent = ai_agent;
        this->result = nullptr;
    }

    void start() {
        // Send prompt to human agent and AI agent
        cout << "Sending prompt to " << humanAgent << " and " << aiAgent << endl;

        // Receive responses from human agent and AI agent
        string humanResponse, aiResponse;
        cout << "Waiting for responses from " << humanAgent << " and " << aiAgent << endl;
        cin >> humanResponse >> aiResponse;

        // Send responses to evaluator
        cout << "Sending responses to " << evaluator << endl;
        cout << humanAgent << " response: " << humanResponse << endl;
        cout << aiAgent << " response: " << aiResponse << endl;
    }

    void end() {
        // Determine which player was determined to be AI
        string aiPrediciton;
        double ai_score_final;
        double human_score_final;
        if (evaluator_score1 > evaluator_score2) {
            aiPrediciton = "player1";
            //getScore?
            Results* results = new Results(score, comparison);
        } else {
            aiPrediciton = "player2";
            //getScore?
            Results* results = new Results(score, comparison);
        }
    }

    void save_game_data(GameBook* game_book) {
        game_book->addGame(this);
    }

    void receive_message(Player* player, string message) {
        this->responses[player->get_type()] = message;
        if (this->responses.size() == 3) {
            end();
        }
    }
};

class GameBook {
private:
    vector<Game*> active_games;

public:
    static GameBook& getInstance() {
        static GameBook instance;
        return instance;
    }

    void addGame(Game* game) {
        active_games.push_back(game);
    }

    void removeGame(Game* game) {
        auto it = find(active_games.begin(), active_games.end(), game);
        if (it != active_games.end()) {
            active_games.erase(it);
        }
    }

    void saveData() {
        void writeLog(const string& currentGame, const string& conversationLog) {
            // Open the file for writing
            ofstream file("Game" + currentGame + "_log.txt", ios::app); // ios::app to append to the end of the file

            // Write the conversation log to the file
            file << conversationLog << endl;

            file.close();
        }
    }
};

class Results {
private:
    double score;
    string comparison;

public:
    Results(double score, string comparison) {
        this->score = score;
        this->comparison = comparison;
    }

    double getScore() const {
        return score;
    }

    string getComparison() const {
        return comparison;
    }

    void setScore(double score) {
        this->score = score;
    }

    void setComparison(string comparison) {
        this->comparison = comparison;
    }
};

