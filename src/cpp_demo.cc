#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <curl/curl.h>
#include "twilio.h"
#define MAX_TWILIO_MESSAGE_SIZE 1024


size_t _twilio_null_write(char *ptr, size_t size, size_t nmemb, void *userdata) {
	return size * nmemb;
}

class Twilio {
	private:
		char *account_sid;
		char *auth_token;
		char *from_number;
		CURL *curl;
	public:
		Twilio(char *account_sid, char *auth_token, char *from_number) {
			this->account_sid = account_sid;
			this->auth_token = auth_token;
			this->from_number = from_number;
			this->curl = curl_easy_init();
			curl_global_init(CURL_GLOBAL_ALL);
		}

		~Twilio() {
			curl_easy_cleanup(curl);
			curl_global_cleanup();
		}

		int send_message(char *message, char *to_number, char *picture_url, bool verbose) {
			printf("Message: %s\nTo Number: %s\nPicture URL: %s\nVerbose: %d\n", message, to_number, picture_url ? picture_url : "NULL", verbose);

			if (strlen(message) > 1600) {
				fprintf(stderr, "SMS send failed.\nMessage body must be less than 1601 characters.\nThe message had %zu characters.\n", strlen(message));
				return -1;
			}

			char url[MAX_TWILIO_MESSAGE_SIZE];
			snprintf(url, sizeof(url), "%s%s%s", "https://api.twilio.com/2010-04-01/Accounts/", this->account_sid, "/Messages");

			char parameters[MAX_TWILIO_MESSAGE_SIZE];
			if (!picture_url) {
				snprintf(parameters, sizeof(parameters), "%s%s%s%s%s%s", "To=", to_number, "&From=", this->from_number, "&Body=", message);
			} else {
				snprintf(parameters, sizeof(parameters), "%s%s%s%s%s%s%s%s", "To=", to_number, "&From=", this->from_number, "&Body=", message, "&MediaUrl=", picture_url);
			}

			curl_easy_reset(curl);
			curl_easy_setopt(curl, CURLOPT_POST, 1);
			curl_easy_setopt(curl, CURLOPT_URL, url);
			curl_easy_setopt(curl, CURLOPT_POSTFIELDS, parameters);
			curl_easy_setopt(curl, CURLOPT_USERNAME, this->account_sid);
			curl_easy_setopt(curl, CURLOPT_PASSWORD, this->auth_token);                        

			if (!verbose) {
				curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, _twilio_null_write);
			}

			CURLcode res = curl_easy_perform(curl);

			long http_code = 0;
			curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);

			if (res != CURLE_OK) {
				if (verbose) {
					fprintf(stderr, "SMS send failed: %s.\n", curl_easy_strerror(res));
				}
				return -1;
			} else if (http_code != 200 && http_code != 201) {
				if (verbose) {
					fprintf(stderr, "SMS send failed, HTTP Status Code: %ld.\n", http_code);
				}
				return -1;
			} else {
				if (verbose) {
					fprintf(stderr, "SMS sent successfully!\n");
				}
				return 0;
			}
		}
};

int main() {
	char account_sid[MAX_TWILIO_MESSAGE_SIZE] = "ACa930b837f18e77aaf249303b6f91288b";
	char auth_token[MAX_TWILIO_MESSAGE_SIZE] = "d2caecaebb0f0c4c80b7984e13f28272";
	char from_number[MAX_TWILIO_MESSAGE_SIZE] ="+18557381564";
	char to_number[MAX_TWILIO_MESSAGE_SIZE] = "+18135974145";
	char message[MAX_TWILIO_MESSAGE_SIZE] = "Hello Joshua.. We did it!";
	char *picture_url = NULL;
	bool verbose = true;
	Twilio twilio(account_sid, auth_token, from_number);

	int result = twilio.send_message( message,to_number, picture_url, verbose);

	if (result == 0) {
		printf("Message sent successfully!\n");
	} else {
		printf("Message failed to send.\n");
	}

	return 0;
}
