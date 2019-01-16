#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll>v;

int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        ll sum=0;
        ll n;
        cin>>n;
        for(ll j=0;j<n;j++)
        {
            ll a;
            cin>>a;
            if(a<0)
            {
                continue;
            }
            v.push_back(a);
        }
        for(ll j=0;j<v.size();j++)
        {
            sum=sum+v[j];
        }
        printf("Case %d: %lld\n",i,sum);
        v.clear();
    }
    return 0;
}
