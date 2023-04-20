#include <iostream>
#include <string>
using namespace std;

class Helptool{
  string initial_request = "Would you like to be a player or a judge?";
  string player = "You are now a player. Convince the judge that you are a human and not an AI by answering their questions";
  string judge = "You are now a judge. Ask questions to both a human player and an AI and figure out which is the human";
  string waitlist = "Please wait to be paired with another number";
  string pair = "You have been paired. Time to begin!";
}
public:
string getInitial(){
  return initial_request;
}

string getPlayer(){
  return player;
}

string getJudge(){
  return judge;
}

string getWait(){
  return waitlist;
}

string getPair()
  return pair;
}
};
