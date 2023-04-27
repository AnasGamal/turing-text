#ifndef HELPTOOL_H
#define HELPTOOL_H

#include <iostream>
#include <string>
using namespace std;

class Helptool{
  string instructions = "Welcome to the Turing Text Game! You will be assigned to either a player or a judge. If you are a judge, you will ask questions to both another human player or an AI from ChatGPT and figure out which is the human based on their answers. If you are a player, you will try and convince the judge that you are a human based on your answers"; 
  string initial_request = "Would you like to be a player or a judge?";
  string player = "You are now a player. Convince the judge that you are a human and not an AI by answering their questions";
  string judge = "You are now a judge. Ask questions to both a human player and an AI and figure out which is the human";
  string waitlist = "Please wait to be paired with another number";
  string pair = "You have been paired. Time to begin!";
  string error = "Your response is invalid.";

public:
  string getinstructions();
  string getInitial();
  string getPlayer();
  string getJudge();
  string getWait();
  string getPair();
  string getError();
};

#endif
