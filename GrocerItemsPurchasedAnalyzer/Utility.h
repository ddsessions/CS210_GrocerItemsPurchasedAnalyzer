#pragma once
#include <string>
#include <sstream>

using namespace std;

class Utility
{
public:
    //Help minimize code in methods where whitespace and asterisks are repeated
    static string repeatCharNTimes(size_t n, char c) {
        string printString = "";

        for (int i = 0; i < n; i++) {
            printString += c;
        }

        return printString;
    }

    //Change all input strings to lowercase so the program is not case sensitive
    static string toLowerString(string t_value) {
        stringstream loweredString;

        for (char x : t_value) {
            loweredString << (char)tolower(x);
        }

        return loweredString.str();
    }
};