#include<bits/stdc++.h>
using namespace std;

int main ()
{
    string str;
    int countB = 0;
    cin>>str;
    int n = str.length();
    //cout<<n<<endl;
    for (int i=0; i<n; i++)
    {
        if(str[i]=='b')
        {
            countB=countB+1;
            if (countB>1){
                cout<<"invalid"<<endl;
                break;
            }
        }
        else if (str[i]!='a'){
            cout<<"invalid"<<endl;
            break;
        }
        if (i==(n-1)){
            cout<<"valid"<<endl;
            break;
        }
    }
    return 0;
}

