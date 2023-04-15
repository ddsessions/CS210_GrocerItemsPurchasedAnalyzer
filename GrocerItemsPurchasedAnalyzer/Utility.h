#pragma once
#include <string>
#include <sstream>

using namespace std;

class Utility
{
public:
    static string repeatCharNTimes(size_t n, char c) {
        string printString = "";

        for (int i = 0; i < n; i++) {
            printString += c;
        }

        return printString;
    }

    static string toLowerString(string value) {
        stringstream loweredString;

        for (char x : value) {
            loweredString << (char)tolower(x);
        }

        return loweredString.str();
    }
};