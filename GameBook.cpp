#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Game {
private:
    Human *human_agent;
    Human *evaluator;
    Ai *ai_agent;
    vector<string> prompts;
    map<string, string> responses;
    Results *result;
    map<string, string> playerAB;

public:
    Game(Human *human_agent, Human *evaluator, AI *ai_agent, Results *result) {
        this->human_agent = human_agent;
        this->evaluator = evaluator;
        this->ai_agent = ai_agent;
        this->result = results;
    }

    void start() {
        /*
        bool human_is_judge = rand() % 2 == 0;
        string human_role = human_is_judge ? "Judge" : "Player";
        string ai_role = human_is_judge ? "Player" : "Judge";

        // Create player objects based on their roles
        HumanAgent *human_agent = human_is_judge ? new Judge() : new Player();
        AI* ai_agent = !human_is_judge ? new Judge() : new Player();
        */

        // Set the instance of each player to the game
        Game game(human_agent, evaluator, ai_agent);

        // Randomly assign roles to players
        srand(time(nullptr));
        int randomNum = rand() % 2;
        if (randomNum == 0) {
            return "A";
        } else {
            return "B";
        }

        /*
        // Send prompt to human agent and AI agent
        cout << "Sending prompt to " << human_agent->get_type() << " and " << ai_agent->get_type() << endl;

        // Receive responses from human agent and AI agent
        string humanResponse, aiResponse;
        cout << "Waiting for responses from " << human_agent->get_type() << " and " << ai_agent->get_type() << endl;
        cin >> humanResponse >> aiResponse;

        // Send responses to evaluator
        cout << "Sending responses to " << evaluator->get_type() << endl;
        cout << human_agent->get_type() << " (" << human_role << ") response: " << humanResponse << endl;
        cout << ai_agent->get_type() << " (" << ai_role << ") response: " << aiResponse << endl;
         */
    }

    void createPlayer(string phoneNum){
        playerAB[phoneNum] = defineLetter();
    }

    /*
    string defineLetter() {
        srand(time(nullptr));

        int randomNum = rand() % 2;

        if (randomNum == 0) {
            return "A";
        } else {
            return "B";
        }
    }
     */

    string playerLetter(string phoneNum){
        try {
            return playerAB.at(phoneNum);
        } catch (const out_of_range& e) {
            return NULL;
        }
    }

    void end() {
        // Determine which player was thought to be AI
        string aiPrediciton; //Player A or B
        double finalScoreA;
        double finalScoreB;
        if (finalScoreA > finalScoreB) {
            aiPrediciton = "A";
            score = Results.getScore();
            comparison = Results.getComparison();
            results = new Results(score, comparison);
        } else {
            aiPrediciton = "B";
            score = Results.getScore();
            comparison = Results.getComparison();
            results = new Results(score, comparison);
        }
    }

    string findRole(string phoneNum) {
        if(phoneNum == human_agent->getPhoneNumber()) {
            return "Player";
        } else if(phoneNum == evaluator->getPhoneNumber()) {
            return "Judge";
        } else {
            return NULL;
        }
    }
    
    string player_num(){
        return human_agent->getPhoneNumber;
    }
    
    string judge_num(){
        return evaluator->getPhoneNumber;
    }

    void save_game_data(GameBook *game_book) {
        game_book->addGame(this);
    }

    void receive_message(Player *player, string message) {
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

    void addGame(Game *game) {
        active_games.push_back(game);
    }

    void removeGame(Game *game) {
        auto it = find(active_games.begin(), active_games.end(), game);
        if (it != active_games.end()) {
            active_games.erase(it);
        }
    }
    // check if phone number is in an active game, if so, returns the game.
    Game* inGame(string phoneNum) {
        for(Game *game : active_games){
            if(game->getHuman_agent().getPhoneNumber() || game->getEvaluator().getPhoneNumber() == phoneNum) {
                return game;
            } else {
                return NULL;
            }
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
