#include <iostream>
using namespace std;

int main() {
    string input;
    cout << "Enter the input: ";
    cin >> input;


    int length = 0;
    while (input[length] != '\0') {
        length++;
    }

    char arr[100];
    for (int i = 0; i < length; i++) {
        arr[i] = input[i];
    }

    bool isValid = true;

    char ch = arr[0];
    if (!((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || ch == '_')) {
        isValid = false;
    }


    for (int i = 1; i < length; i++) {
        char c = arr[i];
        if (!((c >= 'A' && c <= 'Z') ||
              (c >= 'a' && c <= 'z') ||
              (c >= '0' && c <= '9') ||
              c == '_')) {
            isValid = false;
            break;
        }
    }


    if (isValid) {
        cout << "This is a valid identifier." << endl;
    } else {
        cout << "This is not a valid identifier." << endl;
    }

    return 0;
}

