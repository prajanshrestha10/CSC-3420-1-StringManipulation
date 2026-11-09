#include "StringManipulation.h"

void displayMenu() {
    cout << endl << "=====================================" << endl;
    cout << "  CharCraft - C-String Workshop Menu " << endl;
    cout << "=====================================" << endl;
    cout << "1) Compare two strings" << endl;
    cout << "2) Compare up to N characters" << endl;
    cout << "3) Copy a string" << endl;
    cout << "4) Append a string" << endl;
    cout << "5) Find the length of a string" << endl;
    cout << "6) Tokenize and reverse word order" << endl;
    cout << "0) Exit" << endl;
    cout << "=====================================" << endl;
    cout << "Enter your choice: ";
}

char* getDynamicStringInput(const string& prompt) {
    cout << prompt;
    string input;
    getline(cin, input);

    char* dynamicCStr = new char[input.length() + 1];
    strcpy(dynamicCStr, input.c_str());
    return dynamicCStr;
}

int main() {
    StringManipulation sm;
    int choice = -1;

    while (choice != 0) {
        displayMenu();
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear newline

        switch (choice) {
            case 1: {
                char* str1 = getDynamicStringInput("Enter first string: ");
                char* str2 = getDynamicStringInput("Enter second string: ");

                int res = sm.compareStrings(str1, str2);
                if (res == 0)
                    cout << "Result: Strings are equal." << endl;
                else if (res < 0)
                    cout << "Result: First string is lexicographically smaller." << endl;
                else
                    cout << "Result: First string is lexicographically larger." << endl;

                delete[] str1;
                delete[] str2;
                break;
            }
            case 2: {
                char* str1 = getDynamicStringInput("Enter first string: ");
                char* str2 = getDynamicStringInput("Enter second string: ");
                size_t n;
                cout << "Enter number of characters to compare (N): ";
                cin >> n;

                int res = sm.compareNStrings(str1, str2, n);
                if (res == 0)
                    cout << "Result: First " << n << " characters are equal." << endl;
                else if (res < 0)
                    cout << "Result: First string is smaller in first " << n << " characters." << endl;
                else
                    cout << "Result: First string is larger in first " << n << " characters." << endl;

                delete[] str1;
                delete[] str2;
                break;
            }
            case 3: {
                char* src = getDynamicStringInput("Enter string to copy: ");
                char* copied = sm.copyString(src);

                cout << "Copied String: " << copied << endl;

                delete[] src;
                delete[] copied;
                break;
            }
            case 4: {
                char* str1 = getDynamicStringInput("Enter base string: ");
                char* str2 = getDynamicStringInput("Enter string to append: ");
                char* appended = sm.appendString(str1, str2);

                cout << "Appended Result: " << appended << endl;

                delete[] str1;
                delete[] str2;
                delete[] appended;
                break;
            }
            case 5: {
                char* str = getDynamicStringInput("Enter string: ");
                cout << "Length of string: " << sm.getLength(str) << endl;

                delete[] str;
                break;
            }
            case 6: {
                char* str = getDynamicStringInput("Enter string to tokenize and reverse: ");
                char* reversed = sm.reverseWords(str);

                cout << "Reversed Word Order: " << reversed << endl;

                delete[] str;
                delete[] reversed;
                break;
            }
            case 0:
                cout << "Exiting CharCraft Workshop. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please select an option from 0 to 6." << endl;
                break;
        }
    }

    return 0;
}