#include <iostream>
using namespace std;

int fromLine5 = 3;
void printHashVal();

// main() is where program execution begins.
int main()
{
    for (int row = 1; row <= 7; row++)
    {
        if (row <= 4)
        {
            for (int hashVal = 1; hashVal <= row; hashVal++)
            {
                printHashVal();
            }
        }
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
}

void printHashVal()
{
    cout << "#";
}