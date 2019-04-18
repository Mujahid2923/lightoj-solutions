///...................................*****.................................................///
///                  Mujahidul Islam ( mujahidulislam2923@gmail.com )                       ///
///                  Department of Ict                                                      ///
///                  Comilla University , Bangladesh.                                       ///
///...................................*****.................................................///

#include<bits/stdc++.h>
using namespace std;

#define           CIN              ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define           ll               long long int
#define           ull              unsigned long long int
#define           pii              pair < int, int>
#define           pll              pair < ll, ll>
#define           MOD              1000000007
#define           vi               vector<int>
#define           vl               vector<ll>
#define           pb               push_back
#define           sc               scanf
#define           pf               printf
#define         scin(x)            scanf("%d",&(x))
#define        scin2(x,y)          scanf("%d %d",&(x),&(y))
#define         scln(x)            scanf("%lld",&(x))
#define        scln2(x,y)          scanf("%lld %lld",&(x),&(y))
#define       min3(a,b,c)          min(a,min(b,c))
#define       min4(a,b,c,d)        min(d,min(a,min(b,c)))
#define       max3(a,b,c)          max(a,max(b,c))
#define       max4(a,b,c,d)        max(d,max(a,max(b,c)))
#define         ms(a,b)            memset(a,b,sizeof(a))
#define           mp               make_pair
#define       gcd(a, b)            __gcd(a,b)
#define       lcm(a, b)            ((a)*(b)/gcd(a,b))
#define         input              freopen("input.txt","rt", stdin)
#define         output             freopen("output.txt","wt", stdout)
#define           PI               3.141592653589793238462643
#define     rep( i , a , b )       for( i=a ; i<b ; i++)
#define     rev( i , a , b )       for( i=a ; i>=b ; i--)
#define     repx( i ,a,b, x)       for( i=a ; i<b ; i+=x)
#define       CASEL(t)             printf("Case %d:\n",t)
#define     RUN_CASE(t,T)          for(__typeof(t) t=1;t<=T;t++)
#define        zero(a)             memset(a,0,sizeof a)

///priority_queue<int,vector<int>,greater<int> >pq;
///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------


int main()
{
    int t,i,j,n,q,a,b;
    char ch;
    scin(t);
    rep(i,1,t+1)
    {
        scin2(n,q);
        vector<int>v(n);
        rep(j,0,n)
        {
            scin(v[j]);
        }
        while(q--)
        {
            cin>>ch;
            if(ch=='S')
            {
                cin>>a;
                rep(j,0,n)
                {
                    v[j]+=a;
                }
            }
            else if(ch=='M')
            {
                cin>>a;
                rep(j,0,n)
                {
                    v[j]*=a;
                }
            }
            else if(ch=='D')
            {
                cin>>a;
                rep(j,0,n)
                {
                    v[j]/=a;
                }
            }
            else if(ch=='D')
            {
                cin>>a;
                rep(j,0,n)
                {
                    v[j]/=a;
                }
            }
            else if(ch=='P')
            {
                cin>>a>>b;
                swap(v[a],v[b]);
            }
            else
            {
                reverse(v.begin(),v.end());
            }
        }
        pf("Case %d:\n",i);
        rep(j,0,n)
        {
            if(j==n-1)
            {
                pf("%d\n",v[j]);
            }
            else
            {
                pf("%d ",v[j]);
            }
        }
        v.clear();
    }
    return 0;
}

