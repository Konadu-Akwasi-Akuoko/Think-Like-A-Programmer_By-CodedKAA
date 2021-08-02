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

//Modes of the application. (U,L,P)
char Mode;
//The raw/coded number.
int codedNum;
//The coded string.
string stringOfNums;
char UCaseLetters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
char LCaseLetters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char Punctuations[] = {'!', '?', ',', '.', ' ', ';', '"', '\''};
void ModCalculator(int inputNum);
//The modulo for alphabets.
int AlphaNum = 27;
//The modulo for punctuations.
int PuncNum = 9;
void GetCodedNum();
void UpCaLettersConvert(int modAnswer);
void LoCaLettersConvert(int modAnswer);
void PunctuationConvert(int modAnswer);
void ChangeMode();
void SortCodedNum(string codedString);
//The converted message.
string DecodeMessage;

// main() is where program execution begins.
int main()
{
    //When the program starts the mode is always set to U.
    Mode = 'U';
    GetCodedNum();
}

//Get the coded number
void GetCodedNum()
{
    //Get all coded message in a string.
    cout << "Enter the coded message: \n";
    cin >> stringOfNums;
    //Call the SortCodeNum to sort and convert them into integers.
    SortCodedNum(stringOfNums);
}

//We need a function that can distinguish between a number and a comma. The function will treat any number
//before and after the comma as whole integers. The function will be called SortCodedNum(). It's primary
//function it to transform a set of string to integers and send them to the ModCalculator.
void SortCodedNum(string codedString)
{        
    int num;
    //Temporal variable where the coded numbers will be stored as strings.
    string tempCodedNum;

    //Loop through the string.
    for (int i = 0; i <= codedString.length() - 1; i++)
    {
        //Any number is added to the string using the push_back function, when it gets to a comma we pass the string into an int
        //and send it to the modolu calculator, we then clear the tempCodedNum. 
        if (codedString[i] != ',')
        {
            tempCodedNum.push_back(codedString[i]);
        }
        else if (codedString[i] == ',')
        {
            codedNum = stoi(tempCodedNum);
            cout << codedNum <<endl;
            tempCodedNum.clear();
            ModCalculator(codedNum);
        }
    }
     cout << "The dedcoded message is: " << DecodeMessage << endl;
}

//This calculates the number based on the current mode (U,L,P). It later sends the mod answer to the required function.
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
            ChangeMode();
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
            ChangeMode();
        }
    }

    else
    {
        int Answer = inputNum % PuncNum;
        if (Answer != 0)
        {
            //Send the result to punctuation function.
            PunctuationConvert(Answer);
        }
        else
        {
            //Send the result to modeChanger function.
            ChangeMode();
        }
    }
}

//Convert the decoded message to an UpperCase alphabet and put it in the string.
void UpCaLettersConvert(int modAnswer)
{
    //When the codedNum is converted to a number from 1 to 26, we choose the appopirate letter.
    //And we add it to the string using the push_back() function, it adds it to the last place.
    DecodeMessage.push_back(UCaseLetters[modAnswer - 1]);
    cout << "The decoded letter is: " << UCaseLetters[modAnswer - 1] << endl;
    //cout << "Here is the decoded message: " << DecodeMessage << endl;
}

void LoCaLettersConvert(int modAnswer)
{
    //When the codedNum is converted to a number from 1 to 26, we choose the appopirate letter.
    //And we add it to the string using the push_back() function, it adds it to the last place.
    DecodeMessage.push_back(LCaseLetters[modAnswer - 1]);
    cout << "The decoded letter is: " << LCaseLetters[modAnswer - 1] << endl;
    //cout << "Here is the decoded message: " << DecodeMessage << endl;
}

void PunctuationConvert(int modAnswer)
{
    //When the codeNum is converted to a number from one to nine we choose the appopirate punctuation.
    //And we add it to the string using the push_back() function.
    DecodeMessage.push_back(Punctuations[modAnswer - 1]);
    //cout << "Punctuation added: " << Punctuations[modAnswer - 1] << endl;
}

void ChangeMode()
{
    //Change the mode based on the current mode.
    switch (Mode)
    {
    case 'U':
        Mode = 'L';
        cout << "Mode changed to L \n";
        break;
    case 'L':
        Mode = 'P';
        cout << "Mode changed to P \n";
        break;
    case 'P':
        Mode = 'U';
        cout << "Moded changed to U \n";
        break;
    }
}