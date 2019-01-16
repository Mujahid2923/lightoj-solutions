#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int main()
{
    int t,n,x1,x2,y1,y2,z1,z2;
    cin>>t;
    for(int k=1; k<=t; k++)
    {
        int p1=INT_MIN,p2=INT_MAX,q1=INT_MIN,q2=INT_MAX,r1=INT_MIN,r2=INT_MAX;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>x1>>y1>>z1>>x2>>y2>>z2;
            p1=max(p1,x1);
            q1=max(q1,y1);
            r1=max(r1,z1);
            p2=min(p2,x2);
            q2=min(q2,y2);
            r2=min(r2,z2);
        }
        int u,v,w;
        //  cout<<p1<<p2<<" "<<q1<<q2<<" "<<r1<<r2;
        u=p2-p1;
        v=q2-q1;
        w=r2-r1;

        ll ans=u*v*w;
        if(ans<0)
        {
            ans=0;
        }
        printf("Case %d: %lld\n",k,ans);
    }
    return 0;
}
