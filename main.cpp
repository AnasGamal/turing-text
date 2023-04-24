//Missing Functions Still Needed:
//twilio.receive_message() or sms.getMessage()
//getter for the active_games vector in gamebook
//helptool.generatePrompt()?
//where to use game.start() function?

#include <iostreamm>
#include "Delegator.h"
#include "HelpTool.h"
#include "Human.h"
#include "AI.h"
#include "Twilio.h"
#include "Results.h"
#include "GameBook.h"
#include "Game.h"
using namespace std;

int main() {
	Delegator delegator;	
	HelpTool tool;
	Human player;
	AI ai;
	Twilio twilio;
	GameBook gamebook;
	string phoneNum, aiResponse;
	string api_key = read_api_key_from_file();
	
	//how to get this as a user_message?
	cout << "Please enter your phone number." << endl;
	getline(cin, phoneNum);
	player.setPhoneNumber(phoneNum);
	//get account SID, authtoken, twilio#
	
	cout << "Please enter your Twilio phone number." << endl;'
	getline(cin, twilioNum);
	player.setTwilioNumber(twilioNum);

	cout << "Please enter your account SID." << endl;'
	getline(cin, accountSID);
	player.setAccountSID(accountSID);

	cout << "Please enter your Twilio authorization token." << endl;'
	getline(cin, authToken);
	player.setAuthToken(authToken);

	TwilioClient client(player.getAccountSID(), player.getAuthToken(), player.getTwilioNum())
	
	//when is this initial message sent?
	//need an if statement asking if there is a message waiting?
	string initial message =  "Welcome to Twilio Message SMS, do you want to be a player or judge?";
	client.send_sms(phoneNum, initial_message);
	bool gameActive = true;

	//if a message from user has been received (boolean)
	if (gameActive) {
		string user_message = twilio.receive_message();

		if (!user_message.empty()) {
			delegator.analyze_request(user_message);

			if (delegator.is_game_question(user_message)) {//if the user message is a question from the judge for participant and AI
				aiResponse = ai.askGPT(user_message);
				twilio.send_message(phoneNum, aiResponse);
	}
	//if player phoneNum has been added to judge or player queue
	if (!player.getRole().empty()) {//if the player has a role assigned 
		Game *current = game.getActiveGames().end();i//.back()
		//if a pair is matched 
		if (delegator.pairWaiting()) {
			delegator.pair_human_agent_evaluator();
			gamebook.save_game_data(current);
			gamebook.saveData();
		}
		//to end the game
		if (user_message == "exit") {
			gameActive = false;
			gamebook.removeGame(current);
			game.end();
		}
	}
}
