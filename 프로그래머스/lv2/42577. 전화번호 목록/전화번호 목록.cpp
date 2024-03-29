#include <bits/stdc++.h>

using namespace std;

bool solution(vector<string> phone_book) {
    map<string, bool> phoneDict;
    for (vector<string>::iterator it = phone_book.begin(); it != phone_book.end(); it++)
    {
        phoneDict[*it] = false;
    }

    for (vector<string>::iterator it = phone_book.begin(); it != phone_book.end(); it++)
    {
        string phoneNumber = *it;
        for (int i = 1; i < phoneNumber.size(); i++)
        {
            if (phoneDict.find(phoneNumber.substr(0, i)) != phoneDict.end())
                return false;
        }
    }
    return true;
}