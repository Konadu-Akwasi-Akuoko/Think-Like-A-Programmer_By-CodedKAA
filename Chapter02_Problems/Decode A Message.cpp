#include <iostream>
using namespace std;

/*
PROBLEM: DECODE A MESSAGE

A message has been encoded as a text stream that is to be read character by character. 
The stream contains a series of comma-delimited integers, each a positive number capable of 
being represented by a C++ int. However, the character represented by a particular integer 
depends on the current decoding mode. There are three modes: uppercase, lowercase, and punctuation.
In uppercase mode, each integer represents an uppercase letter: The integer modulo 27 indicates 
the letter of the alphabet (where 1 = A and so on). So an input value of 143 in uppercase mode 
would yield the letter H because 143 modulo 27 is 8 and H is the eighth letter in the alphabet.
The lowercase mode works the same but with lowercase letters; the remainder of dividing the integer 
by 27 represents the lowercase letter (1 = a and so on). So an input value of 56 in lowercase mode 
would yield the letter b because 57 modulo 27 is 2 and b is the second letter in the alphabet.
In punctuation mode, the integer is instead considered modulo 9, with the interpretation given by 
Table 2-3 below. So 19 would yield an exclamation point because 19 modulo 9 is 1.
At the beginning of each message, the decoding mode is uppercase letters. Each time the modulo 
operation (by 27 or 9, depending on mode) results in 0, the decoding mode switches. If the current 
mode is uppercase, the mode switches to lowercase letters. If the current mode is lowercase, the 
mode switches to punctuation, and if it is punctuation, it switches back to uppercase.*/

//Modes of the application.
char Mode;
int currentMode = 0;
//The raw/coded number.
int codedNum;
char UCaseLetters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
char LCaseLetters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char Punctuations[] = {'!', '?', ',', '.', ' ', ';', '"', '\''};
void ModCalculator(int inputNum);
//The modulo for alphabets.
int AlphaNum = 27;
//The modulo for punctuations.
int PuncNum = 9;
void UpCaLettersConvert(int modAnswer);
void LoCaLettersConvert(int modAnswer);
void PunctuationConvert(int modAnswer);
void ChangeMode();
//The converted message.
string DecodeMessage;

// main() is where program execution begins.
int main()
{
    //When the program starts the mode is always set to U.
    Mode = 'U';
    //Get code character by character.
    cout << "Enter the coded message character by character. \n";
    cin >> codedNum;
    ModCalculator(codedNum);
}

//This calculates the number based on the current mode (U,L,P). It later sends the mod answer to the required location.
void ModCalculator(int inputNum)
{
    if (Mode == 'U')
    {
        int Answer = inputNum % AlphaNum;
        if (Answer != 0)
        {
            //Send the result to Upperalphabet function.
            UpCaLettersConvert(Answer);
        }
        else
        {
            //Send the result to modeChanger function.
            return;
        }
    }

    else if (Mode == 'L')
    {
        int Answer = inputNum % AlphaNum;
        if (Answer != 0)
        {
            //Send the result to Loweralphabet function.
            LoCaLettersConvert(Answer);
        }
        else
        {
            //Send the result to modeChanger function.
        }
    }

    else
    {
        int Answer = inputNum % PuncNum;
        if (Answer != 0)
        {
            //Send the result to punctuation function.
        }
        else
        {
            //Send the result to modeChanger function.
        }
    }
}

//Convert the decoded message to an UpperCase alphabet and put it in the string.
void UpCaLettersConvert(int modAnswer)
{
    //When the codedNum is converted to a number from 1 to 26, we choose the appopirate letter.
    //And we add it to the string using the push_back() function, it add it to the last place.
    DecodeMessage.push_back(UCaseLetters[modAnswer - 1]);
    cout << "The decoded letter is: " << UCaseLetters[modAnswer - 1] << endl;
    cout << "Here is the decoded message: " << DecodeMessage << endl;
}

void LoCaLettersConvert(int modAnswer)
{
    //When the codedNum is converted to a number from 1 to 26, we choose the appopirate letter.
    //And we add it to the string using the push_back() function, it add it to the last place.
    DecodeMessage.push_back(LCaseLetters[modAnswer - 1]);
    cout << "The decoded letter is: " << UCaseLetters[modAnswer - 1] << endl;
    cout << "Here is the decoded message: " << DecodeMessage << endl;
}

void PunctuationConvert(int modAnswer)
{
    DecodeMessage.push_back(Punctuations[modAnswer - 1]);
}

void ChangeMode()
{
    //Change the mode 
}