#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Delegator{
        queue<string> p_num;
        queue<string> j_num;
        set<string> asked_player_judge;
        Gamebook* GB;
        AI* ai;
        Helptool* help;
        TwilioClient* twilio;

        public:
        void analyze_request(string message, string number){
                asked_player_judge.push(number);
                Game *g = GB->inGame(number);
                if (g != NULL){
                        if(g->findRole(player) == "Judge"){  
                            //we know that this person is a judge
                            //the judge asks either the ai or the player a question
                            //we need to somehow determine whether the judge is either messaging the player or the ai
                            //the game class randomizes whether the player is either player a or player b; same with the ai
                            // if the message contains player a in it and if player a is assigned to the human, then we send the question to the player
                            // if the message contains player b in it and if player b is assigned to the human, then we send the question to the player
                            // if the message contains player a in it and if player a is assigned to the ai, then we send the question to the ai
                            // if the message contains player b in it and if player b is assigned to the ai, then we send the question to the ai
                            if(message.find("Player A") || message.find("player A") || message.find("Player a") || message.find("player a")){
                                if(Player = A){//however Jeremy and Rayan assign the player to either A or B in game class
                                        twilio -> send_sms(p_num, message);
                                }
                                else{
                                        ai -> askGPT(message);
                                }
                            }
                            
                            if(message.find("Player B") || message.find("player B") || message.find("Player b") || message.find("player b")){
                                if(Player = B){//however Jeremy and Rayan assign the player to either A or B in game class
                                        twilio -> send_sms(p_num, message);
                                    }
                                else{
                                        ai -> askGPT(message);
                                }
                            }
                        }
                
                        if(g->findRole(player) == "Player"){
                             //we know this person is a player
                             // this player has a responded to a judge's question, so we need to send the sms to twilio
                             twilio -> send_sms(j_num, message);
                        }
                }
                
                if (asked_player_judge.contains(number)){
                        if (message.find("Player") || message.find("player")){
                                p_num.push(number);
                                help->getPlayer();
                        }
                        
                        if (message.find("Judge") || message.find("judge")){
                                j_num.push(number);
                                help->getJudge();  
                        }
                        asked_player_judge.erase(number)
                }
                else{
                     help->error();
                     help->instructions();
                }
        }

        void pair_human_agent_evaluator(string p_num, string j_num){
                help->getPair();
                g = new Game(string p_num, string j_num);
                GB->addGame(g);
                g.start();
        }
        
};
