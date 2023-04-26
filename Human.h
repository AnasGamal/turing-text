#ifndef HUMAN_H 
#define HUMAN_H

#include <string>
using namespace std;

class Human {
	
	private:
	string role;
	string accountSID;
	string authToken;
	string twilioNum;

	public:
	void setPhoneNumber(string phoneNumber);
	string getPhoneNumber();
	void setRole(string role);
	string getRole();
	void setAccountSID(string accountSID);
	string getAccountSID();
	void setAuthToken(string authToken) {
	string getAuthToken();
	void setTwilioNum(string twilioNum);
	string getTwilioNum(); 
};

#endif
