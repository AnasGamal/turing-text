#include <string>
using namespace std;

class Human {
	string phoneNumber;
	string role;

	public:
	void setPhoneNumber(string phoneNumber) {
		this ->phoneNumber = phoneNumber;
	}
	string getPhoneNumber() {
		return phoneNumber;
	}
	void setRole(string role) {
		this ->role = role;
	}
	string getRole() {
		return role;
	}
};
