#include <iostream>
using namespace std;

/* PROBLEM: A SIDEWAYS TRIANGLE
Write a program that uses only two output statements, cout << "#" and cout << "\n", to produce
a pattern of hash symbols shaped like a sideways triangle:
#
##
###
####
###
##
#
*/

void AntonSolution();
char response;

int fromLine5 = 3;
void printHashVal();

// main() is where program execution begins.
int main()
{
    //This for loop creates 7 lines of free space which can be filled with letters with the help of (cout << "\n")
    for (int line = 1; line <= 7; line++)
    {
        //We first check and see if the line we are currently on is less than 4, if it is less than four we print
        //"#" according to the line number, so if we start from line 1, we will print only 1 "#" on that line,
        //on line 2 we will print 2 "#",etc.
        //NB: the "cout << "\n";" is outside the for loop inside this if statement, so the loop will execute and finish
        //before going to the next line.
        if (line <= 4)
        {
            for (int hashVal = 1; hashVal <= line; hashVal++)
            {
                printHashVal();
            }
        }
        //In this else statement, when the value of the line is greater than 4 and the current line we are on is 5,
        //we use "fromLine5" (which serves as the number of times we need to print "#") to print out "#",
        //and outside the loop but in the same else statement we decrease the number by 1, thus forming a decresing print of "#".
        else
        {
            for (int hashVal2 = 1; hashVal2 <= fromLine5; hashVal2++)
            {
                printHashVal();
            }
            fromLine5 -= 1;
        }
        cout << "\n";
    }
    
    //Here is the solution of Anton.
    cout << "Would you like to see the solution of Anton? \n";
    cout << "Y for yes, and N for no \n";
    cin >> response;
    if (response == 'Y' | response == 'y')
    {
        AntonSolution();
    }
}

//This function is needed, because from the problem it states that "use only two output statements".
void printHashVal()
{
    cout << "#";
}

//This is the solution of Anton.
void AntonSolution()
{
    for (int row = 1; row <= 7; row++)
    {
        for (int hashNum = 1; hashNum <= 4 - abs(4 - row); hashNum++)
        {
            cout << "#";
        }
        cout << "\n";
    }
}