#include <bits/stdc++.h>
using namespace std;
int main(){
    stack<string>stk;
    vector<string>var;
    string s;
    int x = 1;

    cin>>s;
    for (int i=0;i<s.length();i++){
        if (s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
            string temp2= stk.top();
            stk.pop();
            string temp1= stk.top();
            stk.pop();
            string str = "t"+to_string(x)+" = "+temp1+ string(1,s[i])+temp2;
            string str2 = "t"+to_string(x);
            stk.push(str2);
            x++;
            var.push_back(str);

        }
        else {
            stk.push(string(1,s[i]));
        }
    }
    for (int j=0; j<var.size(); j++){
        cout<<var[j]<<endl;
    }
    return 0;
}










