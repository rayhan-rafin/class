#include <bits/stdc++.h>
using namespace std;

int main ()
{
    string str1="";
    string line="";
    string str2 ="";
    bool single=0;
    bool multi=0;
    while(1)
    {
        getline(cin, line);
        if (line=="end"){
            break;
        }
        str1=str1+line+"\n";
    }
    //cout<<str1<<endl;
    for (int i=0; i<(str1.length()-1); i++){
        if (str1[i]=='/' && str1[i+1]=='*' && single==0){
            multi=1;
            i++;
        }
        else if (str1[i]=='/' && str1[i+1]=='/' && multi==0){
            single=1;
            i++;
        }
        if(single==0 && multi==0){
            str2=str2+str1[i];
        }
        if (str1[i]=='\n' && single==1){
            single=0;
        }
        else if (str1[i]=='*' && str1[i+1]=='/' && multi==1){
            multi=0;
        }
    }
    cout<<str2<<endl;
return 0;
}

