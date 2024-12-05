#include<bits/stdc++.h>
using namespace std;


int main ()
{
    int choice;
    string name;
    string type;
    string scope;
    vector<string>Name;
    vector<string>Type;
    vector<string>Scope;

    cout<<"Symbol Table Menu: "<<endl;
    cout<<"1. Insert symbol"<<endl;
    cout<<"2. Display Symbol Table"<<endl;
    cout<<"3. Exit"<<endl;

    while (1){
        cout<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        if (choice==1){
            cout<<"Enter identifier name: ";
            cin>>name;
            Name.push_back(name);

            cout<<"Enter Data Type: ";
            cin>>type;
            Type.push_back(type);

            cout<<"Enter scope: ";
            cin>>scope;
            Scope.push_back(scope);
            cout<<"symbol added successfully"<<endl;
        }
        else if (choice==2){
            cout<<"Index Name Type Scope";
                for(int j=0; j<Name.size(); j++){
                    cout<<endl;
                    cout<<"  "<<(j+1)<<" ";
                    cout<<"   "<<Name[j]<<" ";
                    cout<<"  "<<Type[j]<<" ";
                    cout<<"  "<<Scope[j]<<" ";
                }
        }
        else{
            break;
        }
    }
    return 0;
}
