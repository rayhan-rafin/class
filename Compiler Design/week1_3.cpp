#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str1;
    string str2;
    getline (cin,str1);
    for (int i=0, j=0 ; i<str1.length(); i++){
        if (str1[i]!=' '){
                str2=str2+str1[i];
        }
    }
    cout<<str2<<endl;
    return 0;
}
