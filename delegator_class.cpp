#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Delegator{
        queue<string> p_num;
        queue<string> j_num;
        Gamebook* GB
        AI* ai;
        Human* hum;
        Helptool* help;
        Twilio* twilio;

        public:
        Human player, judge;
        HelpTool tool;
        Twilio sms;

        string message = sms.getMessage();

        void addPlayerID() {
                p_num.push(player.getPhoneNumber());
        }

        void addJudgeID() {
                j_num.push(judge.getPhoneNumber());
        }

        void analyze_request(string message){
                if (message == "Player"){
                        addPlayerID();
                        tool.getPlayer();
                }
                if (message == "Judge"){
                        addJudgeID();
                        tool.getJudge();
                }
        }

        void pair_human_agent_evaluator(){
                tool.getPair;
                g = new Game(string p_num, string j_num);
                GB->addGame(g);
        }

        void setHuman(Human* h){
                hum = h;
        }

        void setGamebook(Gamebook* gb){
                GB = gb;
        }

        void setAI(AI* a){
                ai = a;
        }

        void setTwilio(Twilio* t){
                twilio = t;
        }
        
        void setHelpTool(Helptool* ht){
                help = ht;
        }
};
