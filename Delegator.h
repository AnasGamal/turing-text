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
        Twilio* twilio;

        public:
        void analyze_request(string message, string number){
                asked_player_judge.push(number);
                Game *g = GB->inGame(number);
                if (g != NULL){
                        if(g->findRole(player) == "Judge"){  
                            if(){
                                    twilio -> send_message(message, p_num);
                            }
                            else{
                                    ai -> askGPT(message);
                            }
                        }
                
                        if(g->findRole(player) == "Player"){
                             //we know this person is a player
                             // this player has a responded to a judge's question, so we need to send the sms to twilio
                             twilio -> send_message(message, j_num);
                        }
                }
                
                if (asked_player_judge.contains(number)){
                        if (message == "Player"){
                                p_num.push(number);
                                help->getPlayer();
                        }
                        
                        if (message == "Judge"){
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
