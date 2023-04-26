#ifndef HUMAN_H 
#define HUMAN_H

//class Human {
	/*string role;
	string accountSID;
	string authToken;
	string twilioNum;*/

//	public:
	void setPhoneNumber(string phoneNumber);
//		this ->phoneNumber = phoneNumber;
//	}
	string getPhoneNumber();
	//	return phoneNumber;
//	}
	void setRole(string role);
//		this ->role = role;
//	}
	string getRole();
//		return role;
//	}
	void setAccountSID(string accountSID);
//		this -> accountSID = accountSID;
//	}
	string getAccountSID();
//		return accountSID;
//	}
	void setAuthToken(string authToken) {
//		this -> authToken = authToken;
//	}
	string getAuthToken();
//		return authToken;
//	}
	void setTwilioNum(string twilioNum);
///		this -> twilioNum = twilioNum;	}
	string getTwilioNum(); 
//		return twilioNum;
//	}
class Human {
	string role, accountSID, authToken, twilioNum;
};

#endif
