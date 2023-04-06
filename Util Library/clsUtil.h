#pragma once

#include <iostream>
#include "clsDate.h"
using namespace std;

class clsUtil
{

private:


public:


	static void Srand() {
		srand((unsigned)time(NULL));
	}

	static int RandomNumber(int From, int To)
	{

		int randNum = rand() % (To - From + 1) + From;

		return randNum;
	}

    enum enCharType
    {
        SmallLetter = 1,
        CapitalLetter = 2,
        SpecialCharacter = 3,
        Digit = 4,
        MixChars = 5
    };

    static char GetRandomCharacter(enCharType CharType)
    {

        switch (CharType)
        {
        case enCharType::SmallLetter:
            return char(RandomNumber(97, 122));
            break;

        case enCharType::CapitalLetter:
            return char(RandomNumber(65, 90));
            break;

        case enCharType::SpecialCharacter:
            return char(RandomNumber(33, 47));
            break;

        case enCharType::Digit:
            return char(RandomNumber(48, 57));
            break;


        case enCharType::MixChars:
            return char(RandomNumber(48, 122));
            break;



        default:
            break;
        }

        return char(enCharType::SmallLetter);
    }

   static string GenerateWord(enCharType CharType, short length)
    {

        string word = "";

        for (int i = 1; i <= length; i++)
        {
            word += GetRandomCharacter(enCharType::CapitalLetter);
        }

        return word;
    }

   static string GenerateKey(enCharType CharType)
    {

        string Key = "";

        Key += GenerateWord(CharType, 4) + "-";
        Key += GenerateWord(CharType, 4) + "-";
        Key += GenerateWord(CharType, 4) + "-";
        Key += GenerateWord(CharType, 4);

        return Key;
    }

    static void GenerateKeys(short NumberOfKeys , enCharType CharType)
    {

        for (int i = 1; i <= NumberOfKeys; i++)
        {
            cout << "Key "
                << "[" << i << "]: " << GenerateKey(CharType) << endl;
        }
    }

    static void Swap(int& A, int& B)
    {
        int Temp;
        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(double& A, double& B)
    {
        double Temp;
        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(string& A, string& B)
    {
        string Temp;
        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(clsDate& A, clsDate& B)
    {
        clsDate Temp;
        Temp = A;
        A = B;
        B = Temp;
    }

    static void ShuffleArray(int arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }
    }



    static void ShuffleArray(string arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }
    }
    

    static void FillArrayWithRandomNumbers(int arr[100], int arrLength , int From , int To)
    {

        for (int i = 0; i < arrLength; i++)
        {
            arr[i] = RandomNumber(From, To);
        }
    }

    static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType , int WordLength)
    {

        for (int i = 0; i < arrLength; i++)
        {
            arr[i] = GenerateWord(CharType, WordLength);;
        }
    }


    static void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType)
    {

        for (int i = 0; i < arrLength; i++)
        {
            arr[i] = GenerateKey(CharType);;
        }
    }

    static string  Tabs(short NumberOfTabs)
    {
        string t = "";

        for (int i = 1; i < NumberOfTabs; i++)
        {
            t = t + "\t";
            cout << t;
        }
        return t;

    }

    static string EncryptText(string Text, short EncryptKey) {

        for (int i = 0; i <= Text.length(); i++)
        {
            Text[i] = char((int)Text[i] + EncryptKey);
        }

        return Text;

    }

    static string DecryptText(string Text, short EncryptKey) {

        for (int i = 0; i <= Text.length(); i++)
        {
            Text[i] = char((int)Text[i] - EncryptKey);
        }

        return Text;

    }

};

