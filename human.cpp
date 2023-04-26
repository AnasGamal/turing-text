#include <string>
using namespace std;

class Human {
	string phoneNumber;
	string accountSID;
	string authToken;
	string twilioNum;

	public:
	void setPhoneNumber(string phoneNumber) {
		this ->phoneNumber = phoneNumber;
	}
	string getPhoneNumber() {
		return phoneNumber;
	}
	void setAccountSID(string accountSID) {
		this -> accountSID = accountSID;
	}
	string getAccountSID() {
		return accountSID;
	}
	void setAuthToken(string authToken) {
		this -> authToken = authToken;
	}
	string getAuthToken() {
		return authToken;
	}
	void setTwilioNum(string twilioNum) {
		this -> twilioNum = twilioNum;
	}
	string getTwilioNum() {
		return twilioNum;
	}
};
