#include <iostream>
#include <string>
using namespace std;

int main() {
    string line;
    int lineCount = 0;

    cout << "Enter multiple lines of text (type 'END' on a new line to stop input):" << endl;

    while (true) {
        getline(cin, line);
        if (line == "END") {
            break;
        }
        lineCount++;
    }

    cout << "Number of lines entered: " << lineCount << endl;

    return 0;
}
