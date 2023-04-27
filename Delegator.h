#ifndef DELEGATOR_H
#define DELEGATOR_H

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
        void analyze_request(string message, string number);
        void pair_human_agent_evaluator(string p_num, string j_num);
};

#endif
