#include<bits/stdc++.h>
using namespace std;

int main ()
{
    string s;
    int count=0;
    getline(cin,s);
    for (int i=0; i<s.length(); i++){
        if (s[i]==' '){
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}
