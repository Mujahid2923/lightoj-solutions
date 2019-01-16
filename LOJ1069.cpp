#include<bits/stdc++.h>
using namespace std;


int main()
{
    int t,a,b,time;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        cin>>a>>b;

        time=(abs(b-a)+abs(a-0))*4+10+9;


        printf("Case %d: %d\n",i,time);

    }
    return 0;
}
