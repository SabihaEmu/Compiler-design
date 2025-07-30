#include <iostream>
using namespace std;

int main() {
    string input;
    cout << "Enter a line: ";
    getline(cin, input);
    int length = 0;
    while (input[length] != '\0') {
        length++;
    }

    char arr[1000];
    for (int i = 0; i < length; i++) {
        arr[i] = input[i];
    }


    if (arr[0] == '/' && arr[1] == '/') {
        cout << "This is a single-line comment." << endl;
    }

    else if (arr[0] == '/' && arr[1] == '*') {
        bool foundEnd = false;
        for (int i = 2; i < length - 1; i++) {
            if (arr[i] == '*' && arr[i + 1] == '/') {
                foundEnd = true;
                break;
            }
        }
        if (foundEnd) {
            cout << "This is a multi-line comment." << endl;
        } else {
            cout << "This is not a complete comment " << endl;
        }
    }
    else {
        cout << "This is not a comment." << endl;
    }

    return 0;
}

