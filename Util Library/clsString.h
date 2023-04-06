#pragma once

#include <iostream>
#include <vector>
using namespace std;

class clsString
{

private:
    string _Value;

public:

    clsString() {
        _Value = "";
    }

    clsString(string Value) {
        _Value = Value;
    }


    void SetValue(string Value) {
        _Value = Value;
    }

    string GetValue() {
        return _Value;
    }

    __declspec(property(get = GetValue, put = SetValue)) string Value;





    static short CountWords(string S1)
    {
        string delim = " ";
        short pos = 0;
        string sWord = "";
        short Counter = 0;
        while ((pos = S1.find(delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos);
            if (sWord != "")
            {
                Counter++;
            }
            S1.erase(0, pos + delim.length());
        }
        if (S1 != "")
        {
            Counter++;
        }
        return Counter;
    }

    short CountWords()
    {
        return CountWords(_Value);
    }

    static vector<string> Split(string S1, string delim)
    {
        short pos = 0;
        string sWord = "";
        vector<string> VString;
        while ((pos = S1.find(delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos);
            if (sWord != "")
            {
                VString.push_back(sWord);
            }
            S1.erase(0, pos + delim.length());
        }
        if (S1 != "")
        {
            VString.push_back(S1);
        }
        return VString;
    }


    vector <string> Split() {
        return Split(_Value, " ");
    }


    static string JoinString(vector <string> vString, string delim) {

        string S1 = "";
        for (string& s : vString) {


            S1 = S1 + s + delim;

        }
        return S1.substr(0, S1.length() - delim.length());
    }


    static string JoinString(string arrString[], short Length, string delim) {

        string S1 = "";
        for (short i = 0; i < Length; i++) {


            S1 = S1 + arrString[i] + delim;

        }
        return S1.substr(0, S1.length() - delim.length());
    }

    static string ReplaceString(string S1, string StringToReplace, string ReplaceTo, bool MatchCase = true) {

        vector <string> vString;


        vString = Split(S1, " ");

        for (string& s : vString) {

            if (MatchCase) {

                if (s == StringToReplace) {

                    s = ReplaceTo;
                }

            }
            else {

                if (LowerAllString(s) == LowerAllString(StringToReplace)) {

                    s = ReplaceTo;
                }


            }

        }
        return JoinString(vString, " ");
    }


    string ReplaceString(string StringToReplace, string ReplaceTo, bool MatchCase = true) {

        return ReplaceString(_Value, StringToReplace, ReplaceTo, MatchCase);

    }



    static string TrimLeft(string S1)
    {
        for (int i = 0; i < S1.length(); i++)
        {

            if (S1[i] != ' ') {

                return  S1.substr(i, S1.length() - i);
            }

        }
        return "";

    }

    string TrimLeft()
    {
        return TrimLeft(_Value);
    }

    static string TrimRight(string S1)
    {
        for (int i = S1.length() - 1; i >= 0; i--)
        {
            if (S1[i] != ' ') {

                return S1.substr(0, i + 1);

            }

        }
        return "";

    }

    string TrimRight()
    {
        return TrimRight(_Value);
    }

    static string Trim(string S1) {
        return  TrimLeft(TrimRight(S1));

    }

    void Trim() {

        TrimLeft(TrimRight(_Value));

    }


    static short Length(string S1) {

        return S1.length();
    }


    short Length() {
        return _Value.length();
    }


    static string UpperAllString(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
        {
            S1[i] = toupper(S1[i]);
        }
        return S1;
    }


    string UpperAllString()
    {
        return UpperAllString(_Value);
    }


    static string LowerAllString(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
        {
            S1[i] = tolower(S1[i]);
        }
        return S1;
    }

    string LowerAllString()
    {
        return LowerAllString(_Value);
    }

    static string ReverseString(string S1) {

        vector <string> vString;
        string S2 = "";

        vString = Split(S1, " ");
        vector <string>::iterator iter = vString.end();

        while (iter != vString.begin()) {

            --iter;

            S2 += *iter + " ";

        }

        S2 = S2.substr(0, S2.length() - 1);

        return S2;
    }


    string ReverseString() {

        return ReverseString(_Value);
    }


    static string RemovePunctuation(string S1) {

        string S2 = "";
        for (short i = 0; i < S1.length(); i++) {

            if (!ispunct(S1[i])) {

                S2 += S1[i];
            }
        }

        return S2;
    }


    string RemovePunctuation() {

        return RemovePunctuation(_Value);
    }


    static string PrintUpperFirstLetterOfEachWord(string S1)
    {
        bool isFirstLetter = true;
        for (short i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ' && isFirstLetter)
            {
                S1[i] = toupper(S1[i]);
            }
            isFirstLetter = S1[i] == ' ' ? true : false;
        }
        return S1;
    }

    void PrintUpperFirstLetterOfEachWord()
    {
        _Value = PrintUpperFirstLetterOfEachWord(_Value);
    }


    static string PrintLowerFirstLetterOfEachWord(string S1)
    {
        bool isFirstLetter = true;
        for (short i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ' && isFirstLetter)
            {
                S1[i] = tolower(S1[i]);
            }
            isFirstLetter = S1[i] == ' ' ? true : false;
        }
        return S1;
    }


    void PrintLowerFirstLetterOfEachWord()
    {
        _Value = PrintLowerFirstLetterOfEachWord(_Value);
    }

    static string InvertAllLetterCases(string S1)
    {

        for (short i = 0; i < S1.length(); i++)
        {
            S1[i] = InvertLetterCase(S1[i]);

        }

        return S1;
    }

    void InvertAllLetterCases() {

        _Value = InvertAllLetterCases(_Value);
    }

    static char InvertLetterCase(char Ch1)
    {
        return isupper(Ch1) ? tolower(Ch1) : toupper(Ch1);

    }





    static void PrintEachWordInString(string S1)
    {
        string delim = " ";
        short pos = 0;
        string sWord = "";

        while ((pos = S1.find(delim)) != std::string::npos)
        {

            sWord = S1.substr(0, pos);

            if (sWord != "")
            {

                cout << sWord << endl;
            }
            S1.erase(0, pos + delim.length());
        }
        if (S1 != "")
        {
            cout << S1 << endl;
        }
    }


    void PrintEachWordInString()
    {
        return PrintEachWordInString(_Value);
    }



    static void PrintAllVowelsInString(string S1)
    {

        for (short i = 0; i < S1.length(); i++)
        {
            if (isVowel(S1[i]))
            {

                cout << S1[i] << "  ";

            }
        }
    }

    void PrintAllVowelsInString()
    {
        return PrintAllVowelsInString(_Value);
    }

    static short CountSpecificLetters(string S1, char Ch1, bool MatchCase = true)
    {
        short Count = 0;
        for (short i = 0; i < S1.length(); i++)
        {
            if (MatchCase)
            {
                if (Ch1 == S1[i]) {
                    Count++;
                }
            }
            else
            {
                if (tolower(Ch1) == tolower(S1[i]))
                {
                    Count++;
                }
            }
        }
        return Count;
    }




    static short CountVowels(string S1)
    {
        short Count = 0;
        for (short i = 0; i < S1.length(); i++)
        {
            if (isVowel(S1[i]))
            {
                Count++;
            }
        }
        return Count;
    }

    short CountVowels()
    {
        return CountVowels(_Value);
    }



    static short CountCapitalLetters(string S1)
    {
        short Count = 0;
        for (short i = 0; i < S1.length(); i++)
        {
            if (isupper(S1[i]))
            {
                Count++;
            }
        }
        return Count;
    }

    short CountCapitalLetters()
    {
        return CountCapitalLetters(_Value);
    }


    static short CountSmallLetters(string S1)
    {
        short Count = 0;
        for (short i = 0; i < S1.length(); i++)
        {
            if (islower(S1[i]))
            {
                Count++;
            }
        }
        return Count;
    }

    short CountSmallLetters()
    {
        return CountSmallLetters(_Value);
    }

    static bool isVowel(char Ch1)
    {
        Ch1 = tolower(Ch1);
        return (Ch1 == 'a') || (Ch1 == 'o') || (Ch1 == 'u') || (Ch1 == 'e') || (Ch1 == 'i');
    }

};


