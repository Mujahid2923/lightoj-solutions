#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
using namespace std;

int phi[5000005];
ull cum[5000005];

void euler()
{
    int n=5000005;
    for(int i=1; i<=n; i++)
    {
        phi[i]=i;

    }

    for(int i=2; i<=n; i++)
    {
        if(phi[i]==i)
        {
            for(int j=i; j<=n; j+=i)
            {
                phi[j]-=phi[j]/i;
            }
        }
    }
}

int main()
{
    euler();
    for(int i=2; i<=5000000; i++)
    {

        cum[i]=(ull)phi[i]*(ull)phi[i];
        cum[i]=cum[i-1]+cum[i];
    }

    int t;
    scanf("%d",&t);

    for(int i=1; i<=t; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        ull sum=cum[b]-cum[a-1];
        printf("Case %d: %llu\n",i,sum);
    }
    return 0;
}

