
#include "Delegator.h"
#include "HelpTool.h"
#include "Human.h"
#include "AI.h"
#include "Twilio.h"
#include "Results.h"
#include "GameBook.h"
#include "Game.h"
#include "Server.h"
using namespace std;

int main() {
	Delegator *delegator = new Delegator();	
	Human player;
	string phoneNum, accountSID, authToken, twilioNum;
	string api_key = read_api_key_from_file();
	
	cout << "Please enter your phone number." << endl;
	getline(cin, phoneNum);
	player.setPhoneNumber(phoneNum);
	
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
	client.start_twilio();
}
