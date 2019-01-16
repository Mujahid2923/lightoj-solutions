#include<bits/stdc++.h>
using namespace std;


int main()
{
    int t,n;
    int a=0,b=0;
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        cin>>n;
        if(n>10)
        {
            b=n-10;
        }
        a=n-b;
        cout<<a<<" ";
        cout<<b<<endl;
        a=0;
        b=0;
    }
    return 0;
}
