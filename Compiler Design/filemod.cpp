#include<bits/stdc++.h>
using namespace std;

int main()
{
    string path = "E:\\8th semester\\Compiler design lab\\filetest.txt";
    string content;
    string newcont;

    ifstream inputfile(path);
    string str;
    if(inputfile.is_open()){
        while (getline(inputfile,str)){
            content = content+str+"\n";
        }
        inputfile.close();
    }
    else{
        cout<<"error"<<endl;
    }
    cout<<content<<endl;
    return 0;
}
