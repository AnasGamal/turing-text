#include <string>
#include <iostream>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include <fstream>

using namespace std;
using json = nlohmann::json;

//trim from start (in place)
static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

// trim from end (in place)
static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch) && ch != '.';
    }).base(), s.end());
}

// trim from both ends (in place)
static inline void trim(std::string &s) {

    	rtrim(s);
    ltrim(s);
}

string askGPT(string q, const string& api_key) {
    string answer;
    int retries = 3; // Set a limit for the number of retries
    while (answer.empty() && retries > 0) { // Check for empty response and remaining retries
        cout << "q: " << q << endl;
        const string body = "{\"model\": \"text-davinci-003\", \"prompt\": \"" + q + "\", \"temperature\": 0.5, \"max_tokens\": 500}";
        cpr::Response r = cpr::Post(cpr::Url{"https://api.openai.com/v1/completions"},
            cpr::Header{{"Authorization", "Bearer " + api_key}, {"Content-type", "application/json"}},
            cpr::Body{body});
        auto d = json::parse(r.text);
        if (!d["choices"].empty()) { // Check if "choices" array is not empty
            answer = d["choices"][0]["text"];
            trim(answer);
            cout << "response: " << answer << endl;
        } else {
            cout << "Invalid response: " << r.text << endl;
        }
        retries--; // Decrement retries counter
    }
    return answer;
}


std::string read_api_key_from_file() {
    std::ifstream api_key_file("OpenAiKey");
    std::string api_key;
    std::getline(api_key_file, api_key);
    return api_key;
}

int main() {
    string api_key = read_api_key_from_file();
    string response = askGPT(question, api_key);
    cout << "AI response: " << response << endl;
}


