#include <iostream>
using namespace std;

// main() is where program execution begins.
//This is a tester program.
int main()
{
    char digitChar;
    do
    {
        digitChar = cin.get();
        int number = (digitChar - '0');
        digitChar = cin.get();
        while ((digitChar != 10) && (digitChar != ','))
        {
            number = number * 10 + (digitChar - '0');
            digitChar = cin.get();
        }
        cout << "Numbered entered: " << number << "\n";
    } while (digitChar != 10);
}
