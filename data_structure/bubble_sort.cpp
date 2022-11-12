#include<bits/stdc++.h>
using namespace std;

int main ()
{
//    1 7 2 3 4 5 9 7 8 6 10
    int i,j,k,n,temp;
    cin>>n;
    int arr[n];
    for (int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    for (k=1; k<n; k++)
    {
        for(i=0; i<(n-1); i++)
        {
            if (arr[i]>arr[i+1])
            {
                temp = arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
    }
    for (int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}
