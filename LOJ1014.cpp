#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll>v;

void check(ll n,ll b)
{
    for(ll i=1; i*i<=n; i++)
    {
        if(n%i == 0)
        {

            if((n/i)==i && i>=b)
            {
                v.push_back(i);
            }
            else
            {
                if(i>=b)
                    v.push_back(i);
                if((n/i)>=b)
                    v.push_back(n/i);
            }

        }
    }
    sort(v.begin(),v.end());
}

int main()
{
    //freopen("in.txt","w",stdout);
    ll t,a,b;
    cin>>t;
    for(ll i=1; i<=t; i++)
    {
        bool ck=false;
        scanf("%lld %lld",&a,&b);
        check(a-b,b+1);
        printf("Case %lld: ",i);
        if(v.empty())
        {
            cout<<"impossible"<<endl;
        }
        else
        {
            for(ll j=0; j<v.size(); j++)
            {
                if(ck)
                {
                    cout<<" ";
                }
                cout<<v[j];
                ck=true;
            }
            cout<<endl;
        }
        v.clear();
    }
}
