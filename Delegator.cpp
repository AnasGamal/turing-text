#include <iostream>
#include <string>
#include <queue>
#include <set>
#include "GameBook.h"
#include "AiClass.h"
#include "HelpTool.h"
#include "Twilio.h"

using namespace std;

class Delegator{
        queue<string> p_num;
        queue<string> j_num;
        set<string> asked_player_judge;
        GameBook* GB;
        AiClass* ai;
        HelpTool* help;
        Twilio* twilio;

        public:
        void analyze_request(string message, string number){
                asked_player_judge.insert(number);
                Game *g = GB->inGame(number);
                if (g != NULL){
                        asked_player_judge.erase(number);
                        if(g->findRole(number) == "Judge"){
                            //we know that this person is a judge
                            //the judge asks either the ai or the player a question
                            //we need to somehow determine whether the judge is either messaging the player or the ai
                            //the game class randomizes whether the player is either player a or player b; same with the ai
                            // if the message contains player a in it and if player a is assigned to the human, then we send the question to the player
                            // if the message contains player b in it and if player b is assigned to the human, then we send the question to the player
                            // if the message contains player a in it and if player a is assigned to the ai, then we send the question to the ai
                            // if the message contains player b in it and if player b is assigned to the ai, then we send the question to the ai
                            if(message.find("Player A") || message.find("player A") || message.find("Player a") || message.find("player a")){
                                g -> player_num();
                                if(g->playerLetter(player_num()) == "A"){
                                        twilio -> send_sms(player_num(), message);
                                }
                                else{
                                        ai -> askGPT(message, "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");
                                }
                            }

                            if(message.find("Player B") || message.find("player B") || message.find("Player b") || message.find("player b")){
                                g -> player_num();
                                if(g->playerLetter(player_num()) == "B"){
                                        twilio -> send_sms(player_num(), message);
                                }
                                else{
                                        ai -> askGPT(message, "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");
                                }
                            }
                        }

                        if(g->findRole(number) == "Player"){
                             //we know this person is a player
                             // this player has a responded to a judge's question, so we need to send the sms to twilio
                             g -> judge_num();
                             twilio -> send_sms(judge_num(), message);
                        }
                }

                 if (asked_player_judge.find(number) != asked_player_judge.end()){
                        if (message.find("Player") || message.find("player")){
                                p_num.push(number);
                                help -> getPlayer();
                        }

                        if (message.find("Judge") || message.find("judge")){
                                j_num.push(number);
                                help -> getJudge();
                        }
                        asked_player_judge.erase(number);
                }

                else {
                     help -> error();
                     help -> initial_request();
                }
        }

        void pair_human_agent_evaluator(string p_num, string j_num){
                help -> getPair();
                Game g = new Game(p_num, j_num);
                GB -> addGame(g);
                g->start();
        }

};
