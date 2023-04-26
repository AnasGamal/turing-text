#include "Ai.h"

Ai::Ai() {
    api_key = read_api_key_from_file();
}

string Ai::read_api_key_from_file() {
    ifstream api_key_file("OpenAiKey");
    string key;
    getline(api_key_file, key);
    return key;
}

void Ai::ltrim(string& s) {
    s.erase(s.begin(), find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !isspace(ch);
    }));
}

void Ai::rtrim(string& s) {
    s.erase(find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !isspace(ch) && ch != '.';
    }).base(), s.end());
}

void Ai::trim(string& s) {
    rtrim(s);
    ltrim(s);
}

string Ai::askGPT(string q) {
    string answer;
    int retries = 3;
    while (answer.empty() && retries > 0) {
        cout << "q: " << q << endl;
        const string body = "{\"model\": \"text-davinci-003\", \"prompt\": \"" + q + "\", \"temperature\": 0.5, \"max_tokens\": 500}";
        cpr::Response r = cpr::Post(cpr::Url{"https://api.openai.com/v1/completions"},
            cpr::Header{{"Authorization", "Bearer " + api_key}, {"Content-type", "application/json"}},
            cpr::Body{ body });
        auto d = json::parse(r.text);
        if (!d["choices"].empty()) {
            answer = d["choices"][0]["text"];
            trim(answer);
            cout << "response: " << answer << endl;
        }
        else {
            cout << "Invalid response: " << r.text << endl;
        }
        retries--;
    }
    return answer;
}

