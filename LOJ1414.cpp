#include<bits/stdc++.h>
using namespace std;

#define ll long long int

#define MAX 10
char s1[MAX];
char s3[MAX];


int main()
{
    map<string, ll>m;
    m["January"]=1;
    m["February"]=2;
    m["March"]=3;
    m["April"]=4;
    m["May"]=5;
    m["June"]=6;
    m["July"]=7;
    m["August"]=8;
    m["September"]=9;
    m["October"]=10;
    m["November"]=11;
    m["December"]=12;


    int t;
    char s2,s4;
    ll a,b,c,d;
    scanf("%d",&t);
    for(int i=1; i<=t; i++)
    {
        scanf("%s %lld %c %lld",&s1,&a,&s2,&b);
        scanf("%s %lld %c %lld",&s3,&c,&s4,&d);

        b--;

        if(m[s1]>2)
        {
            b++;
        }
        if((m[s3]==1)|| (m[s3]==2 && c<29))
        {
            d--;
        }

        ll cnt=(d/4-d/100+d/400)- (b/4-b/100+b/400);
        printf("Case %d: %lld\n",i,cnt);
    }
    return 0;
}


