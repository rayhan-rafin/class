#include<bits/stdc++.h>
using namespace std;

int main()
{

    string str;
    vector <string>tokens;
    string word;
    getline(cin,str);
    int n = str.length();
    for (int i=0; i<n; i++){
        word=word+str[i];
        if(str[i]==' '){
            tokens.push_back(word);
            word="";
        }
    }
    tokens.push_back(word);
    for (int i=0; i<tokens.size(); i++){
        cout<<tokens[i]<<endl;
    }

    return 0;
}
