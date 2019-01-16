#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        double a;
        cin>>a;
        double ans=((a*2)*(a*2))-((2 * acos (0.0))*a*a);
        printf("Case %d: %.2lf\n",i,ans);
    }

    return 0;
}

