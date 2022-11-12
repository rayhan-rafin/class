#include<bits/stdc++.h>
using namespace std;

int main ()
{
    //    1 7 2 3 4 5 9 7 8 6 10
    int i,hole,value,n;
    cin>>n;
    int arr[n];
    for (int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    for (i=1; i<n; i++)
    {
        value = arr[i];
        hole = i;
        while (hole>0 && arr[hole-1]>value)
        {
            arr[hole] =arr[hole-1];
            hole = hole-1;
        }
        arr[hole]=value;
    }
    for (int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
