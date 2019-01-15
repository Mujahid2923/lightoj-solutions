#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll binary(ll n,ll val)
{
    for(ll i=n+1; i<=1000000000; i++)
    {
        string s = std::bitset<64>(i).to_string();
        ll cnt=0;
        for(int j=0; j<s.size(); j++)
        {
            if(s.at(j)=='1')
                cnt++;
        }
        if(cnt==val)
            return i;
    }
}
int main()
{
    ll t,n;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        scanf("%lld",&n);
        string s = std::bitset<64>(n).to_string();
        ll cnt=0;
        for(int j=0; j<s.size(); j++)
        {
            if(s.at(j)=='1')
                cnt++;
        }
        ll res=binary(n,cnt);
        printf("Case %d: %lld\n",i,res);
    }
    return 0;
}
