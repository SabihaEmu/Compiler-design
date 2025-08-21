#include <iostream>
#include<fstream>
using namespace std;
const char* keywords[] = {
    "int", "float", "double", "char", "bool", "if", "else", "for", "while",
     "return" ,"true", "false","include","namespace","using"
};
const int keywordCount = sizeof(keywords) / sizeof(keywords[0]);

bool stringEquals(const char* a, const char* b) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) return false;
        i++;
    }
    return a[i] == '\0' && b[i] == '\0';
}

bool isKeyword(const char* word) {
    for (int i = 0; i < keywordCount; i++) {
        if (stringEquals(keywords[i], word)) return true;
    }
    return false;
}

bool isLetter(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

bool isDigit(char ch) {
    return (ch >= '0' && ch <= '9');
}

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' ||
           ch == '%' || ch == '=' || ch == '<' || ch == '>';
}

bool isPunctuation(char ch) {
    return ch == ';' || ch == ',' || ch == '(' || ch == ')' ||
           ch == '{' || ch == '}' || ch == '[' || ch == ']';
}

bool isIdentifier(const char* word) {
    if (!(isLetter(word[0]) || word[0] == '_')) return false;
    int i = 1;
    while (word[i] != '\0') {
        if (!(isLetter(word[i]) || isDigit(word[i]) || word[i] == '_')) return false;
        i++;
    }
    return true;
}

void printTokenType(const char* token) {
    if (isKeyword(token)) {
        cout << "Keyword: " << token << endl;
    } else if (isIdentifier(token)) {
        cout << "Identifier: " << token << endl;
    } else {

        cout << "Unknown token: " << token << endl;
    }
}

int main() {
    ifstream fin("code.txt");
    if (!fin) {
        cout << "Cannot open file" << endl;
        return 1;
    }

    char ch;
    char token[100];
    int index = 0;

    while (fin.get(ch)) {
        if (isLetter(ch) || isDigit(ch) || ch == '_') {

            if (index < 99) {
                token[index++] = ch;
            }
        } else {

            if (index > 0) {
                token[index] = '\0';
                printTokenType(token);
                index = 0;
            }

            if (isOperator(ch)) {
                cout << "Operator: " << ch << endl;
            } else if (isPunctuation(ch)) {
                cout << "Punctuation: " << ch << endl;
            } else if (ch == ' ' || ch == '\n' || ch == '\t') {

            } else {

            }
        }
    }


    if (index > 0) {
        token[index] = '\0';
        printTokenType(token);
    }

    fin.close();
    return 0;
}
