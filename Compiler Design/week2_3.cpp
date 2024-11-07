#include<bits/stdc++.h>
using namespace std;

int main()
{
    char str[] = "my name is Rayhan";
    char *token = strtok (str, " ");

    while (token){
        cout<<token<<endl;
        token = strtok(NULL," ");
    }
    return 0;
}
