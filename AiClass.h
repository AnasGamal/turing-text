#ifndef AI_H
#define AI_H

#include <string>
#include <iostream>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include <fstream>

using namespace std;
using json = nlohmann::json;

class Ai {
private:
    string api_key;
public:
    Ai();
    string read_api_key_from_file();
    static void ltrim(string& s);
    static void rtrim(string& s);
    static void trim(string& s);
    string askGPT(string q);
};

#endif

