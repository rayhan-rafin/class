#include <bits/stdc++.h>
using namespace std;

string removeComments(const string& str1) {
    string str2 = "";
    bool single = false;
    bool multi = false;

    for (int i = 0; i < str1.length(); i++) {
        if (multi) {
            if (str1[i] == '*' && str1[i + 1] == '/') {
                multi = false;
                i++;
            }
        }
        else if (single) {
            if (str1[i] == '\n') {
                single = false;
                str2 = str2 + str1[i];
            }
        }
        else {
            if (str1[i] == '/' && str1[i + 1] == '*') {
                multi = true;
                i++;
            } else if (str1[i] == '/' && str1[i + 1] == '/') {
                single = true;
                i++;
            } else {
                str2 = str2 + str1[i];
            }
        }
    }
    return str2;
}
//---------------------------------------------------------------------------------------------------
string cmdinput (){
    string str1 = "";
    string line = "";

    cout << "write 'end' on a new line to stop input" << endl;

    while (true) {
        getline(cin, line);
        if (line == "end") {
            break;
        }
        str1 = str1 + line + "\n";
    }

    return str1;
}

//-------------------------------------------------------------------------------------------------------
int main() {

    string inputs=cmdinput();
    string result = removeComments(inputs);

    cout << endl << result << endl;
    return 0;
}
