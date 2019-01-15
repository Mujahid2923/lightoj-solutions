#include<bits/stdc++.h>
using namespace std;
int arr[102];

vector<int>v,g,f;

void findPrime()
{
    int n=1000;
    bool prime[n+1];
    memset(prime,false,sizeof prime);

    for(int i=4; i<=n; i+=2)
    {
        prime[i]=true;
    }

    prime[1]=true;

    for(int i=3; i*i<=n; i+=2)
    {
        if(prime[i]==false)
        {
            for(int j=2; i*j<=n; j++)
            {
                prime[i*j]=true;
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        if(prime[i]==false)
        {
            v.push_back(i);
        }
    }
}

void fact()
{
    for(int i=1; i<=100; i++)
    {
        g.push_back(i);
    }
}

int main()
{
    findPrime();
    fact();
    int t,n;
    cin>>t;
    for(int k=1; k<=t; k++)
    {
        f=g;
        bool ck=false;
        memset(arr,0,sizeof arr);
        cin>>n;
        for(int j=1; j<n; j++)
        {
            for(int i=0; v[i]<=f[j]; i++)
            {
                //cout<<f[j]<<" "<<v[i]<<endl;
                while(f[j]%v[i]==0)
                {
                    arr[v[i]]++;
                    f[j]=f[j]/v[i];
                }
            }
        }
        printf("Case %d: %d = ",k,n);
        for(int i=1; i<=n; i++)
        {
            if(arr[i]!=0)
            {
                if(ck)
                {
                    printf(" * ");
                }
                printf("%d (%d)",i,arr[i]);
                ck=true;
            }
        }
        cout<<endl;
        f.clear();
    }
}
