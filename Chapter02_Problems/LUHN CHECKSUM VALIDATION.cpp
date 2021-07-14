#include <iostream>
using namespace std;

/*PROBLEM: LUHN CHECKSUM VALIDATION
The Luhn formula is a widely used system for validating identification numbers. Using the original number, 
double the value of every other digit. Then add the values of the individual digits together (if a doubled 
value now has two digits, add the digits individually). The identification number is valid if the sum is divisible by 10.
    
Write a program that takes an identification number of arbitrary length and determines whether the number 
is valid under the Luhn formula. The program must process each character before reading the next one.
*/

string idNumber;
int lentghOfId;
int checkSum;
char response;
void Validation(int idLentgh);

void AntonSolution();
int doubleDigitValue(int digit);

int main()
{
    //First of all we will get the ID number of the user, we then
    cout << "Enter your ID number: \n";
    cin >> idNumber;
    cout << "Your ID number is " + idNumber + "\n";
    //Get the total number of the idNumber and store it in "lentghOfId".
    lentghOfId = idNumber.length();
    //We call the "Validation" function when we have get the number and its length.
    Validation(lentghOfId);

    //Anton's Solution
    cout << "Do you want to see the solution of Anton? \n";
    cin >> response;
    if (response == 'y' | response == 'Y')
    {
        AntonSolution()
    }
}

//Validates the number, and checks to see if it is valid or not.
void Validation(int idLentgh)
{
    //The sum of all the idNumbers after being processed. It must always be 0 when this method is called.
    checkSum = 0;
    //Create an array with a size of lentghOfId, so that the idNumber can fit inside perfectly.
    string arrID[idLentgh] = {};

    //This loop populates the array with the idNumber,
    for (int i = 0; i < idLentgh; i++)
    {
        //Populate the array, with every single number in the idNumber getting a space.
        arrID[i] = idNumber[i];
        //Check and see if the number is at a location which is devisible by two with a reminder, because we are intrested
        //in second digits from the rightmost, thus we only want numbers which are located at odd indexes in the array.
        if (i % 2 != 0)
        {
            //When found it is multiplied by two and stored inside the array index where it was found.
            arrID[i] = std::to_string(stoi(arrID[i]) * 2);
            //Check and see if the number you just stored is two numbers by using index of strings. NB:'\0' == NULL
            if (arrID[i][1] != '\0')
            {
                //If it is two numbers acess the numbers seprately and add them toghether.
                int twoNums = stoi(string(1, arrID[i][0])) + stoi(string(1, arrID[i][1]));
                //Store them inside where it was picked from.
                arrID[i] = std::to_string(twoNums);
            }
        }

        //Sum up the values and store it inside "checkSum".
        checkSum = stoi(arrID[i]) + checkSum;
    }

    //Check to see if the number is valid or not.
    if (checkSum % 10 == 0)
    {
        cout << "This is a valid card." << endl;
    }
    else
        cout << "This is not a valid card." << endl;
}

//Anton's Solution to the problem.
void AntonSolution()
{
    char digit;
    int oddLengthChecksum = 0;
    int evenLengthChecksum = 0;
    int position = 1;
    cout << "Enter a number: ";
    digit = cin.get();
    while (digit != 10)
    {
        if (position % 2 == 0)
        {
            oddLengthChecksum += doubleDigitValue(digit - '0');
            evenLengthChecksum += digit - '0';
        }
        else
        {
            oddLengthChecksum += digit - '0';
            evenLengthChecksum += doubleDigitValue(digit - '0');
        }
        digit = cin.get();
        position++;
    }
    int checksum;
    if ((position - 1) % 2 == 0)
        checksum = evenLengthChecksum;
    else
        checksum = oddLengthChecksum;
    cout << "Checksum is " << checksum << ". \n";
    if (checksum % 10 == 0)
    {
        cout << "Checksum is divisible by 10. Valid. \n";
    }
    else
    {
        cout << "Checksum is not divisible by 10. Invalid. \n";
    }
}

int doubleDigitValue(int digit)
{
    int doubledDigit = digit * 2;
    int sum;
    if (doubledDigit > 10)
        sum = 1 + doubledDigit % 10;
    else
        sum = doubledDigit;
    return sum;
}