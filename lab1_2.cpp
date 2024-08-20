#include <iostream>
#include <string>
using namespace std;

int main() {
    while (1) {
        string testString;
        cout << "Enter a string: ";
        cin >> testString;

        string testChar;
        cout << "Enter character to replace or 'stop': ";
        cin >> testChar;
        if (testChar.length() == 1 || testChar == "stop") {
            if (testChar == "stop") {
                break;
            }

            for (char &index : testString) {
                if (index == testChar[0]) {
                    index = '_';
                }
            }
            cout << testString << "\n";
        } else {
            cout << "Invalid input. Please input a single letter or the word 'stop'.\n";
        }
    }

    return 0;
}