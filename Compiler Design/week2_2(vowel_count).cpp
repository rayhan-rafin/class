#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    int digit =0;
    int vowel=0;
    int consonent =0;

    getline(cin,str);
    for (int i=0; i<str.length(); i++)
    {
        if (str[i]>='0' && str[i]<='9')
        {
            digit++;
            continue;
        }
        else if (str[i]>='A' && str[i]<='Z')
        {
            str[i]=str[i]+32;
        }
        if (str[i]=='a' ||str[i]=='e' ||str[i]=='i' ||str[i]=='o' ||str[i]=='u'){
            vowel++;
            continue;
        }
        else if (str[i] != ' ') {
            consonent++;
        }
    }
    cout<<"vowel: " <<vowel<<endl;
    cout<<"consonent: " <<consonent<<endl;
    cout<<"digit: " <<digit<<endl;
}
