#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Delegator{
        queue<string> p_num;
        queue<string> j_num;
        Gamebook* GB;
        AI* ai;
        Helptool* help;
        Twilio* twilio;

        public:
        void addPlayerID() {
                p_num.push(player.getPhoneNumber());
        }

        void addJudgeID() {
                j_num.push(judge.getPhoneNumber());
        }

        void analyze_request(string message, string number){
                if (message == "Player"){
                        addPlayerID();
                        tool.getPlayer();
                }
                if (message == "Judge"){
                        addJudgeID();
                        tool.getJudge();
                }
        }

        void pair_human_agent_evaluator(string p_num, string j_num){
                tool.getPair();
                g = new Game(string p_num, string j_num);
                gamebook->addGame(g);
                g.start();
        }
        
        bool pairWaiting(){
                if (!get_p_num().empty() && !get_j_num().empty()){
                        return true;    
                }
                else{
                        return false;
                }
        }
        
        bool is_game_question(string message){
               if (message -> j_num){
                       return true;
               }
               else{
                       return false;
               }
        }
};
